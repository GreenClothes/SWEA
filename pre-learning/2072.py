T = int(input())

for t in range(1, T+1):
    nums = list(map(int, input().split()))
    ans = 0
    for n in nums:
        if n % 2:
            ans += n
    print("#{0} {1}".format(t, ans))