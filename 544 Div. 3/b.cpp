#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k;
int cnt[100] = {0};

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n>>k;

 	fr(i,1,n + 1)
 	{
 		int d;
 		cin>>d;
 		d %= k;
 		cnt[d]++;
 	}
 	int ans = 0;
 	//cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<"\n";

 	fr(i,1,k)
 	{
 		if(i != k - i) ans += min(cnt[i], cnt[k - i]);
 		else ans += cnt[i] - (cnt[i]&1);
 	}
 	ans += 2*(cnt[0]/2);
 	cout<<ans<<"\n";


}