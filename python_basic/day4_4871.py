T = int(input())

def dfs(S, G):
    stack = []
    stack.append(S)

    while stack:
        v = stack.pop()
        if visited[v] == 0:
            visited[v] = 1

            for w in range(1, V+1):
                if graph[v][w] == 1 and not visited[w]:
                    if w == G:
                        return 1
                    stack.append(w)
    return 0

for t in range(1, T+1):
    V, E = map(int, input().strip().split())
    graph = [[0 for _ in range(V+1)] for _ in range(V+1)]
    for _ in range(E):
        i, j = map(int, input().strip().split())
        graph[i][j] = 1
    S, G = map(int, input().strip().split())
    visited = [False]*(V+1)

    print('#{0} {1}'.format(t, dfs(S, G)))