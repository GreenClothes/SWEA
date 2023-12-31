from collections import deque
T = int(input())

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

for t in range(1, T+1):
    N = int(input())
    swim = [list(map(int, input().split())) for _ in range(N)]
    AB = list(map(int, input().split()))
    CD = list(map(int, input().split()))
    AB.append(0)
    visited = [[False] * N for _ in range(N)]
    visited[AB[0]][AB[1]] = True

    q = deque()
    q.append(AB)
    while q:
        y, x, time = q.popleft()
        if y == CD[0] and x == CD[1]:
            print('#{0} {1}'.format(t, time))
        for i in range(4):
            dr, dc = y+dy[i], x+dx[i]
            if 0<=dr<N and 0<=dc<N and not visited[dr][dc]:
                if swim[dr][dc] == 0:
                    visited[dr][dc] = True
                    q.append([dr, dc, time+1])
                if swim[dr][dc] == 2:
                    if time % 3 == 2:
                        visited[dr][dc] = True
                        q.append([dr, dc, time+1])
                    else:
                        q.append([y, x, time+1])