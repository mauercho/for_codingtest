N, M = map(int, input().split())

arr = list(map(int, input().split()))
arr.sort()
temp = []

def dfs(depth):
	if depth == M:
		print(*temp)
	else:
		for i in range(N):
			if len(temp) == 0 or temp[-1] <= arr[i]:
				temp.append(arr[i])
				dfs(depth + 1)
				temp.pop()

dfs(0)
