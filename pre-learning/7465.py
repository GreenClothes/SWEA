from collections import deque
T = int(input())

for t in range(1, T+1):
    N, M = map(int, input().split())
    people = {n:[] for n in range(1, N+1)}
    visited = {n:False for n in range(1, N+1)}
    cnt = 0

    for _ in range(M):
        a, b = map(int, input().split())
        people[a].append(b)
        people[b].append(a)

    q = deque()
    for i in range(1, N+1):
        if not visited[i]:
            visited[i] = True
            q.append(i)
            cnt += 1
            while q:
                qp = q.popleft()
                for p in people[qp]:
                    if not visited[p]:
                        visited[p] = True
                        q.append(p)

    print('#{0} {1}'.format(t, cnt))