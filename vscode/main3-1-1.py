import cv2
import numpy as np
from urllib.request import urlopen

ip = '192.168.137.155'
stream = urlopen('http://' + ip + ':81/stream')
buffer = b''

while True:
    buffer += stream.read(4096)
    print(buffer)
    
#main 3-1-1.py
#자율주행 자동차 영상 스트리밍 데이터 확인