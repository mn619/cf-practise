#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000
#define pii pair<int, int>

using namespace std;

int n, a1, a2, b1, b2;
string s, t;
set <int> a, b;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>s>>t;
 	for(auto x: s){
 		if(x == 'a')a1++;
 		else b1++;
 	}
 	
 	for(auto x: t){
 		if(x == 'a')a2++;
 		else b2++;
 	}	

 	if((a1 + a2)&1 or (b1 + b2)&1)return cout<<-1, 0;

 	fr(i, 0, n){
 		if(s[i] == t[i]) continue;
 		if(s[i] == 'a'){
 			a.insert(i);
 		}
 		else b.insert(i);
 	}

 	vector <pii> ans;

 	while(!a.empty() or !b.empty()){
 		if((a.size() == b.size()) and (a.size() == 1)){
 			int pos1 = *(a.begin()), pos2 = *(b.begin());
 			ans.pb({pos1, pos1});
 			ans.pb({pos1, pos2});
 			a.clear();
 			b.clear();
 			continue;
 		}
 		if(a.size() > b.size()){
 			auto it = a.begin();
 			auto it2 = it;
 			it2++;
 			ans.pb({*it, *it2});
 			a.erase(it);
 			a.erase(it2);
 			continue;
 		}
 		else {
 			auto it = b.begin();
 			auto it2 = it;
 			it2++;
 			ans.pb({*it, *it2});
 			b.erase(it);
 			b.erase(it2);
 			continue;
 		}
 	}

 	cout<<ans.size()<<'\n';
 	for(auto x: ans){
 		cout<<x.first + 1<<" "<<x.second + 1<<'\n';
 		swap(s[x.first], t[x.second]);
 	}

 	assert(s == t);
}