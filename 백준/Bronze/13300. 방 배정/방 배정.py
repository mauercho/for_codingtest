import sys

input = sys.stdin.readline

N, K = map(int, input().split())
arr = [[0] * 2 for _ in range(7)]
for _ in range(N):
	S, Y = map(int, input().split())
	arr[Y][S] += 1

cnt = 0
for i in range(1, 7):
	for j in range(2):
		if arr[i][j] > 0:
			if arr[i][j] % K == 0:
				cnt += arr[i][j] // K
			else:
				cnt += (arr[i][j] // K) + 1

print(cnt)