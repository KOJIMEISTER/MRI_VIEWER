#ifndef INTERP_H
#define INTERP_H
#include <QFile>
#include <QDebug>
#include "packContain.h"
#include "imagePack.h"
#include "predresult.h"
#include <boost/python.hpp>
#include <boost/thread.hpp>
using namespace boost::python;

class PINFIN
{
private:

    struct acuirePyGIL
    {
        PyGILState_STATE gil;
        acuirePyGIL()
        {
            gil = PyGILState_Ensure();
        }
        ~acuirePyGIL()
        {
            PyEval_SaveThread();
        }
    };

public:

    static QString formatError( handle<> const&, handle<> const&, handle<> const& );
    static void initCl();
    static void initSeg();
    static acuirePyGIL getLock();
    static PredResult doClassification(const ImagePack& pack);
    static ImagePack doSegmentation(const ImagePack& pack);
    static bool isClInited();
    static bool isSegInited();

private:
    PyThreadState *tstate = nullptr;
    bool clInited;
    bool segInited;
    object moduleMain;
    object moduleDict;
    object moduleTraceback;
    object moduleFormatError;
    PINFIN();
    ~PINFIN();
    static PINFIN& instance();
    object& modMainInst();
    object& modDictInst();
    object& modTracebackInst();
    QString formatError( object const&, object const&, object const& );

};

void exceptionsRethrow();

#endif // INTERP_H
