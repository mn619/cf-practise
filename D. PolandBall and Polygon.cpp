#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 2000000

using namespace std;

int n, k, bit[maxn], ans = 1, cur = 0;

void update(int x){
	x++;
	while(x <= n) bit[x]++, x += x&-x;
}

int queri(int l, int r){
	l++, r++;
	int res = 0, x = r;
	while(x > 0) res += bit[x], x -= x&-x;
	x = l - 1;
	while(x > 0) res -= bit[x], x -= x&-x;
	return res;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;
 	if(k > n/2) k = n - k;

 	fr(i, 1, n + 1){
 		int nex = (cur + k)%n;

 		if(nex > cur || nex == 0 || cur == n - 1) ans += queri((cur + 1)%n, (nex - 1 + n)%n);
 		else ans += queri((cur + 1)%n, n - 1) + queri(0, (nex - 1 + n)%n);
 		ans++;

 		update(cur);
 		update(nex);

 		cout<<ans<<' ';
 		cur = nex;
 	}

}