N = int(input())
arr = list(map(int, input().split()))
B, C = map(int, input().split())

ans = 0
for mem in arr:
    if mem <= B:
        ans += 1
    else:
        if (mem - B) % C == 0:
            ans += (mem - B) // C
            ans += 1
        else:
            ans += ((mem - B) // C) + 1
            ans += 1
print(ans)