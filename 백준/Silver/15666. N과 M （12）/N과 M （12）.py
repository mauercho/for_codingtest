N, M = map(int, input().split())

arr = list(map(int, input().split()))
arr = sorted(list(set(arr)))
temp = []
N = len(arr)

def dfs(depth, start):
    if depth == M:
        print(*temp)
    else:
        for i in range(start, N):
            temp.append(arr[i])
            dfs(depth + 1, i)
            temp.pop()


dfs(0, 0)