#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 1000000

using namespace std;

string s;
int pre[maxn + 10], suf[maxn + 10];
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>s;
 	int n = s.size();

 	reverse(s.begin(), s.end());
 	s += '%';
 	reverse(s.begin(), s.end());


 	fr(i, 1, n + 1){
 		pre[i] = pre[i - 1];
 		if(s[i] == 'v' and s[i - 1] == 'v')
 			pre[i]++;
 	}

 	for(int i = n - 1; i >= 1; i--){
 		suf[i] = suf[i + 1];
 		if(s[i] == 'v' and s[i + 1] == 'v')
 			suf[i]++;	
 	}



 	int ans = 0;
 	fr(i, 1, n + 1){
 		if(s[i] == 'o'){
 			ans += pre[i - 1]*suf[i + 1];
 		}
 	}

 	//fr(i, 1, n + 1) cout<<pre[i]<<" ";

 	cout<<ans;
}