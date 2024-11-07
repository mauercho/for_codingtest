import sys
from itertools import combinations

input = sys.stdin.readline

def get_dist(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

N, M = map(int, input().split())

ans = 987654321
chick_houses = []
houses = []
for i in range(N):
    lst = list(map(int, input().split()))
    for j in range(N):
        if lst[j] == 1:
            houses.append((i, j))
        elif lst[j] == 2:
            chick_houses.append((i, j))

for mem in combinations(chick_houses, M):
    temp_sum = 0
    for house in houses:
        temp = 100000
        for chicken in mem:
            temp = min(temp, get_dist(chicken, house))
        temp_sum += temp
    ans = min(temp_sum, ans)

print(ans)

