N, M = map(int, input().split())

temp = []

def dfs(depth):
	if depth == M:
		print(*temp)
	else:
		for i in range(1, N + 1):
			if len(temp) == 0 or (i not in temp and temp[-1] < i):
				temp.append(i)
				dfs(depth + 1)
				temp.pop()
dfs(0)