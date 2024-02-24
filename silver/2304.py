import sys
input = sys.stdin.readline

N = int(input())
arr = []

max_height = -1
for _ in range(N):
	L, H = map(int, input().split())
	if max_height < H:
		max_height = H
	arr.append((L, H))

def f(arr):
	return arr[1]

if N == 1:
	print(arr[0][1])
else:

	arr.sort()

	max_idx = -1
	min_idx = 1001

	for idx in range(len(arr)):
		if arr[idx][1] == max_height:
			if min_idx > idx:
				min_idx = idx
			if max_idx < idx:
				max_idx = idx

	now_height = arr[0][1]
	sum_val = 0
	for k in range(min_idx):
		if now_height <= arr[k + 1][1]:
			sum_val += now_height * (arr[k + 1][0] - arr[k][0])
			now_height = arr[k + 1][1]
		else:
			sum_val += now_height * (arr[k + 1][0] - arr[k][0])
	for idx in range(arr[min_idx][0], arr[max_idx][0] + 1):
		sum_val += max_height
	new_arr = arr[max_idx:]
	new_arr.sort(reverse=True)
	now_height = new_arr[0][1]
	for k in range(len(new_arr) - 1):
		if now_height <= new_arr[k + 1][1]:
			sum_val += now_height * (abs(new_arr[k + 1][0] - new_arr[k][0]))
			now_height = new_arr[k + 1][1]
		else:
			sum_val += now_height * (abs(new_arr[k + 1][0] - new_arr[k][0]))
	print(sum_val)



import sys
input = sys.stdin.readline

N = int(input())
arr = []

max_height = -1
for _ in range(N):
    L, H = map(int, input().split())
    if max_height < H:
        max_height = H
    arr.append((L, H))

# 기둥 정렬
arr.sort()

# 왼쪽에서 오른쪽으로 면적 계산
now_height = arr[0][1]
sum_val = 0
for k in range(len(arr) - 1):
    if now_height <= arr[k + 1][1]:
        sum_val += now_height * (arr[k + 1][0] - arr[k][0])
        now_height = arr[k + 1][1]
    else:
        sum_val += now_height * (arr[k + 1][0] - arr[k][0])

# 최대 높이 기둥부터 오른쪽으로 면적 계산
new_arr = arr[::-1]
now_height = new_arr[0][1]
for k in range(len(new_arr) - 1):
    if now_height <= new_arr[k + 1][1]:
        sum_val += now_height * (abs(new_arr[k + 1][0] - new_arr[k][0]))
        now_height = new_arr[k + 1][1]
    else:
        sum_val += now_height * (abs(new_arr[k + 1][0] - new_arr[k][0]))

print(sum_val)