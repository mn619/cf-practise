#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, x;
vector<int> ans;
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>x;
 	set <int> s;
 	s.insert(0);
 	int p = 0;

 	bool ok = 1;
 	int cnt = 0;
 	
 	while(ok){
 		cnt++;
 		bool in = 0;
 		fr(i, 1, (1<<n)){
 			if(s.find(p^i) == s.end() and s.find(p^x^i) == s.end()){
 				p ^= i;
 				ans.pb(i);
 				s.insert(p);
 				in = 1;
 			}
 		 }
 		ok = in;
 	}

 	cout<<ans.size()<<'\n';
 	//fr(i, 0, ans.size()) cout<<ans[i]<<' '; 
 	cout<<cnt;
}