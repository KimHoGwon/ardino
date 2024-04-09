import cv2
import numpy as np
from urllib.request import urlopen
import os
import uuid
os.chdir(os.path.dirname(os.path.abspath(__file__)))

ip = '192.168.137.123'
stream = urlopen('http://' + ip +':81/stream')
buffer = b''


if os.path.isdir('images') is False:
    os.mkdir("images")

image_uuid = uuid.uuid1().hex
while True:
    buffer += stream.read(4096)
    head = buffer.find(b'\xff\xd8')
    end = buffer.find(b'\xff\xd9')
    
    try: 
        if head > -1 and end > -1:
            jpg = buffer[head:end+2]
            buffer = buffer[end+2:]
            img = cv2.imdecode(np.frombuffer(jpg, dtype=np.uint8), cv2.IMREAD_UNCHANGED)

            cv2.imshow("AI CAR Streaming", img)
            
            key = cv2.waitKey(1)
            if key == ord('q'):
                break
            elif key == ord('s'):
                print("이미지 저장:",image_uuid)
                cv2.imwrite(f'images/image_{image_uuid}.png',img)
                image_uuid = uuid.uuid1().hex

    except:
        print("에러")
        pass

urlopen('http://' + ip + "/action?go=stop")
cv2.destroyAllWindows()

# main6-2-1.py
# 버튼을 눌러 이미지 저장하기