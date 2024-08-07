N, K = map(int, input().split())
arr = list(map(int, input().split()))

sum_val = sum(arr[0:K])

longest = sum_val
small_idx = 0
for idx in range(K, N):
    sum_val -= arr[small_idx]
    sum_val += arr[idx]
    small_idx += 1
    if longest < sum_val:
        longest = sum_val

print(longest)
