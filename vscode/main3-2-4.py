import cv2
import numpy as np
from urllib.request import urlopen
import os
import uuid

os.chdir(os.path.dirname(os.path.abspath(__file__)))

ip = '192.168.137.125'
stream = urlopen('http://' + ip + ':81/stream')
buffer = b''
urlopen('http://'+ip+"/action?go=speed40")

if os.path.isdir('01_go') is False:
    os.mkdir("01_go")
    
if os.path.isdir('02_left') is False:
    os.mkdir("02_left")
    
if os.path.isdir('03_right') is False:
    os.mkdir("03_right") 

car_state = 'stop'
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
            
            file_name = uuid.uuid1().hex+'.png'
            
            if car_state == 'forward':
                print("직전 이미지 저장")
                cv2.imwrite(f'01_go/go_'+file_name,img)
            elif car_state == 'left':
                print("왼쪽 이미지 저장")
                cv2.imwrite(f'02_left/left_'+file_name,img)
            elif car_state == 'right':
                print("오른쪽 이미지 저장")
                cv2.imwrite(f'03_right/right_'+file_name,img)
                    
            if key == ord('q'):break
                # urlopen('http://' + ip + "/action?go=stop")
                
            # elif key == ord('w'):
            #     print('전진')
            #     urlopen('http://' + ip + "/action?go=forward")
            # elif key == ord('a'):
            #     print('왼쪽')
            #     urlopen('http://' + ip + "/action?go=left")
            # elif key == ord('d'):
            #     print('오른쪽')
            #     urlopen('http://' + ip + "/action?go=right")
            # elif key == ord('s'):
            #     print('후진')
            #     urlopen('http://' + ip + "/action?go=backward")
            # elif key == ord('A'):
            #     print('왼쪽 회전')
            #     urlopen('http://' + ip + "/action?go=turn_left")
            # elif key == ord('D'):
            #     print('오른쪽 회전')
            #     urlopen('http://' + ip + "/action?go=turn_right")
            # elif key == 32:
            #     print('멈춤')
            #     urlopen('http://' + ip + "/action?go=stop")
            # elif key == ord('1'):
            #     print('40%속도')
            #     urlopen('http://' + ip + "/action?go=speed40")
            # elif key == ord('2'):
            #     print('50%속도')
            #     urlopen('http://' + ip + "/action?go=speed50")
            # elif key == ord('3'):
            #     print('60%속도')
            #     urlopen('http://' + ip + "/action?go=speed60")
            # elif key == ord('4'):
            #     print('80%속도')
            #     urlopen('http://' + ip + "/action?go=speed80")
            # elif key == ord('5'):
            #     print('100%속도')
            #     urlopen('http://' + ip + "/action?go=speed100")
            

            
    except:
        print("에러")
        pass
urlopen('http://' + ip + "/action?go=stop")
cv2.destroyAllWindows()

#자동차 조종하기