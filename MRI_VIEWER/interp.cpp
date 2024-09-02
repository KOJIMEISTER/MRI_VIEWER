#include "interp.h"

void PINFIN::initCl()
{
    try {
        auto lock = getLock();
        QFile file("classification.py");
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "\nOpen file error";
            return;
        }
        QByteArray script = file.readAll();
        object ignore = exec(script.constData(), instance().modDictInst(), instance().modDictInst());
        instance().clInited = true;
        file.close();
    } catch (error_already_set) {
        PyErr_Print();
        exceptionsRethrow();
    }

}

void PINFIN::initSeg()
{
    try {
        auto lock = getLock();
        QFile file("segmentation.py");
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "\nOpen file error";
            return;
        }
        QByteArray script = file.readAll();
        object ignore = exec(script.constData(), instance().modDictInst(), instance().modDictInst());
        instance().segInited = true;
        file.close();
    } catch (error_already_set) {
        PyErr_Print();
        exceptionsRethrow();
    }

}

PredResult PINFIN::doClassification(const ImagePack& pack)
{
    if (!instance().clInited)
        initCl();
    if(!instance().clInited)
        return PredResult();
    try {
        auto lock = getLock();
        object res =  instance().modDictInst()["doClassification"](pack);
        return extract<PredResult>(res);
    } catch (error_already_set) {
        PyErr_Print();
        exceptionsRethrow();
    }
    return PredResult();
}

ImagePack PINFIN::doSegmentation(const ImagePack& pack)
{
    if (!instance().segInited)
        initSeg();
    if(!instance().segInited)
        return ImagePack();
    try {
        auto lock = getLock();
        object res = instance().modDictInst()["doSegmentation"](pack);
        return extract<ImagePack>(res);
    } catch (error_already_set) {
        PyErr_Print();
        exceptionsRethrow();
    }
    return ImagePack();
}

PINFIN::acuirePyGIL PINFIN::getLock()
{
    instance();
    return PINFIN::acuirePyGIL();
}

PINFIN::PINFIN()
{
    Py_Initialize();
    PyEval_InitThreads();
    tstate = PyEval_SaveThread();
}

PINFIN::~PINFIN()
{
    moduleMain = object();
    moduleFormatError = object();
    moduleTraceback = object();
    moduleDict = object();
    PyEval_RestoreThread(tstate);
}

QString PINFIN::formatError( handle<> const& exc, handle<> const& msg, handle<> const& tb )
{
    return instance().formatError( object(exc), object(msg), object(tb) );
}

PINFIN& PINFIN::instance()
{
    static PINFIN single;
    return single;
}

object& PINFIN::modMainInst()
{
    try {
        if( moduleMain.is_none() )
            moduleMain = import( "__main__" );
    } catch (error_already_set const&) {
        PyErr_Print();
        exceptionsRethrow();
    }
    return moduleMain;
}

object& PINFIN::modDictInst()
{
    try {
        if(moduleDict.is_none())
            moduleDict = modMainInst().attr("__dict__");
    } catch (error_already_set const&) {
        PyErr_Print();
        exceptionsRethrow();
    }
    return moduleDict;
}

object& PINFIN::modTracebackInst()
{
    try {
        if( moduleTraceback.is_none() )
            moduleTraceback = import( "traceback" );
    } catch (error_already_set const&) {
        PyErr_Print();
        exceptionsRethrow();
    }

    return moduleTraceback;
}

QString PINFIN::formatError( object const& exc, object const& val, object const& tb )
{
    try {
        if( moduleFormatError.is_none() )
            moduleFormatError = modTracebackInst().attr( "format_exception" );
    } catch (error_already_set const&) {
        PyErr_Print();
        exceptionsRethrow();
    }
    return extract<QString>( str( "" ).join( formatError( exc, val, tb ) ) );
}

void exceptionsRethrow()
{
    PyObject *exc, *val, *tb;
    PyErr_Fetch( &exc, &val, &tb );
    PyErr_NormalizeException( &exc, &val, &tb );
    handle<> hexc(exc), hval( allow_null( val ) ), htb( allow_null( tb ) );
    QString message, details;
    message = extract<QString>( !hval ? str( hexc ) : str( hval ) );
    details = !tb ? extract<QString>( str( hexc ) ) : PINFIN::formatError( hexc, hval, htb );
    qDebug() << "\nError : " << message << "\n Details : " << details;
}

bool PINFIN::isClInited()
{
    return instance().clInited;
}

bool PINFIN::isSegInited()
{
    return instance().segInited;
}
