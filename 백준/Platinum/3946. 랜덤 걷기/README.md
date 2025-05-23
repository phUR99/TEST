# [Platinum III] 랜덤 걷기 - 3946 

[문제 링크](https://www.acmicpc.net/problem/3946) 

### 성능 요약

메모리: 221444 KB, 시간: 1960 ms

### 분류

다이나믹 프로그래밍, 수학, 확률론

### 제출 일자

2025년 4월 22일 21:39:08

### 문제 설명

<p>걷기 전에 동전을 던진 다음, 앞 면이면 왼쪽으로 한 칸, 뒷 면이면 오른쪽으로 한 칸 이동하는 방법을 랜덤 걷기라고 한다. 이 랜덤 걷기의 위치의 기댓값은 항상 0이 된다. 즉, 랜덤 걷기를 아무리 많이 한다고 해도, 평균 위치는 처음 시작한 지점과 같다.</p>

<p>랜덤 걷기에서 왼쪽으로 갈 확률과 오른쪽으로 갈 확률, 그리고 동전을 던지는 횟수가 주어졌을 때, 가장 오른쪽 위치의 기댓값을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에는 테스트 케이스의 P가 주어진다. 각 테스트 케이스는 모두 독립적이다.</p>

<p>각 테스트 케이스는 한 줄로 이루어져 있다. 이 줄에는 총 세 개의 숫자가 주어지는데, 왼쪽부터 순서대로 n, L, R이다. n(1 ≤ n ≤ 1000)은 동전을 던지는 횟수이다. L과 R은 각각 왼쪽으로 갈 확률과 오른쪽으로 갈 확률이다. ( 0 ≤ L ≤ 1, 0 ≤ R ≤ 1, 0 ≤ L+R ≤ 1) 이 문제에서 사용하는 동전은 조금 독특해서, 앞 면과 뒷 면이 나올 확률이 서로 다를 수도 있다. 또, 1-L-R은 동전의 옆 면이 나올 확률로, 옆 면이 나온 경우에는 그 자리에 그대로 있는다.</p>

### 출력 

 <p>각 테스트 케이스에 대해서, 가장 오른쪽 위치의 기댓값(평균)을 소수점 넷째 자리 까지 출력한다.</p>

