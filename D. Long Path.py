n = int(input())
a = list(map(int, input().split()))
dp = [0 for i in range(n+1)]
for i in range(n+1):
    if i > 0 : dp[i] = (2*dp[i-1]+2-dp[a[i-1]-1])%1000000007
print((dp[n]+1000000007)%1000000007)