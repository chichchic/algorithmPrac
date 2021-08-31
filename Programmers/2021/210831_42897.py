def solution(money):
    dp1 = [0] * len(money)
    dp1[0] = money[0]
    dp1[1] = max(money[0], money[1])

    for idx in range(2, len(money) - 1):
        dp1[idx] = max(dp1[idx-1], dp1[idx-2] + money[idx])

    dp2 = [0] * len(money)
    dp2[0] = 0
    dp2[1] = money[1]
    for idx in range(2, len(money)):
        dp2[idx] = max(dp2[idx-1], dp2[idx-2] + money[idx])

    return max(max(dp1), max(dp2))
