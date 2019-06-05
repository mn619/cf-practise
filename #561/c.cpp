#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[200001];


int bs1(int x){
	int l = 1, r = n;
	int ans = mod;
	while(l <= r){
		int mid = (l + r)/2;
		if(2*a[mid] >= x){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

int bs2(int x){
	int l = 1, r = n;
	int ans = 0;
	while(l <= r){
		int mid = (l + r)/2;
		if(2*a[mid] <= x){
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

 	cin>>n;
 	fr(i, 1, n + 1) {cin>>a[i]; a[i] = abs(a[i]);}

 	sort(a + 1, a + n + 1);
 	int ans = 0;
 	fr(i, 1, n + 1){
 		int l = bs1(a[i]), r = bs2(4*a[i]);
 		//cout<<l<<" "<<r<<" "<<a[i]<<'\n';
 		ans += max((int) 0, r - l + 1);
 	}
 	ans = (ans - n)/2;
 	cout<<ans<<'\n';
}