for _ in range(4):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(int, input().split())
    result = 'a'

    if x2 < x3 or y2 < y3 or x4 < x1 or y4 < y1:
        result = 'd'
    elif (x2 == x3 and y2 == y3) or (x1 == x4 and y2 == y3) or (x1 == x4 and y1 == y4) or (x2 == x3 and y1 == y4):
        result = 'c'
    elif (x2 == x3) or (y2 == y3) or (y1 == y4) or (x1 == x4):
        result = 'b'
    print(result)
