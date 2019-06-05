#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

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
 		string s;
 		cin>>s;

 		int n = s.size();

 		int cnt[26] = {0};

 		fr(i, 0, n ){
 			cnt[s[i] - 'a']++;
 		}

 		string ans1 = "", ans2 = "";
 		int e = 0, o = 0;

 		for(int i = 0; i < 26; i += 2){
 			if(cnt[i]) e++;
 			while(cnt[i]--){
 				ans1 += 'a' + i;
 			}
 		}

 		for(int i = 1; i < 26; i += 2){
 			if(cnt[i]) o++;
 			while(cnt[i]--){
 				ans2 += 'a' + i;
 			}
 		}

 		bool ok = 1;
 		string ans = ans1 + ans2;
 		fr(i, 1, n){
 			if(abs(ans[i] - ans[i - 1]) == 1)ok = 0; 
 		}

 		if(ok){
 			cout<<ans<<'\n';
 			continue;
 		}

 		ans = ans2 + ans1;
 		ok = 1;
 		fr(i, 1, n){
 			if(abs(ans[i] - ans[i - 1]) == 1)ok = 0; 
 		}

 		if(!ok) cout<<"No answer\n";
 		else cout<<ans<<'\n';
 	}
}