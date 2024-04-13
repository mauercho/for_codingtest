import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

def recursive(a, n):
    if n == 1:
        return a % c
    temp = recursive(a, n // 2)
    if n % 2 == 0 :
        return (temp * temp) % c
    else:
        return (temp * temp * a) % c

a, b, c = map(int, input().split())

print(recursive(a, b))