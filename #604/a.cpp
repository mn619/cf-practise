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
	string s;
	cin>>s;
	int n = s.size();
	string ans = "";
	fr(i, 0, n){
		if(i < n - 1 and s[i] != '?' and s[i + 1] != '?' and s[i] == s[i + 1]){
			cout<<-1<<'\n';
			return;
		}
		if(s[i] == '?'){
			bool b[3] = {0};
			if(i > 0){
				fr(j, 0, 3){
					if(s[i - 1] == 'a' + j) b[j] = 1;
				} 
			}
			if(i < n - 1){
				fr(j, 0, 3){
					if(s[i + 1] == 'a' + j) b[j] = 1;
				} 
			}
			fr(j, 0, 3){
				if(b[j] == 0){
					char c = 'a' + j;
					s[i] = c;
					break;
				}
			}
		}
	}
	cout<<s<<'\n';
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int t;
 	cin>>t;
 	while(t--) solv();
}