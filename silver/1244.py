def switch(arr, i):
    if arr[i] == 1:
        arr[i] = 0
    else:
        arr[i] = 1

def is_valid(a):
    return 0 <= a < T

T = int(input())

arr = list(map(int, input().split()))
N = int(input())

for _ in range(N):
    s, num = map(int, input().split())
    gap = num
    num -= 1
    if s == 1:  # 남자
        while num < T:
            switch(arr, num)
            num += gap
    elif s == 2:
        gap = 1
        while is_valid(num - gap) and is_valid(num + gap) and arr[num + gap] == arr[num - gap]:
            gap += 1
        for idx in range(1, gap):
            switch(arr, num + idx)
            switch(arr, num - idx)
        switch(arr, num)

for i in range(T):
    print(f"{arr[i]}", end=' ')
    if (i + 1)% 20 == 0:
        print()
