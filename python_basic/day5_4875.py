from collections import deque

T = int(input())

def bfs(n, m):
    visited = [[0 for _ in range(n)] for _ in range(n)]
    q = deque()

    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    for i in range(n):
        for j in range(n):
            if m[i][j] == '2':
                q.append([i, j])
                while q:
                    cur_v = q.popleft()
                    for k in range(4):
                        y = cur_v[0] + dy[k]
                        x = cur_v[1] + dx[k]

                        if n > x > -1 and n > y > -1:
                            if m[y][x] == '0' and not visited[y][x]:
                                visited[y][x] = 1
                                q.append([y, x])
                            elif maze[y][x] == '3':
                                return 1
                return 0

for t in range(1, T + 1):
    N = int(input())
    maze = [list(input()) for _ in range(N)]

    print('#{0} {1}'.format(t, bfs(N, maze)))
