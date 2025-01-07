from bisect import bisect_left, bisect_right

def get_range(word, arr): # 맨 앞 글자수
    a = bisect_left(arr, word.replace('?', 'a'))
    b = bisect_right(arr, word.replace('?', 'z'))
    return b - a
def solution(words, queries):
    answer = []
    array = [[] for _ in range(10001)]
    reverse_array = [[] for _ in range(10001)]
    for word in words:
        length = len(word)
        array[length].append(word)
        reverse_array[length].append(word[::-1])
    
    for i in range(1, 10001):
        array[i].sort()
        reverse_array[i].sort()
    for query in queries:
        if query[0] != '?': # 뒷글자가 ? 입니다. 그냥 array 봐야함.
            count = get_range(query, array[len(query)]) 
        else:
            count = get_range(query[::-1], reverse_array[len(query)])
        answer.append(count)
    return answer