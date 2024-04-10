import sys
from collections import deque
input = sys.stdin.readline

def L(x):
    return (x % 1000) * 10 + x // 1000  # 왼쪽으로 회전

def R(x):
    return (x % 10) * 1000 + x // 10  # 오른쪽으로 회전


def make_to_thousand(lst):
    if len(lst) == 4:
        return (int(lst[0]) * 1000 + int(lst[1]) * 100 + int(lst[2]) * 10 + int(lst[3]))
    elif len(lst) == 3:
        return (int(lst[0]) * 100 + int(lst[1]) * 10 + int(lst[2]))
    elif len(lst) == 2:
        return (int(lst[0]) * 10 + int(lst[1]))
    else:
        return int(lst[0])

def bfs(start, end): # 스트링을 받아서 비교
    q = deque()
    q.append((start, ""))
    visited = [False] * 10000  # 방문 여부를 체크할 배열
    visited[start] = True
    while q:
        num, action = q.popleft()
        if num == end:
            print(action)
            return
        # D
        next_num = (2 * num) % 10000
        if not visited[next_num]:
            q.append((next_num, action + "D"))
            visited[next_num] = True
        # S
        next_num = 9999 if num == 0 else num - 1
        if not visited[next_num]:
            q.append((next_num, action + "S"))
            visited[next_num] = True
        # R
        next_num = R(num)
        if not visited[next_num]:
            q.append((next_num, action + "R"))
            visited[next_num] = True
        # L
        next_num = L(num)
        if not visited[next_num]:
            q.append((next_num, action + "L"))
            visited[next_num] = True

T = int(input())

for _ in range(T):
    num_lst = input().split()
    bfs(int(num_lst[0]), int(num_lst[1]))
