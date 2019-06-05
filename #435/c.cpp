#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
#define maxn 100000

int n, x;
map<int ,int> m;
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n>>x;
 	if(n == 1)return cout<<"YES\n"<<x<<'\n', 0;
 	cout<<"YES\n";

 	if(n%4 == 2){
 		for(auto y: m){
 			ans.pb(y.first);
 			ans.pb(y.second);
 			n -= 2;
 			break;
 		}
 	}
 	else if(n%4 == 1){
 		for(auto y: m){
 			if(y.first == x || y.second == x) continue;
  			ans.pb(y.first);
 			ans.pb(y.second);
 			n -= 2;
 			if(n == 1) break;
 		}
 		ans.pb(x);
 	}
 	else if(n%4 == 3){
 		for(auto y: m){
 			if(y.first == 0 || y.second == 0) continue;
 			ans.pb(y.first);
 			ans.pb(y.second);
 			n -= 2;
 			if(n == 1) break;
 		}
 		ans.pb(0);
 	}
 	else{
 		
 	}
}