#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int k;
string s;

bool palindrome(string x){
	fr(i, 0, x.size()) if(x[i] != x[x.size() - i - 1]) return 0;
	return 1;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>k>>s;

 	queue<int> q;

 	for(int i = k - 1; i >= 0; i--){
 		bool ok = 0;
 		fr(j, 0, s.size()){
 			if(s[j] - 'a' == i) {ok = 1; break;}
 		}
 		if(!ok) q.push(i);
 	}
 	int l = s.size();

 	for(int i = (l - 1)/2; i >= 0; i--){
 		if(q.empty()){
 			if(s[i] == '?' and s[l - i - 1] != '?') s[i] = s[l - i - 1];
 			else if(s[i] == '?') {s[i] = 'a'; s[l - i - 1] = 'a';}
 		}
 		else if(s[i] == '?' and s[l - i - 1] == '?'){
 			s[i] = q.front() + 'a';
 			s[l - i - 1] = 'a'  + q.front();
 			q.pop();
 		}
 		else if(s[i] == '?'){
 			s[i] = s[l - i - 1];
 		}
 	}
 	fr(i, (l + 1)/2, l){
 		if(s[i] == '?') s[i] = s[l - i - 1];	
 	}
 	if(!q.empty() || !palindrome(s)) cout<<"IMPOSSIBLE";
 	else cout<<s;
}