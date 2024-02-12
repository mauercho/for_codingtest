import sys
input = sys.stdin.readline
N = int(input())

for _ in range(N):
	A_lst = [0] * 5
	B_lst = [0] * 5
	who_win = 'D'
	for mem in input().split()[1:]:
		A_lst[int(mem)] += 1
	for mem in input().split()[1:]:
		B_lst[int(mem)] += 1
	for i in range(4 , 0, -1):
		if A_lst[i] > B_lst[i]:
			who_win = 'A'
			break
		elif A_lst[i] < B_lst[i]:
			who_win = 'B'
			break
	print(f"{who_win}")

