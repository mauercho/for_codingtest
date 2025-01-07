from collections import deque

def get_next_pos(pos, visited, new_board):
    now_p1_i = pos[0][0]
    now_p1_j = pos[0][1]
    now_p2_i = pos[1][0]
    now_p2_j = pos[1][1]
    
    lst = []
    # 이동할거임. 
    for move in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        next_p1_i, next_p1_j = now_p1_i + move[0], now_p1_j + move[1]
        next_p2_i, next_p2_j = now_p2_i + move[0], now_p2_j + move[1]
        if new_board[next_p1_i][next_p1_j] == 1 or new_board[next_p2_i][next_p2_j] == 1:
            continue
        if ((next_p1_i, next_p1_j), (next_p2_i, next_p2_j)) in visited:
            continue
        lst.append(((next_p1_i, next_p1_j), (next_p2_i, next_p2_j)))
    # 회전
    # 가로 
    if now_p1_i == now_p2_i:
        # 아래로
        if new_board[now_p1_i + 1][now_p1_j] == 0 and new_board[now_p2_i + 1][now_p2_j] == 0:
            if ((now_p1_i, now_p1_j), (now_p1_i + 1, now_p1_j)) not in visited:
                lst.append(((now_p1_i, now_p1_j), (now_p1_i + 1, now_p1_j)))
            if ((now_p2_i, now_p2_j), (now_p2_i + 1, now_p2_j)) not in visited:
                lst.append(((now_p2_i, now_p2_j), (now_p2_i + 1, now_p2_j)))
        # 위로
        if new_board[now_p1_i - 1][now_p1_j] == 0 and new_board[now_p2_i - 1][now_p2_j] == 0:
            if ((now_p1_i - 1, now_p1_j), (now_p1_i, now_p1_j)) not in visited:
                lst.append(((now_p1_i - 1, now_p1_j), (now_p1_i, now_p1_j)))
            if ((now_p2_i - 1, now_p2_j), (now_p2_i, now_p2_j)) not in visited:
                lst.append(((now_p2_i - 1, now_p2_j), (now_p2_i, now_p2_j)))
    # 세로 
    else:
        # 오른쪽
        if new_board[now_p1_i][now_p1_j + 1] == 0 and new_board[now_p2_i][now_p2_j + 1] == 0:
            if ((now_p1_i, now_p1_j), (now_p1_i, now_p1_j + 1)) not in visited:
                lst.append(((now_p1_i, now_p1_j), (now_p1_i, now_p1_j + 1)))
            if ((now_p2_i, now_p2_j), (now_p2_i, now_p2_j + 1)) not in visited:
                lst.append(((now_p2_i, now_p2_j), (now_p2_i, now_p2_j + 1)))
        
        # 왼쪽
        if new_board[now_p1_i][now_p1_j - 1] == 0 and new_board[now_p2_i][now_p2_j - 1] == 0:
            if ((now_p1_i, now_p1_j - 1), (now_p1_i, now_p1_j)) not in visited:
                lst.append(((now_p1_i, now_p1_j - 1), (now_p1_i, now_p1_j)))
            if ((now_p2_i, now_p2_j - 1), (now_p2_i, now_p2_j)) not in visited:
                lst.append(((now_p2_i, now_p2_j - 1), (now_p2_i, now_p2_j)))
    return tuple(lst)
        
    

def solution(board):
    answer = 0
    n = len(board)
    new_board = [[1] * (n + 2) for _ in range(n + 2)]
    for i in range(n):
        for j in range(n):
            new_board[i + 1][j + 1] = board[i][j]
    visited = set()
    visited.add(((1, 1), (1, 2))) # 이걸로 방문 여부 체크할거임.
    q = deque()
    q.append((((1, 1), (1, 2)), 0))
    
    while q:
        pos, cnt = q.popleft()
        if (n, n) in pos: # ((1, 1), (2, 1)) 관건은 리스트 -> 튜플 -> 리스트임.
            answer = cnt
            break
        next_poses = get_next_pos(pos, visited, new_board) # 최종 튜플로 반환하자. 안에서는 리스트로 하고.
        for p in next_poses: # ((1, 1), (2, 1)) 이거 튜플로 변환 시켜서 받아야할듯?
            if p not in visited:
                visited.add(p)
                q.append((p, cnt + 1))
            
    return answer