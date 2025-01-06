from itertools import permutations

def solution(n, weak, dist):
    weakLen = len(weak)
    
    for mem in range(weakLen):
        weak.append(weak[mem] + n)
        
    answer = len(dist) + 1 # 절대로 나올 수 없는 값
    
    for start in range(weakLen):
        for friends in permutations(dist, len(dist)):
            count = 1
            next_val = weak[start] + friends[count - 1]
            for index in range(weakLen):
                if weak[start + index] > next_val:
                    count += 1
                    if count > len(dist):
                        break
                    next_val = weak[start + index] + friends[count - 1]
            answer = min(count, answer)
    return -1 if answer > len(dist) else answer