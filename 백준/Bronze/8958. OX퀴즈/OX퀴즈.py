def n8958():
    ox = input()
    score = 0
    point = 1
    for i in range(len(ox)):
        if ox[i] == "O":
            score += point
            point += 1
        elif ox[i] == "X":
            point = 1
    print(score)
    return 0;

for i in range(int(input())):
    n8958()
