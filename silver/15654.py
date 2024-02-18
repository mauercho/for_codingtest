N, M = map(int, input().split())

arr = list(map(int, input().split()))
arr.sort()

temp = []

def dfs(depth):
	if depth == M:
		print(*temp)
	else:
		for i in range(N):
			if arr[i] not in temp:
				temp.append(arr[i])
				dfs(depth+1)
				temp.pop()

dfs(0)