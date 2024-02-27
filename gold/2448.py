def draw_star(n):
    if n == 3:
        return ["  *  ", " * * ", "*****"]

    prev_star = draw_star(n // 2)
    new_star = []

    for line in prev_star:
        new_star.append(" " * (n // 2) + line + " " * (n // 2))
    for line in prev_star:
        new_star.append(line + " " + line)

    return new_star

N = int(input())

star = draw_star(N)

for line in star:
    print(line)
