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

 	int b,k;
 	cin>>b>>k;
 	int a[k + 1];
 	int p = 1;
 	fr(i,1,k + 1)
 	{
 		cin>>a[i];
 	}

 	int ans = 0;
 	for(int i = k; i >= 1; i--)
 	{
 		ans += p*a[i];
 		ans%= 2;
 		p*=b;
 	}

 	if(ans%2 == 0) cout<<"even";
 	else cout<<"odd";

}