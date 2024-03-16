M =1234567891
r = 31
alpha = "0abcdefghijklmnopqrstuvwxyz"

N = int(input())
string = input()
sum_val = 0
for i in range(len(string)):
    sum_val += alpha.index(string[i]) * (r ** i)

print(sum_val % M)