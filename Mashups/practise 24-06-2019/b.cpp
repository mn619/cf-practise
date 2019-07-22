#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, a[maxn];


int kadane(){
	int sum = 0, ans = 0;
	fr(i, 1, n +1 ){
		sum += a[i];
		ans = max(sum , ans);
		if(sum < 0) sum = 0;
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

	fr(i, 1, n + 1) cin>>a[i];
	n--;

	fr(i, 1, n + 1){
		a[i] = abs(a[i] - a[i + 1]);
	} 	

	fr(i, 1, n + 1){
		if(i&1) a[i] *= -1;
	}

	int ans = kadane();
	fr(i, 1, n + 1) a[i] *= -1;
	ans = max(ans, kadane());
	cout<<ans;
}