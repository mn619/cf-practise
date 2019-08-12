#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;


void solv(){
	string s, t, p;
	cin>>s>>t>>p;

	int cnt[26] = {0};

	for(int i = 0; i < p.size(); i++) cnt[p[i] - 'a']++;

	int ptr = 0;
	
	for(int i = 0; i < t.size(); i++){
		if(ptr < s.size() and s[ptr] == t[i]) ptr++;
		else cnt[t[i] - 'a']--;
	}

	if(ptr < s.size()) cout<<"NO\n";
	else{
		bool ok = 1;
		for(int i = 0; i < 26; i++) if(cnt[i] < 0) ok = 0;
			if(!ok) cout<<"No\n";
				else cout<<"YES\n";
	}


}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int q;
 	cin>>q;

 	while(q--) solv();
 	
}