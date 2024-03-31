#주어진 영상 (img3.jpg, img4.jpg, img5.jpg) 를 이용해 다음의 영상을 완성할 것
import cv2
import numpy as np
from matplotlib import pyplot as plt

img1 = cv2.imread("./img3.jpg", cv2.IMREAD_COLOR)
img2 = cv2.imread("./img4.jpg", cv2.IMREAD_COLOR)
logo = cv2.imread("./img5.jpg", cv2.IMREAD_COLOR)

h, w, _ = img1.shape
#img2의 스칼라 연산을 위한 사이즈 조정
img2 = cv2.resize(img2, dsize=(w, h))
add_image = cv2.subtract(img1, img2)
rows, cols, _ = logo.shape
#logo 위치는 img1의 h//2, w//4로 조정
roi = np.zeros_like(logo)
for x in range(rows) :
    for y in range(cols) :
        roi[x, y, :] = add_image[x + h//2, y + w//4, :]
# 이미지 마스킹
logo2gray = cv2.cvtColor(logo, cv2.COLOR_BGR2GRAY)
ret, mask = cv2.threshold(logo2gray, 200, 255, cv2.THRESH_BINARY)
mask_inv = cv2.bitwise_not(mask)
img_bg = cv2.bitwise_and(roi, roi, mask=mask)
logo_fg = cv2.bitwise_and(logo, logo, mask=mask_inv)
#마스킹한 이미지를 기존 이미지에 합성
dst = cv2.add(img_bg, logo_fg)
for x in range(rows) :
    for y in range(cols) :
        add_image[x + h//2, y + w//4, :] = dst[x, y, :]
cv2.imshow('image', add_image)
cv2.waitKey(0)
cv2.destroyAllWindows()