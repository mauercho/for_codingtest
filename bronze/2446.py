N = int(input())

for i in range(N):
    string = ""
    string += " " * i
    string += "*" * (2 * (N - i) - 1) 
    string += " " * i
    print(string.rstrip())
for i in range(N - 2, -1, -1):
    string = ""
    string += " " * i
    string += "*" * (2 * (N - i) - 1) 
    string += " " * i
    print(string.rstrip())