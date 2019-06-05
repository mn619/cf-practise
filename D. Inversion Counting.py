n = int(input())
a = list(map(int, input().split()))
p = [0 for i in range(n+1)]
for i in range(n):
    p[a[i]] = i+1
done = [0 for i in range(n+1)]
cnt = 0
ans = 0
for i in range(1, n+1):
    temp = 0
    j = i
    if done[i] == 0:
        while done[j] != 1:
            done[j] = 1
            j = p[j]
            temp += 1
        if temp % 2 == 0:
            cnt += 1
if cnt % 2 == 1:
    ans = 1
m = int(input())
while m > 0:
    m -= 1
    l, r = map(int, input().split())
    s = r - l + 1
    if s//2 % 2 == 1:
        ans = (ans + 1)%2
    if ans % 2 == 1:
        print("odd")
    else:
        print("even")