#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n, k;
 	cin>>n>>k;
 	if(n <= 4 || k <= n) return cout<<-1, 0;

 	int a, b, c,d ;
 	cin>>a>>b>>c>>d;

 	int ans[n + 1] = {0, 2, 1, 3, 4};
 	ans[n] = n - 1;

 	fr(i, 5, n - 1){
 		ans[i] = i;
 	}
 	ans[n - 1] = n;


 	int mp[n + 1];
 	mp[1] = a, mp[n] = b, mp[2] = c, mp[n - 1] = d;

 	int cnt = 1;
 	int i = 1;
 	while(cnt <= n){
 		if(i == 1 || i == 2 || i == n - 1 || i == n) {i++; continue;}
 		if(cnt == a || cnt == b || cnt == c || cnt == d){cnt++; continue;}
 		mp[i++] = cnt++;

 	}

 	fr(i, 1,n + 1){
 		cout<<mp[i]<<" ";
 	}
 	cout<<'\n';
 	fr(i, 1, n + 1) cout<<mp[ans[i]]<<" ";
}