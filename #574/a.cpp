#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, k, a[1001], cnt[1001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;

 	fr(i, 1, n + 1){
 		cin>>a[i];
 		cnt[a[i]]++;
 	}


 	int sum = 0;
 	int t = n/2 + (n&1);
 	fr(i, 1, 1001){
 		sum += cnt[i] - (cnt[i]&1);
 		t -= cnt[i]/2;
 	}

 	cout<<sum + t;
}