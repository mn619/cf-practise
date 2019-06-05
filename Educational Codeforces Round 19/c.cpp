#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

string s;
int a[100001], mn[100011];
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	
 	cin>>s;
 	int n = s.size();

 	fr(i, 0, n)
 	{
 		a[i + 1] = s[i] - 'a';
 	}
 	mn[n] = a[n];
 	for(int i = n - 1; i > 1; i--)
 	{
 		mn[i] = min(mn[i + 1], a[i]);
 	}
 	
 	stack <int> s;
 	vector <int> v;
 	mn[n + 1] = 1000;
 	fr(i, 1, n + 1)
 	{
 		int x = a[i];
 		s.push(x);
 		while(!s.empty() && s.top() <= mn[i + 1])
 		{
 			v.pb(s.top());
 			s.pop();
 		}
 	}

 	while(!s.empty()) 
 	{
 		v.pb(s.top());
 		s.pop();
 	}

 	for(auto x: v)
 	{
 		char c = x + 'a';
 		cout<<c;
 	}

}	