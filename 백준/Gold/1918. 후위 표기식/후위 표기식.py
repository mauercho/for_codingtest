import sys
input = sys.stdin.readline

icp = {'(': 3, '*': 2, '/': 2, '+': 1, '-': 1} # 스택 밖에
isp = {'(': 0, '*': 2, '/': 2, '+': 1, '-': 1} # 스택 안에

oper = "(+-*)/"
arr = input().rstrip()
string = "(" + arr + ")"

stack = []

for alpha in string:
    if alpha in oper: # 연산자면    
        if not stack: # 스택 비었을때
            stack.append(alpha)
        else: 
            if alpha == ')':
                while stack[-1] != '(':
                    print(stack.pop(), end='')
                stack.pop() # ( 추출 
            else:
                if stack and isp[stack[-1]] < icp[alpha]:
                    stack.append(alpha)
                else: # 같거나 작음.
                    while stack and isp[stack[-1]] >= icp[alpha]:
                        print(stack.pop(), end='')
                    stack.append(alpha)
    else:
        print(alpha, end='')
        