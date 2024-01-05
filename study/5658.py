T = int(input())

for t in range(1, T+1):
    N, K = map(int, input().split())
    number = input()
    nums = set()

    for i in range(N//4):
        for j in range(0, N, N//4):
            nums.add(int(number[j+i:j+i+N//4], 16))
        number += number[i]
    nums = sorted(nums, reverse=True)
    print('#{0} {1}'.format(t, nums[K-1]))