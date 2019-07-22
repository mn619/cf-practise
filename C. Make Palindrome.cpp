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

 	string s;
 	cin>>s;
 	int n = s.size();
 	int cnt[26] = {0};
 	
 	fr(i, 0, n){
 		cnt[s[i] - 'a']++;
 	}
	
	int odd = 0;
 	fr(i, 0, 26) odd += (cnt[i]&1); 
 	
	bool ok = !(n&1);
	odd -= (!ok);
	int cur = 0;

 	for(int i = 0; i < 26; i++){
		if(cnt[i]&1){
			if(cur < odd/2) cnt[i]++, cur++;
			else if(cur == odd/2 and (n&1)){cur++; continue;}
			else cnt[i]--;
		}	 			
 	}

 	char x;
 	if(n&1) fr(i, 0, 26) {if((cnt[i]&1)) {x = (char) i + 'a'; cnt[i]--; break;}}
 	
 	fr(i, 0, 26){
 		int t = cnt[i]/2;
 		assert(t >= 0);

 		while(t--) cout<<(char)(i + 'a');
 		cnt[i] -= cnt[i]/2;
 	}
 	
 	if(n&1) cout<<(char) x;

 	for(int i = 25; i >= 0; i--){

 		while(cnt[i]--){
 			cout<<(char)(i + 'a');
 		}
 	}
}