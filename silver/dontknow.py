from copy import deepcopy

N = int(input())
print(N, end=' ')
prev = N
lst = []

for i in range(1, N + 1):
    temp = []
    now = i
    while prev >= now:  # 루프 조건 수정
        temp.append(prev)
        temp_var = now
        now = prev - now
        prev = temp_var

    if len(temp) > len(lst):
        lst = deepcopy(temp)

print(*lst)

# 나중에 뭔지 찾아야함.