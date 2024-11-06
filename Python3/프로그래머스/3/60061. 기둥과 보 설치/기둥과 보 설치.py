def possible(arr):
    for mem in arr:
        x, y, a = mem
        if a == 0: # 기둥
            if y == 0 or [x - 1, y, 1] in arr or [x, y, 1] in arr or [x, y - 1, 0] in arr:
                continue
            return False
        else: # 보 
            if [x, y - 1, 0] in arr or [x + 1, y - 1, 0] in arr or ([x - 1, y, 1] in arr and [x + 1, y, 1] in arr):
                continue
            return False
    return True

def solution(n, build_frame):
    arr = []
    for frame in build_frame:
        x, y, a, b = frame
        if b == 1: # 설치 
            arr.append([x, y, a])
            if not possible(arr):
                arr.pop()
        else: # 삭제   
            arr.remove([x, y, a])
            if not possible(arr):
                arr.append([x, y, a])
    return sorted(arr)