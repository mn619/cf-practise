#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int h1, h2, a1, a2, c;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>h1>>a1>>c>>h2>>a2;

 	vector<int> ans;

 	while(h2 > 0){
 		if(h2 - a1 <= 0){
 			ans.pb(0);
 			break;
 		} 
 		else if(h1 - a2 <= 0){
 			ans.pb(1);
 			h1 += c - a2;
 		}
 		else{
 			h1 -= a2;
 			h2 -= a1;
 			ans.pb(0);
 		}
 	}

 	cout<<ans.size()<<'\n';

 	for(auto x: ans){
 		if(x){
 			cout<<"HEAL\n";
 		}
 		else cout<<"STRIKE\n";
 	}
}