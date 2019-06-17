#include<bits/stdc++.h>
#define pb push_back
#define fr(i,a,b) for(int i=a;i<b;i++)
#define int long long 

using namespace std;

int n, p[150001];
map <int, vector<int> > m;

signed main()
{

 	cin>>n;

 	fr(i, 1, n + 1){
 		int a;
 		cin>>a;
 		p[i] = a; 
 		m[a].pb(i);
 	}

 	for(auto x: m){
 		int val = x.first;
 		vector<int> v = x.second;
 		sort(v.begin(), v.end());

 		int l = v.size();
 		for(int i = 0; i < l - 1; i += 2){
 			p[v[i]] = 0;
 			p[v[i + 1]] = 2*val;
 			m[2*val].pb(v[i + 1]);
 		}
 	}

 	vector<int> ans;
 	fr(i, 1, n + 1){
 		if(p[i])  ans.pb(p[i]);
 	}

 	cout<<ans.size()<<"\n";
 	for(auto x: ans) cout<<x<<" ";

}