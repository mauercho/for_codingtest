N = int(input())
lst = list(map(int, input().split()))
start_idx = 0
end_idx = len(lst) - 1

result = abs(lst[start_idx] + lst[end_idx])
final_start = start_idx
final_end = end_idx
while start_idx != end_idx:
    if abs(lst[start_idx] + lst[end_idx]) < result:
        result = abs(lst[start_idx] + lst[end_idx])
        final_start = start_idx
        final_end = end_idx
    if lst[start_idx] + lst[end_idx] > 0:
        end_idx -= 1
    elif lst[start_idx] + lst[end_idx] < 0:
        start_idx += 1
    else:
        break

print(lst[final_start], lst[final_end])
    
