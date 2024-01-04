from collections import deque
T = int(input())

for t in range(1, T+1):
    V, E, a, b = map(int, input().split())
    tree = {n:[] for n in range(1, V+1)}
    parent = dict()
    graph = list(map(int, input().split()))
    a_parent = [a]
    ans = 0
    q = deque()
    for i in range(0, 2*E, 2):
        tree[graph[i]].append(graph[i+1])
        parent[graph[i+1]] = graph[i]

    while a_parent[-1] != 1:
        a_parent.append(parent[a_parent[-1]])
    while b not in a_parent:
        b = parent[b]

    q.append(b)
    while q:
        qp = q.popleft()
        ans += len(tree[qp])
        for node in tree[qp]:
            q.append(node)
    print('#{0} {1} {2}'.format(t, b, ans+1))



