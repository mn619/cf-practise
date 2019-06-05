def dfs(node, cnt):
    if cnt > m:
        return

    vis[node] = 1
    for i in v[node]:
         if vis[i] == 0:
             if a[i] == 1:
                 dfs(i, cnt + 1)
             else:
                 dfs(i, 0)


n, m = input().split()
n = int(n)
m = int(m)
ans=0

a = list(map(int, input().split()))

v = [[] for i in range(n+1)]
vis = [0 for i in range(n+1)]


for i in range(n - 1):
    x, y = map(int, input().split())
    v[x - 1].append(y - 1)
    v[y - 1].append(x - 1)
if a[0] == 1:
    dfs(0, 1)
else:
    dfs(0, 0)
for i in range(n):
    if i!=0 and len(v[i])==1 and vis[i]==1:
        ans+=1

print(ans)