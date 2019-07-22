n = int(input())
arr = input().split() 
b = []

for x in arr:
	b.append(int(x))

cnt = {}
ans = 0

for i in range(n):
	ans += b[i]*(i) + (-b[i])*(n - i - 1)

for i in range(n):
	if((b[i] - 1) in cnt.keys()):
		ans -= cnt[b[i] - 1]
	if((b[i] + 1) in cnt.keys()):
		ans += cnt[b[i] + 1]
	if((b[i]) in cnt.keys()):
		cnt[b[i]] += 1
	else:
		cnt[b[i]] = 1

print(ans)