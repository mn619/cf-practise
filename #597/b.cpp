#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int t;
 	cin>>t;
 	while(t--){
 		int n, a, b, c, x = 0, y = 0, z = 0, ans = 0;
 		string s;

 		cin>>n>>a>>b>>c>>s;
 		string anss = s;
 		vector <int> r, p, sc;

 		fr(i, 0, n){
 			anss[i] = '*';
 			if(s[i] == 'R') {x++; r.pb(i);}
 			else if(s[i] == 'P') {p.pb(i);y++;}
 			else {sc.pb(i);z++;}
 		}
 		int t = min(x, b);
 		ans += t;
 		t = min(y, c);
 		ans += t;
 		t = min(z, a);
 		ans += t;

 		if(ans*2 >= n){
 			cout<<"yes\n";
 			for(auto i: r){
 				if(b > 0) {anss[i] = 'P'; b--;}
 			}
 			for(auto i: p){
 				if(c > 0){anss[i] = 'S'; c--;}
 			}
 			for(auto i: sc){
 				if(a > 0){anss[i] = 'R'; a--;}
 			}	
 			
 			fr(i, 0, n){
 				if(anss[i] == '*'){
 					if(a > 0){
 						cout<<"R";
 						a--;
 					}
 					else if(b > 0){
 						cout<<"P";
 						b--;
 					}
 					else {cout<<"S"; c--;}
 				}
 				else cout<<anss[i];
 			}
 			cout<<'\n';
 		}
 		else cout<<"no\n";	
 	}	
}