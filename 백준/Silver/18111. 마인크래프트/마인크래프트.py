import math 

ans = math.inf
temp = math.inf
N, M, B = map(int, input().split())
block = [list(map(int, input().split())) for _ in range(N)]
ans = int(1e9)
level = 0

for height in range(257):
    use_block = 0
    take_block = 0
    for x in range(N):
        for y in range(M):
            if block[x][y] > height:
                take_block += block[x][y] - height
            else:
                use_block += height - block[x][y]

    if use_block > take_block + B:
        continue

    count = take_block * 2 + use_block

    if count <= ans:
        ans = count
        level = height

print(ans, level)