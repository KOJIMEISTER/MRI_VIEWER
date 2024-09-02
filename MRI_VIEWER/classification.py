import tensorflow.keras as keras
from keras.models import Model, load_model
from tensorflow.keras.preprocessing import image
import numpy as np
import imgwrap as iw
modelClass = keras.models.load_model('classification.h5')
def doClassification(pack):
    resPred = iw.PredResult()
    dirPath = pack.packCont.getDirPath()
    names = pack.packCont.getPyImgNames()
    for idx in range(len(names)):
        img = image.load_img(dirPath + names[idx], target_size=(224,224))
        arr = image.img_to_array(img)
        arr = np.expand_dims(arr, axis=0)
        images = np.vstack([arr])
        pred = modelClass.predict(images, verbose=0)
        if(pred[0][14] < 0.5):
            idx = []
            probs = []
            sArr = np.argsort(-pred)[0]
            sArrIdx = np.where(np.abs(pred[0][sArr[0]] - pred[0][sArr]) < .20)
            idx = sArr[sArrIdx]
            probs = pred[0][idx]
            resPred.addProbs(idx.tolist(),probs.tolist())
    return resPred