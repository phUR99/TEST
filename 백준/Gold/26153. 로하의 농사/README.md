# [Gold IV] 로하의 농사 - 26153 

[문제 링크](https://www.acmicpc.net/problem/26153) 

### 성능 요약

메모리: 2036 KB, 시간: 24 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2023년 12월 1일 18:26:46

### 문제 설명

<p>로하가 사는 마을에는 정사각형 땅들이 $N \times M$행렬로 이루어져 있다. 로하는 그중 한 개의 땅에 살고 있으며 그 땅에 농사를 지으려 한다. 하지만 자신의 땅에서 나오는 물로는 농사짓기에 턱없이 부족하여 파이프를 만들어 주변에서 물을 최대한 끌어오려고 한다. 로하에게는 파이프를 만들기 위한 $p$개의 재료가 있으며 다음과 같은 규칙을 지키며 파이프를 건설해야 한다. </p>

<ul>
	<li>땅 한 칸에는 일자 파이프나 구부러진 파이프 중 하나만 설치할 수 있다.</li>
	<li>일자 파이프는 하나당 재료를 1개 소비하고 구부러진 파이프는 2개 소비한다. </li>
	<li>설치한 모든 파이프는 하나로 연결되어 있어야 하며, 파이프 한쪽 끝은 반드시 자신의 땅이어야 한다.</li>
	<li>자신의 땅에는 파이프를 설치하지 않는다.</li>
</ul>

<p>로하는 파이프가 설치된 곳의 물과 자신의 땅에서 나오는 물을 모두 합한 양을 길어올 수 있다. 로하가 길어올 수 있는 물의 최대량을 구해보자.</p>

### 입력 

 <p>첫째 줄에 $N$, $M$이 주어진다. $(1 \le N, M \le 50)$</p>

<p>둘째 줄부터 $N+1$째 줄까지 $i$행 $j$열에서 나오는 물의 양인 정수 $W_{i,j}$ $(0 \le i < N, 0 \le j < M, 0 \le W_{i,j} \le 100)$이 주어진다. </p>

<p>$N+2$ 번째 줄에는 로하가 사는 땅의 위치 $x$행 $y$열 그리고 재료 개수 $p$가 주어진다. $(0 \le x < N, 0 \le y < M, 0 \le p \le 20)$</p>

### 출력 

 <p>로하가 길어올 수 있는 물의 최대량을 출력한다.</p>

