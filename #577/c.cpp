#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int x[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n, k;
 	cin>>n>>k;

 	map <int, bool> ok1, ok2;
 	set <int> s;

 	fr(i, 1, k + 1){
 		cin>>x[i];
 		if(s.find(x[i] - 1) != s.end()) {ok1[x[i]] = 1;}
 		if(s.find(x[i] + 1) != s.end()) {ok2[x[i]] = 1; }
 		s.insert(x[i]);
 	}

 	int ans = 3*n - 2 - ok1.size() - ok2.size() - s.size();
 	cout<<ans;
}