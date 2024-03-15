arr = list(map(int, input().split()))

up = False
down = False
mix = False
for i in range(len(arr) - 1):
    if not up and not down:
        if arr[i] < arr[i + 1]:
            up = True
        else:
            down = True
    if up:
        if arr[i] > arr[i + 1]:
            mix = True
            break
    if down:
        if arr[i] < arr[i + 1]:
            mix = True
            break
if mix:
    print("mixed")
else:
    if up:
        print("ascending")
    else:
        print("descending")