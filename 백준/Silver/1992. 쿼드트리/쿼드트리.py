import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def dfs(a, b, gap):
    first = arr[a][b]
    flag = True  # flag가 true 면 gap만큼이 모두 같은거임.
    for i in range(gap):
        for j in range(gap):
            if first != arr[a + i][b + j]:
                flag = False
                break
        if not flag: # 다른것이 있음.
            break 
    if flag:
        print(first, end='')
    else:
        print('(', end='')
        dfs(a, b, gap // 2)
        dfs(a, b + gap // 2, gap // 2)
        dfs(a + gap // 2, b, gap // 2)
        dfs(a + gap // 2, b + gap // 2, gap // 2)
        print(')', end='')


N = int(input())

arr = []

for _ in range(N):
    arr.append(input().rstrip())

dfs(0, 0, N)