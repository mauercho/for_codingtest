N, M = map(int,input().split())
arr = sorted(list(map(int, input().split())))

temp = [] 
def dfs(depth, start):
    if depth == M:
        print(*temp)
    else:
        prev = 0
        for j in range(start, N):
            if prev != arr[j]:
                temp.append(arr[j])
                prev = arr[j]
                dfs(depth + 1, j)
                temp.pop()

dfs(0, 0)
