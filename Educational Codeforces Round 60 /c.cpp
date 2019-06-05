#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int x,y, n;

pair<int, int> f(pair<int,int> a, char c, char d)
{
	pair<int,int> ans =a;
	if(c == 'U')ans.second++;
	if(c == 'D') ans.second--;
	if(c == 'L')ans.first--;
	if(c == 'R') ans.first++;

	if(d == '$') return ans;
	if(d == 'U')ans.second++;
	if(d == 'D') ans.second--;
	if(d == 'L')ans.first--;
	if(d == 'R') ans.first++;
	return ans;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>x>>y;
 	int xx, yy;
 	cin>>xx>>yy;
 	x = xx - x, y = yy - y;

 	cin>>n;

 	char s[n+ 1];
 	fr(i,1,n + 1)cin>>s[i];
 	int a[n + 1] = {0};

 	fr(i,1,n + 1)
 	{
 		if(s[i] == 'U' || s[i] == 'L')a[i] = a[i - 1] +1;
 		else a[i] = a[i - 1] - 1;
 		a[i]++;
 	}


 	int ans = mod, sm = a[n];
 	fr(i,1,n + 1)
 	{
 		if(a[i] >= x + y)return cout<<i,0;
 	}
}