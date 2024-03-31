import cv2
import numpy as np
from matplotlib import pyplot as plt
#주어진 영상 (img1.jpg)에 빨강, 파랑, 초록색의 점을 각각 설정한 개수만큼 무작위로 생성하는 프로그램 작성
#3채널 이미지 
img1 = cv2.imread("./img1.jpg", cv2.IMREAD_COLOR)
#각각의 채널에서 R, G, B의 분포를 세어줌
img1R = cv2.calcHist([img1], [0], None, [256], [0, 256])
img1G = cv2.calcHist([img1], [1], None, [256], [0, 256])
img1B = cv2.calcHist([img1], [2], None, [256], [0, 256])
#각각의 채널에서 255일 때를 세어줌
img1R = img1R[255][0]
img1G = img1G[255][0]
img1B = img1B[255][0]
#겹치는 점의 개수를 세어줄 배열
samedata = [0] * 3
h, w, _  = img1.shape
#img1과 동일 형태의 array 선언
img2 = np.zeros_like(img1)
size = h * w
#random하게 R, G, B의 개수를 지정
num =[np.random.randint(0, size) for _ in range(3)]
#random하게 위치를 지정 후 img2를 생성함
colorNum = [np.random.choice(size, num[i], replace= False) for i in range(3)]
for i in range(0, 3) :
    for pos in colorNum[i]:
        x = pos // w
        y = pos %  w 
        img2[x][y][i] = 255
        if img1[x][y][i] == 255 :
            samedata[i] +=1

#img 합성 후 합성된 이미지의 R, G, B를 셈
image = cv2.add(img1, img2)
imgR = cv2.calcHist([image], [0], None, [256], [0, 256])
imgG = cv2.calcHist([image], [1], None, [256], [0, 256])
imgB = cv2.calcHist([image], [2], None, [256], [0, 256])
imgR = imgR[255][0]
imgG = imgG[255][0]
imgB = imgB[255][0]

data = [
        [img1R, img1G, img1B],
        num,
        [imgR,  imgG ,  imgB],
        samedata
]
#결과 출력
print(data)
cv2.imshow('dst2', img2)
cv2.imshow('dst', img1)
cv2.imshow('result', image)
cv2.waitKey(0)
cv2.destroyAllWindows()