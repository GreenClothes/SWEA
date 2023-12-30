T = int(input())

def rotate(size, matrix):
    change = [[] for _ in range(size)]
    for x in range(size):
        for y in range(size-1, -1, -1):
            change[x].append(matrix[y][x])
    return change

for t in range(1, T+1):
    N = int(input())
    case = [list(map(int, input().split())) for _ in range(N)]

    rot90 = rotate(N, case)
    rot180 = rotate(N, rot90)
    rot270 = rotate(N, rot180)

    print('#{0}'.format(t))
    for i in range(N):
        print(*rot90[i], sep='', end=' ')
        print(*rot180[i], sep='', end=' ')
        print(*rot270[i], sep='')