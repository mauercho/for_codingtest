A, B, V = map(int, input().split())

new = V - A
gap = A - B
if new % gap == 0:
    print(new // gap + 1)
else:
    print(new // gap + 2)  