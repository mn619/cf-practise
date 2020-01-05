#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 100000000000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, a[maxn], k, pref[maxn], suf[maxn];

int lef(int x){
	int l = 1, r = n, ans = 0;
	while(l <= r){
		int mid = (l + r)/2;
		if(a[mid] < x) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int rig(int x){
	int l = 1, r = n, ans = n + 1;
	while(l <= r){
		int mid = (l + r)/2;
		if(a[mid] > x) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

int check(int x){
	int ans = inf;
	fr(i, 1, n + 1){
		int l = lef(a[i]), r = rig(a[i] + x);
		ans = min(ans, a[i]*l - pref[l] + suf[r] - (n + 1 - r)*(a[i] + x));
	}

	fr(i, 1, n + 1){
		int l = lef(a[i] - x), r = rig(a[i]);
		ans = min(ans, (a[i] - x)*l - pref[l] + suf[r] - (n + 1 - r)*a[i]);
	}
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;	

 	fr(i, 1, n + 1) cin>>a[i];
 	sort(a + 1, a + n + 1);
 	fr(i, 1, n + 1){
 		pref[i] = pref[i - 1] + a[i];
 	}

 	for(int i = n; i >= 1; i--){
 		suf[i] = suf[i + 1] + a[i];
 	}

 	int l = 0, r = a[n] - a[1], ans = a[n] - a[1];

 	while(l <= r){
 		int mid = (l + r)/2;
 		if(check(mid) <= k){
 			ans = mid;
 			r = mid - 1;
 		}
 		else l = mid + 1;
 	}

 	cout<<ans<<'\n';
}