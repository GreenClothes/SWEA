from collections import deque

T = int(input())

for t in range(1, T+1):
    N, M = map(int, input().split())
    road = {i:[] for i in range(1, N+1)}
    cycle = []

    for _ in range(M):
        s, e, c = map(int, input().split())
        road[s].append([e, c])
    for n in range(1, N+1):
        q = deque()
        visited = {i:False for i in range(1, N+1)}
        q.append([n, 0])
        visited[n] = True
        while q:
            location, length = q.popleft()
            for r in road[location]:
                if r[0] == n:
                    cycle.append(length+r[1])
                elif not visited[r[0]]:
                    visited[r[0]] = True
                    q.append([r[0], length+r[1]])
    print('#{0} {1}'.format(t, min(cycle)))