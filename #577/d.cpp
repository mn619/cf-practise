#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m;
set<pair<int,int>> s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	fr(i, 1, m + 1){
 		int a, b;
 		cin>>a>>b;
 		a--;
 		b--;
 		s.insert({a,b});
 		s.insert({b,a});
 	}

 	fr(i, 1, n){
 		if(n%i == 0){
 			bool ok = 1;
 			for(auto p: s){
 				int a = p.first, b = p.second;
 				a += i;
 				a %= n;
 				b += i;
 				b %= n;
 				if(s.find({a,b}) == s.end()){ok = 0; break;}
 			}
 			if(ok) return cout<<"Yes\n", 0;
 		}
 	}

 	cout<<"No";

}