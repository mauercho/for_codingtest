while True:
    T = input()
    if int(T) == 0:
        break
    length = len(T)
    for i in range(length // 2):
        if T[i] != T[length - 1 - i]:
            print("no")
            break
    else:
        print("yes")