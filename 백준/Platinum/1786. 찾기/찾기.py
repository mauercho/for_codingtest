T = input()
P = input()

p_table = [0] * len(P)

j = 0
for i in range(1, len(p_table)):
    while j > 0 and P[i] != P[j]:
        j = p_table[j - 1]
    if P[i] == P[j]:
        j += 1
    p_table[i] = j

j = 0
cnt = 0
arr_answer = []
for i in range(len(T)):
    while j > 0 and T[i] != P[j]:
        j = p_table[j - 1]

    if T[i] == P[j]:
        j += 1

        if j == len(P):
            arr_answer.append(i - j + 2)
            j = p_table[j - 1]
            cnt += 1

print(cnt)
print(*arr_answer)