#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define pii pair<int, int>
using namespace std;

int n, vcnt[100001], l[100001];
bool in[100001];

map<pair<int, int>, vector<int>>  ms;
map <int ,vector<int> > mf;


string s[100001];
set <char> vowel;

int cnt(string x){
	int len = x.size();

	int ans = 0;
	fr(i, 0, len){
		if(vowel.find(x[i]) != vowel.end()) ans++;
	}
	return ans;
}

int last(string x){
	int len = x.size();
	int ans = '$';
	fr(i, 0, len){
		if(vowel.find(x[i]) != vowel.end()) ans = x[i];
	}
	return ans - 'a';
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	vowel.insert('a');
 	vowel.insert('e');
 	vowel.insert('i');
 	vowel.insert('o');
 	vowel.insert('u');

 	fr(i, 1, n + 1){
 		cin>>s[i];
 		vcnt[i] = cnt(s[i]);
 		l[i] = last(s[i]);
 		mf[vcnt[i]].pb(i);

 		ms[{vcnt[i], l[i]}].pb(i);
 	}


 	vector<pair<int, int>> sec, fir;

 	for(auto x: ms){
 		vector<int> v = x.second;
 		int l = v.size();
 		for(int i = 0; i < l- 1; i += 2){
 			sec.pb({v[i], v[i + 1]});
 		}
 	}

 	for(auto x: mf){
 		vector<int> v = x.second;
 		int l = v.size();
 		for(int i = 0; i < l- 1; i += 2){
 			fir.pb({v[i], v[i + 1]});
 		}
 	}


 	int j = 0;
 	auto las = ms.begin();
 	vector<pair<pii, pii>> ans;

 	while(ok){
	 	for(auto xx: mf){
	 		vector<int> f = xx.second
		 	for(auto x: f){
		 		if(in[x.first] || in[x.second]) continue;

		 		int ans1 = 0, ans2 = 0;

		 		for(auto z = las; z!= ms.end(); z++){
		 			vector<int> v = (*z).second;
		 			for(auto y: v){
		 				if(!in[y] and y != x.first and y != x.second){
		 					if(ans1 != 0) {
		 						ans2 = y;
		 						
		 					}
		 					else ans1 = y;
		 				}
		 			}
		 			if(ans1 == 0|| ans2 ==  0) {las++; ans1 = ans2 = 0;}
		 			else break;
		 		}

		 		in[x.first] = in[x.second] = in[ans1] = in[ans2] = 1;
		 		if(ans1 == 0 || ans2 == 0) continue;
		 	}
	 	}
		ans.pb({{x.first, ans1},{x.second, ans2}});
 	}
 	cout<<ans.size()<<'\n';
 	for(auto x: ans){
 		cout<<s[x.first.first]<<" "<<s[x.first.second]<<'\n'<<s[x.second.first]<<" "<<s[x.second.second]<<'\n';
 	}
}