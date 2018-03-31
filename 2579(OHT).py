n = int(input())
list = []
for i in range(n):
    data = int(input())
    list.append(data)
if(n==1):
    print(list[0])
elif(n==2):
    print(list[0]+list[1])
else:
    # dp[n][0]은 n+1개의계단, 마지막만 밟음,
    # dp[n][1]은 n+1개의계단, 마지막이랑 마지막전 연속해서 밟음
    dp = [[0 for col in range(2)] for row in range(n)]
    dp[0][0] = list[0]
    dp[1][0] = list[1]
    dp[1][1] = list[0] + list[1]
    for i in range(2, n):
        if dp[i - 2][0] > dp[i - 2][1]:
            dp[i][0] = dp[i - 2][0] + list[i]
        else:
            dp[i][0] = dp[i - 2][1] + list[i]
        dp[i][1] = dp[i - 1][0] + list[i]

    if dp[i][0] > dp[i][1]:
        result = dp[i][0]
    else:
        result = dp[i][1]

    print(result)

