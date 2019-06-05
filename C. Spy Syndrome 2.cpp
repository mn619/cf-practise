#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
const int p = 101;

int n, m, h[10001], dp[10001];
string s;

map <int, string> mp;

set <int> w;

void compute_hash(){
	int pwr = 1;
	fr(i, 0, s.size()){
		h[i] = + s[i]*pwr;
		if(i > 0)h[i] += h[i - 1];
		h[i] %= mod;		
		pwr *= p;
		pwr %= mod;
	}  
}

string lower(string x){
	fr(i, 0, x.size()){
		if(65 <= x[i] and x[i] <= 90) x[i] = x[i] + 'a' - 'A';
	}
	return x;
}

int _hash(string x){
	int pwr = 1, res = 0;
	fr(i, 0, x.size()){
 		res += x[i]*pwr;
 		pwr *= p;
 		pwr %= mod;
 		res %= mod;
	}
	return res;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>s;

 	compute_hash();
 	cin>>m;

 	while(m--){
 		string  x;
 		cin>>x;

 		reverse(x.begin(), x.end());
 		string l = lower(x);
 		mp[_hash(l)] = x;
 	}

 	fr(i, 0, s.size()){
 		int h = 0;
 		fr(j, 0, 1000){

 			if(i - j < 0) break;
 			h += s[i - j];
 			h %= mod;
 			if(mp.count(h)){
 				if(i == j){
 					dp[i] = h;
 					break;
 				}
 				else if(dp[i - j - 1] != 0){
 					dp[i] = h;
 					break;
 				}
 			}
 			h *= p;
 			h %= mod;
 		}
 	}

 	int cur = n - 1;
 	stack <string> ans;

 	while(cur >= 0){
 		string x = mp[dp[cur]];
 		reverse(x.begin(), x.end());
 		ans.push(x);
 		cur -= x.size();
 	}
 
 	while(!ans.empty()){
 		cout<<ans.top()<<" ";
 		ans.pop();
 	}
}
