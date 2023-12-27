battle = [1, 2, 3]
A, B = map(int, input().split())
if B == battle[A-2]:
    print('A')
else:
    print('B')