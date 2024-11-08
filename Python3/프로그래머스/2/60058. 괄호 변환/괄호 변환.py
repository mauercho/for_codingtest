def check(string):
    stk = []
    for alpha in string:
        if alpha == '(':
            stk.append(alpha)
        else:
            if len(stk) == 0:
                return False
            stk.pop()
    return True

def dfs(string):
    if string == '':
        return string
    left_count = 0
    right_count = 0
    u = ''
    for alpha in string:
        if alpha == '(':
            left_count += 1
            u = u + alpha
        else:
            right_count += 1
            u = u + alpha
        if left_count == right_count:
            v = string[len(u):]
            break
    if check(u):
        return u + dfs(v)
    else:
        temp = '(' + dfs(v) + ')'
        u2 = u[1:-1]
        for a in u2:
            if a == '(':
                temp += ')'
            else:
                temp += '('
        return temp
        

def solution(p):
    answer = dfs(p)
    return answer