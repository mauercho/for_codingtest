import sys
input = sys.stdin.readline

def preorder(start):
    print(d_idx_to_alpha[start],end='')
    if graph[start][0] != -1:
        preorder(graph[start][0])
    if graph[start][1] != -1:
        preorder(graph[start][1])

def inorder(start):
    if graph[start][0] != -1:
        inorder(graph[start][0])
    print(d_idx_to_alpha[start],end='')
    if graph[start][1] != -1:
        inorder(graph[start][1])

def postorder(start):
    if graph[start][0] != -1:
        postorder(graph[start][0])
    if graph[start][1] != -1:
        postorder(graph[start][1])
    print(d_idx_to_alpha[start],end='')


N = int(input())

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
d_alpha_to_idx = dict()
d_idx_to_alpha = dict()
for i, val in enumerate(alphabet):
    d_alpha_to_idx[val] = i
    d_idx_to_alpha[i] = val

graph = [[] for _ in range(N)]

for i in range(N):
    a, b, c = input().split()
    idx1 = d_alpha_to_idx[a]
    if b == ".":
        graph[idx1].append(-1)
    else:
        graph[idx1].append(d_alpha_to_idx[b])
    if c == ".":
        graph[idx1].append(-1)
    else:
        graph[idx1].append(d_alpha_to_idx[c])

preorder(0)
print()
inorder(0)
print()
postorder(0)


