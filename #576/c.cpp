#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 400000

using namespace std;

int n, I, a[maxn + 1], cnt[maxn + 1];

int bs(int x){
	int l = 1, r = n;
	int ans = n;

	while(l <= r){
		int mid = (l + r)/2;
		if(cnt[mid] <= x){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>I;
 	I *= 8;

 	int k = I/n;
 	int len = 1;


 	fr(i, 1, n + 1) cin>>a[i];
 	sort(a + 1, a + n + 1);

 	fr(i, 1, n + 1){
 		cnt[i] = cnt[i - 1];
 		if(a[i] != a[i - 1]) cnt[i]++;
 	}

 	fr(i, 1, k + 1) {
 		len *= 2;
 		if(len >= n) return cout<<0, 0;
 	}

 	int ans = n;
 	fr(i, 1, n + 1){
 		int ind = bs(cnt[i] + len - 1);
 		ans = min(ans, i + n - ind - 1);
 	}

 	cout<<ans;
}