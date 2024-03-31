import cv2
import numpy as np
from matplotlib import pyplot as plt
# kernel의 연산 범위 지정
def MyKernelConv(arr, kernel, y, x, height, width, L):
    sum, sumKernel =0, 0
    for i in range(-1, L-1):
        for j in range(-1, L-1):
            if((y+ i) >= 0 and (y +i) < height and (x + j) >= 0 and (x + j) < width):
                sum += arr[y+i, x+j] * kernel[i+1, j+1]
                sumKernel += kernel[i+1, j+1]
    if sumKernel != 0:
        return sum / sumKernel
    else:
        return sum                  
#생성한 가우시안 필터    
def mygaussianFilter(width, sigma):
    array = np.arange((width//2)* (-1), width//2 +1)
    arr = np.zeros((width, width))

    for x in range(width):
        for y in range(width):
            arr[x, y] = array[x]**2 + array[y]**2
    kernel = np.zeros((width, width))

    for x in range(width):
        for y in range(width):
            kernel[x, y] = np.exp(-arr[x, y] / (2 * sigma**2))
    # 정규화                                  
    kernel = kernel / kernel.sum()

    return  kernel
# 라이브러리 제공 함수를 이용한 가우시안 필터
gMat = cv2.getGaussianKernel(9, 1)
TgMat = gMat.T
# 라이브러리 제공 함수를 이용해서 생성한 이미지
gMat_2d = np.outer(gMat, TgMat)
#필터 생성
myFilter = mygaussianFilter(9, 1)
image = cv2.imread("./gear.jpg", cv2.IMREAD_GRAYSCALE).astype(np.float32)
                         
image_2 = np.zeros_like(image, dtype=np.float32)
image_3 = np.zeros_like(image, dtype=np.float32)

h, w = image.shape
for x in range(h):
    for y in range(w):
        image_2[x, y] = MyKernelConv(image, myFilter, x, y, h, w, 9)
        image_3[x, y] = MyKernelConv(image, gMat_2d, x, y,h, w, 9)
#생성한 이미지 파일을 출력하기 위해서 0 ~255 의 값으로 변경
image = image.astype(np.uint8)
image_2 = image_2.astype(np.uint8)
image_3 = image_3.astype(np.uint8)
hist1 = cv2.calcHist([image],   [0], None, [256], [0, 256])
hist2 = cv2.calcHist([image_2], [0], None, [256], [0, 256])
hist3 = cv2.calcHist([image_3], [0], None, [256], [0, 256])
hist1 = hist1.ravel() / hist1.max()
hist2 = hist2.ravel() / hist2.max()
hist3 = hist3.ravel() / hist3.max()
#출력
x= np.arange(256)
plt.subplot(321), plt.imshow(image, 'gray'), plt.title("image")
plt.subplot(322), plt.bar(x, hist1, width=1, color='r'), plt.xlim([-1, 256])
plt.subplot(323), plt.imshow(image_2, 'gray'), plt.title("image_2")
plt.subplot(324), plt.bar(x, hist2, width=1,  color='b'), plt.xlim([-1, 256])
plt.subplot(325), plt.imshow(image_3, 'gray'), plt.title("image_3")
plt.subplot(326), plt.bar(x, hist3, width=1,  color='g'), plt.xlim([-1, 256])
plt.show()