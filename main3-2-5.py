import cv2
import numpy as np
from urllib.request import urlopen
from keras.models import load_model
import os
import uuid
import tensorflow
import keras
import numpy as np

ip = '192.168.137.169'
stream = urlopen('http://' + ip + ':81/stream')
buffer = b''

model = load_model(r"D:\\workspaces\\arduino\\keras_model.h5", compile=False)
class_names = open(r"D:\\workspaces\\arduino\\labels.txt","r").readlines()


while True:
    buffer += stream.read(4096)
    head=buffer.find(b'\xff\xd8')
    end=buffer.find(b'\xff\xd9')
    
    try:
        if head > -1 and end > -1:
            jpg = buffer[head:end+2]
            buffer = buffer[end+2:]
            img = cv2.imdecode(np.frombuffer(jpg, dtype=np.uint8), cv2.IMREAD_UNCHANGED)
           
            height, width, _ = img.shape
            img = img[height //2:, :]
            
            img = cv2.resize(img,(224,224),interpolation=cv2.INTER_AREA)
            
            cv2.imshow("AI CAR Streaming", img)
           
            key = cv2.waitKey(1)
            input ={
                ord('q'):'stop',
                ord('w'):'forward',
                ord('a'):'left',
                ord('d'):'right',
                ord('s'):'backward',
                ord('A'):'turn_left',
                ord('D'):'turn_right',
                32:'stop',
                ord('1'):'speed40',
                ord('2'):'speed50',
                ord('3'):'speed60',
                ord('4'):'speed80',
                ord('5'):'speed100',
            }
            
            if key in input:
                urlopen('http://' + ip + "/action?go="+input[key])
                car_state = input[key]
                print(input[key])
        
            if key==32:
                img = np.asarray(img, dtype=np.float32).reshape(1,224,224,3)
               
                img=(img/127.5)-1
               
                prediction=model.predict(img)
                index=np.argmax(prediction)
                class_name=class_names[index]
                confidence_score=prediction[0][index]
                
                print("Class:",class_name[2:],end="")
                print("Confidence Score:",str(np.round(confidence_score*100))[:-2],"%")
                

            if key == ord('q'):break

            
    except:
        print("에러")
        pass
urlopen('http://' + ip + "/action?go=stop")
cv2.destroyAllWindows()

#자동차 조종하기