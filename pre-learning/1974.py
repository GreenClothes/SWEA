T = int(input())

def Sudoku(puzzle):
    check = [[0, 0], [3, 1], [6, 2], [1, 3], [4, 4], [7, 5], [2, 6], [5, 7], [8, 8]]

    for i, j in check:
        num1, num2, num3 = [], [], []
        for k in range(9):
            if puzzle[i][k] not in num1:
                num1.append(puzzle[i][k])
            else:
                return 0
            if puzzle[k][j] not in num2:
                num2.append(puzzle[k][j])
            else:
                return 0

        for y in range(i//3*3, i//3*3+3):
            for x in range(j//3*3, j//3*3+3):
                if puzzle[y][x] not in num3:
                    num3.append(puzzle[y][x])
                else:
                    return 0
    return 1

for t in range(1, T+1):
    case = [list(map(int, input().split())) for _ in range(9)]
    print("#{0} {1}".format(t, Sudoku(case)))