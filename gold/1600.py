from collections import deque
import sys

input = sys.stdin.readline

def is_valid(i, j):
    return 0 <= i < H and 0 <= j < W

input_K = int(input())
W, H = map(int, input().split())
start_i, start_j = 0, 0
end_i, end_j = H - 1, W - 1

arr = [list(map(int, input().split())) for _ in range(H)]
visited = [[[False] * (input_K + 1) for _ in range(W)] for _ in range(H)]
def bfs():
    q = deque()
    q.append((0, 0, 0, input_K))
    visited[0][0][input_K] = True
    while q:
        i, j, cnt, K= q.popleft()
        if i == end_i and j == end_j:
            return cnt
        for idx, move in enumerate([(1, 0), (0, 1), (-1, 0), (0, -1), (2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]):
            if idx >= 4:
                if K <= 0:
                    continue
                else: # K 가 있다는 거임.
                    if is_valid(i + move[0], j + move[1]) and arr[i + move[0]][j + move[1]] != 1 and not visited[i + move[0]][j + move[1]][K - 1]:
                        visited[i + move[0]][j + move[1]][K - 1] = True
                        q.append((i + move[0], j + move[1], cnt + 1, K - 1))
            else:
                if is_valid(i + move[0], j + move[1]) and arr[i + move[0]][j + move[1]] != 1 and not visited[i + move[0]][j + move[1]][K]:
                    visited[i + move[0]][j + move[1]][K] = True
                    q.append((i + move[0], j + move[1], cnt + 1, K))
    return -1


print(bfs())
