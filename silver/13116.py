def find_parent(a_lst, b_lst):
    for i in b_lst:
        for j in a_lst:
            if i == j:
                return 10 * i

T = int(input())

cnt = 0

parent = [0] * 1024

for i in range(2, 1024):
    parent[i] = i // 2



for _ in range(T):
    a_lst = []
    b_lst = []
    a, b = map(int, input().split())
    while a != 0:
        a_lst.append(a)
        a = a // 2
    while b != 0:
        b_lst.append(b)
        b = b // 2
    ans =0
    print(find_parent(a_lst, b_lst))
