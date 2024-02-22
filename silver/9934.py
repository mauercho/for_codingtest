def in_order(i, K):
    global idx 
    if i >= 2 ** K:
        return
    in_order(2 * i, K)
    node[i] = arr[idx]
    idx += 1
    in_order(2 * i + 1, K)

K = int(input())

node = [0] * (2 ** K)
arr = list(map(int, input().split()))

idx = 0
in_order(1, K)

idx = 1

for k in range(K):
    for j in range(2 ** k):
        print(node[idx], end = ' ')
        idx += 1
    print()