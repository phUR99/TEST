import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
from IPython import display
import time

plt.ion()
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')


def plot(x, y, z):
    ax.clear()
    ax.plot(x, y, z, marker='o')
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    #ax.set_xlim([-100, 100])  # X 축 범위 설정
    #ax.set_ylim([-100, 100])  # Y 축 범위 설정
    #ax.set_zlim([-100, 100])
    #plt.draw()
    plt.pause(.1)

# Example usage
x = [0]  # 초기 x 좌표
y = [0]  # 초기 y 좌표
z = [0]  # 초기 z 좌표

num_steps = 10000  # 총 시뮬레이션 단계

for _ in range(num_steps):
    # 가우시안 분포에서 좌표 생성
    
    new_x = x[-1] + np.random.randint(-5, 5)  # x 좌표
    new_y = y[-1] + np.random.randint(-5, 5)  # y 좌표
    new_z = z[-1] + np.random.randint(-5, 5)  # z 좌표    


    # 좌표를 리스트에 추가
    x.append(new_x)
    y.append(new_y)
    z.append(new_z)
    
    # 시각화
    plot(x, y, z)
