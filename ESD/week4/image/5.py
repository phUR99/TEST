import cv2
import numpy as np
from matplotlib import pyplot as plt


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

img = cv2.imread("./gear.jpg", cv2.IMREAD_GRAYSCALE)
output45 = np.zeros_like(img)
output135 = np.zeros_like(img)
h, w = img.shape
#대각의 sobel 행렬
kernel45 = np.array([[1, 0, -1], [0, 0, 0], [-1, 0, 1]], dtype=np.float32)
kernel135 = np.array([[-1, 0, 1], [0, 0, 0], [1, 0, -1]], dtype=np.float32)

for i in range(h):
    for j in range(w):
        output45[i, j] = abs(MyKernelConv(img, kernel45, i, j, h, w, 3))
        output135[i, j] = abs(MyKernelConv(img, kernel135, i, j, h, w, 3))     

   
output = (output45 + output135) / 2
cv2.imshow("output45", output45.astype(np.uint8))
cv2.imshow("output135", output135.astype(np.uint8))
cv2.imshow("output", output.astype(np.uint8))
cv2.waitKey(0)
cv2.destroyAllWindows()