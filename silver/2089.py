N = int(input())
if N == 0:
    print(0)
else:
	div_num = -2

	lst = []
	while abs(N) != 1:
		if N < 0:
			if -N % 2 == 0:
				lst.append(0)
				N = (-N) // 2
			else:
				lst.append(1)
				N = ((-N) + 1) // 2
		else:
			if N % 2 == 1:
				lst.append(1)
				N = (-1) * (N // 2)
			else:
				lst.append(0)
				N = -(N // 2)
	if N == -1:
		lst.append(1)
		lst.append(1)
	else:
		lst.append(1)
	lst.reverse()
	for i in range(len(lst)):
		print(lst[i],end='')

	print()