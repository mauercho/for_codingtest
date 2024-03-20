import sys

input = sys.stdin.readline

dict_eng = dict()
dict_num = dict()
N, M = map(int, input().split())
for i in range(N):
    s = input().rstrip()
    dict_eng[s] = i + 1
    dict_num[i + 1] = s

for _ in range(M):
    s = input().rstrip()
    if ord('0') <= ord(s[0]) <= ord('9'):
        print(dict_num[int(s)])
    else:
        print(dict_eng[s])