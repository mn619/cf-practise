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

 	int a, b, c, d;
 	cin>>a>>b>>c>>d;
 	if(b < a or c < d) return cout<<"NO\n", 0;

 	string s1 = "", s2 = "", s3 = "";
 	while(a > 0){
 		s1 += "0 1 ";
 		a--;
 		b--;
 	}
 	while(d > 0){
 		s3 += "2 3 ";
 		c--;
 		d--;
 	}

 	if(abs(b - c) > 1){
 		return  cout<<"NO\n", 0;
 	}

 	while(min(b, c) > 0){
 		s2 += "2 1 ";
 		c--;
 		b--;
 	}
 	string ans = "";

 	if(b) ans += "1 ";
 	ans += s1;
 	ans += s2;
 	ans += s3;
 	if(c) ans += "2";
 	cout<<"YES\n";
 	cout<<ans<<'\n';
}