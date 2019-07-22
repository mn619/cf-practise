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

 	int n;
 	cin>>n;

 	fr(i, 1, n + 1){
 		string s, t;
 		cin>>s>>t;
 		s += '&';
 		t += '&';

 		string x = "", y = "";
 		fr(i, 0, s.size()){
 			if(i == 0){
 				x += s[0];
 			}
 			else if(s[i] != s[i - 1]) x += s[i];
 		}
 		fr(i, 0, t.size()){
 			if(i == 0){
 				y += t[0];
 			}
 			else if(t[i] != t[i - 1]) y += t[i];
 		}

 		if(x != y){
 			cout<<"NO\n";
 			continue;
 		}

 		vector <int> cnt1, cnt2;
 		char las = s[0];
 		int cnt = 1;
 		fr(i, 1, s.size()){
 			if(s[i] != s[i - 1]){
 				cnt1.pb(cnt);
 				cnt = 1;
 			}
 			else cnt++;
 		}

 		las = t[0];
 		cnt = 1;

 		fr(i, 1, t.size()){
 			if(t[i] != t[i - 1]){
 				cnt2.pb(cnt);
 				cnt = 1;
 			}
 			else cnt++;
 		}

 		bool ok = 1;
 		fr(i, 0, cnt1.size()){
 			if(cnt1[i] > cnt2[i]){
 				ok = 0;
 				break;
 			}
 		}

 		if(!ok) cout<<"NO\n";
 		else cout<<"YES\n";
 	}	

}