string = input().lower()
lst = list(set(string))
cnt_lst = []
for mem in lst:
    cnt_lst.append(string.count(mem))

max_val = max(cnt_lst)

if cnt_lst.count(max_val) >= 2:
    print('?')
else:
    print(lst[cnt_lst.index(max_val)].upper())
