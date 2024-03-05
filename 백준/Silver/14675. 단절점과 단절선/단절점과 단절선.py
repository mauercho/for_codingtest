import sys
input = sys.stdin.readline

N = int(input())
node_info = [[] for _ in range(N + 1)]

for i in range(1, N):
    a, b = map(int, input().split())
    node_info[a].append(b)
    node_info[b].append(b)

q = int(input())
for _ in range(q):
    t, k = map(int, input().split())
    if t == 1:
        if len(node_info[k]) < 2:
            print("no")
        else:
            print("yes")
    elif t == 2:
        print("yes")