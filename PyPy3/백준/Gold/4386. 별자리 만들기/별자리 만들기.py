import sys
import heapq
from itertools import combinations
import math

input = sys.stdin.readline

combi_list = []

n = int(input())

q = []
distance = [[0] * (n + 1) for _ in range(n + 1)]


def get_distance(a, b):
    x1 = float(a[1])
    y1 = float(a[2])
    x2 = float(b[1])
    y2 = float(b[2])

    return math.sqrt(((x1 - x2) ** 2) + ((y1 - y2) ** 2))

def prim(start):
    q = [(0, start)]
    visited = [False] * (n + 1)
    answer = 0
    cnt = 0
    while q:
        dist, now = heapq.heappop(q)
        if visited[now]:
            continue
        visited[now] = True
        answer += dist
        cnt += 1
        if cnt == n:
            return round(answer, 2)
        for next in range(1, n + 1):
            if next == now:
                continue
            if not visited[next]:
                heapq.heappush(q, (distance[now][next], next))

    return None

for i in range(n):
    a, b = input().split()
    combi_list.append((i + 1, a, b))

for member in combinations(combi_list, 2):
    dist = get_distance(member[0], member[1])
    distance[member[0][0]][member[1][0]] = dist
    distance[member[1][0]][member[0][0]] = dist

print(prim(1))

