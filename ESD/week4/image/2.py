import cv2
import numpy as np
from matplotlib import pyplot as plt

#주어진 영상 (img2.jpg)를 이용해 다음과 같은 두 영상을 생성하는 프로그램을 작성하고 히스토그램 일치 여부를 확인 및 결과 분석
img1 = cv2.imread("./img2.jpg",cv2.IMREAD_GRAYSCALE)
h, w, = img1.shape
st = 0
ed = 255
#0~255까지의 값을 가지는 img_2,img_3
img_2 = np.zeros_like(img1, dtype=np.uint8)
img_3 = np.zeros_like(img1, dtype=np.uint8)
#h의 크기를 가지고 st ~ ed 의 정수 값을 가지는 gradient 배열
gradient = np.linspace(st, ed, h, dtype=np.uint8)
for x in range(h):
    #아래로 어두운 배열
    img_2[x, :] = gradient[x]
    #위로 어두운 배열
    img_3[x, :] = ed - gradient[x]
#빼는 연산 실행
image = cv2.subtract(img1, img_2)
image_2 = cv2.subtract(img1, img_3)
# image와 imag2의 원소의 히스토그램을 만듦
hist1 = cv2.calcHist([image], [0], None, [256], [0, 256])
hist2 = cv2.calcHist([image_2], [0], None, [256], [0, 256])
# 정규화
hist1 = hist1.ravel() / hist1.max()
hist2 = hist2.ravel() / hist2.max()
# 256 크기의 배열 생성
x= np.arange(256)
#출력
plt.subplot(221), plt.imshow(image, 'gray'), plt.title("image")
plt.subplot(222), plt.bar(x, hist1, width=1,  color='r'), plt.xlim([-1, 256])
plt.subplot(223), plt.imshow(image_2, 'gray'), plt.title("image_2")
plt.subplot(224), plt.bar(x, hist2, width=1,  color='b'), plt.xlim([-1, 256])
plt.show()