def solution(N, stages):
    length = len(stages)
    d = dict()
    for stage in stages:
        if stage in d:
            d[stage] += 1
        else:
            d[stage] = 1
    lst = []
    answer = []
    for i in range(1, N + 1):
        if i in d:
            lst.append((d[i]/length, i))
            length -= d[i]
        else:
            lst.append((0, i))
    
    lst.sort(key=lambda x: (-x[0] ,x[1]))
    for mem in lst:
        answer.append(mem[1])
    return answer