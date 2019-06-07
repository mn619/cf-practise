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

 	int s, v1, v2, t1, t2;
 	cin>>s>>v1>>v2>>t1>>t2;

 	int a = s*v1 + 2*t1;
 	int b = s*v2 + 2*t2;
 	cout<<a<<" "<<b<<'\n';

 	if(a > b) cout<<"Second";
 	else if(a < b) cout<<"First";
 	else cout<<"Friendship";

}
