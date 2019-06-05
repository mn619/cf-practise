#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	
 	string s, t;
 	cin>>s>>t;
 	n = s.size();

 	int a = 0, b = 0, c = 0;
 	
 	fr(i, 0, n){
 		if(s[i] == '#'){
 			if(t[i] == '#') b++;
 			else a++;
 		}
 		else{
 			if(t[i] == '#'){
 				c++;
 			}
 		}
 	}

 	int x = a, y = b, z = c;
 	int d = n - a- b - c;
 		vector <string> v;
 		while(x--){
 			v.pb("#.");
 		}
 		while(y--){
 			v.pb("##");
 		}
 		while(z--){
 			v.pb(".#");
 		}
 		while(d--){
 			v.pb("..");
 		}

 	if(b > 0 || a == 0 || c == 0){
 		cout<<"YES\n";

 		fr(i, 0, n){
 			cout<<v[i][0];
 		}
 		cout<<'\n';
 		fr(i, 0, n){
 			cout<<v[i][1];
 		}
 	}
 	else cout<<"NO\n";
}