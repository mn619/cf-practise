#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n, q[200001] = {0};

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n;

 	set <int> s;
 	cin>>q[1];
 	int mn = q[1], mx = q[1];
 	s.insert(q[1]);
 	if(q[1] == 0) return cout<<-1, 0;
 	fr(i, 2, n) 
 	{
 		cin>>q[i];
 		q[i] += q[i - 1];
 		if(q[i] == 0) return cout<<-1, 0;
 		s.insert(q[i]);
 		mn = min(mn, q[i]);
 		mx = max(mx, q[i]);
 	}
 	if(s.size() == n - 1) 
 	{
 		if(mn < 0) q[0] 	= -mn + 1;
 		else q[0] = 1;
 		if(q[0] + mx > n || q[0] > n) return cout<<-1, 0;
 		cout<<q[0]<<" ";
 		fr(i, 1, n) cout<<q[0] + q[i]<<" ";
 	}
 	else return cout<<-1, 0;
}