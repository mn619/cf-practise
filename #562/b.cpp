#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

string s;
int ans[300001];
set<int> s0, s1;
vector <int> v0, v1;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>s;

 	int p0 = -1, p1 = -1;

 	fr(i, 0, s.size()){
 		if(s[i] == '0'){
 			for(int j = v0.size() - 1; j >= 0; j--){
 				int d = i - v0[j];
 				if(v0[j] - d < p0) break;
 				if(s0.find(v0[j] - d) != s0.end()){
 					ans[i] = v0[j] - d + 1;
 					p0 = v0[j] - d;
 					break;
 				}
 			}
 			v0.pb(i);
 			s0.insert(i);
 		}
 		else{
 			for(int j = v1.size() - 1; j >= 0; j--){
 				int d = i - v1[j];
 				if(v1[j] - d< p1) break;
 				if(s1.find(v1[j] - d) != s1.end()){
 					ans[i] = v1[j] - d + 1;
 					p1 = v1[j] - d;
 					break;
 				}
 			}
 			v1.pb(i);
 			s1.insert(i);
 		}
 	}

 	int p = 0, x = 0;
 	fr(i, 0, s.size()){
 		p = max(ans[i], p);
 		x += p;
 	}
 	cout<<x;
	 	
}