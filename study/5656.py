T = int(input())

def left_brick(left_state):
    left = 0
    for h in range(H):
        left += (W - left_state[h].count(0))
    return left

def marble(state, n):
    if n == N:
        result.append(left_brick(state))
        return

    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]

    for w in range(W):
        arr = [x[:] for x in state]
        stack = set()

        for h in range(H):
            if arr[h][w]:
                stack.add((h, w))
                break
        while stack:
            y, x = stack.pop()
            if not arr[y][x]:
                continue

            for d in range(arr[y][x]):
                for i in range(4):
                    dr, dc = y + dy[i]*d, x + dx[i]*d
                    if 0<=dr<H and 0<=dc<W:
                        stack.add((dr, dc))
            arr[y][x] = 0

        for c in range(W):
            fall_pos = H-1
            for r in range(H-1, -1, -1):
                if not arr[r][c]:
                    continue
                arr[fall_pos][c], arr[r][c] = arr[r][c], arr[fall_pos][c]
                fall_pos -= 1
        marble(arr, n+1)

for t in range(1, T+1):
    N, W, H = map(int, input().split())
    bricks = [list(map(int, input().split())) for _ in range(H)]
    result = []

    marble(bricks, 0)
    print('#{0} {1}'.format(t, min(result)))
