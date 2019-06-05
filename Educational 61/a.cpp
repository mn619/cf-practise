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

 	int c[5] = {0};
 	fr(i,1,5) cin>>c[i];
 	
 	if(c[1] != 0)
 	cout<<(c[1] == c[4])<<"\n";
 	else
 	{
 		if(c[4] == 0)
 		{
 			if(c[3] != 0)  cout<<0<<"\n";
 			else cout<<1<<'\n';
 		}
 		else cout<<"0"<<"\n";
 	}
}