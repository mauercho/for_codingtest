from collections import deque

def bfs():
    q = deque()
    q.append((N, 0))
    visited[N] = True
    while q:
        x, cnt = q.popleft()
        if x == K:
            return cnt
        if 0 <= x - 1 <= 100000 and not visited[x - 1]:
            q.append((x - 1,cnt + 1))
            visited[x - 1] = True
        if 0 <= x + 1 <= 100000 and not visited[x + 1]:
            q.append((x + 1, cnt + 1))
            visited[x + 1] = True
        if x != 0 and 2 * x <= 100000 and not visited[2 * x]:
            q.append((2 * x, cnt + 1))
            visited[2 * x] = True


N, K = map(int, input().split())
visited = [False] * 100001
print(bfs())
