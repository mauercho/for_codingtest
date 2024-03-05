N, M = map(int, input().split())

arr = list(map(int, input().split()))
arr.sort()
temp = []
visited = [False] * N

def dfs(depth, start):
    if depth == M:
        print(*temp)
    else:
        prev = 0
        for i in range(start, N):
            if not visited[i] and prev != arr[i]:
                visited[i] = True
                temp.append(arr[i])
                prev = arr[i]
                dfs(depth + 1, i + 1)
                visited[i] = False
                temp.pop()

dfs(0, 0)