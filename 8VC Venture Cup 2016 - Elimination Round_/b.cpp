#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, c[3] = {0};
string s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>s;

 	fr(i, 0, n)
 	{
 		if(s[i] == 'R') c[0]++;
 		if(s[i] == 'G') c[1]++;
 		if(s[i] == 'B') c[2]++;
 	}

 	int cnt = 0;
 	fr(i, 0, 3) cnt += (c[i] > 0);

 	if(cnt == 3) return cout<<"BGR", 0;
 	if(cnt == 1)
 	{
 		if(c[0] > 0) cout<<"R";
 		if(c[1] > 0) cout<<"G";
 		if(c[2] > 0) cout<<"B";
 		return 0;
 	}
 	bool b[3];
 	fr(i, 0, 3) b[i] = 1;

 	if(c[0] == 0)
 	{
 		if(c[1] == 1) b[2] = 0;
 		if(c[2] == 1) b[1] = 0; 
 	}
 	if(c[1] == 0)
 	{
 		if(c[0] == 1) b[2] = 0;
 		if(c[2] == 1) b[0] = 0; 
 	}

 	if(c[2] == 0)
 	{
 		if(c[1] == 1) b[0] = 0;
 		if(c[0] == 1) b[1] = 0; 
 	}


 	if(b[2]) cout<<"B";
 	if(b[1]) cout<<"G";
 	if(b[0]) cout<<"R";
 }