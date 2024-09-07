N = int(input())

arr = list(map(int, input().split()))

stack = []
cnt = [-1] * N
for i, v in enumerate(arr):
    if not stack:
        stack.append((v, i))
    else:
        if v > stack[-1][0]:
            while stack and v > stack[-1][0]:
                cnt[stack.pop()[1]] = v
            stack.append((v, i))
        else:
            stack.append((v, i))

print(*cnt)