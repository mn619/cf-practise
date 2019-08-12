#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mid 500000000

using namespace std;

int cnt[2];
set<pair<int, int> > s;

void dfs(int x, int y){
	bool b = (x + y)&1;
	cnt[b]--;
	s.insert({x, y});
	if(cnt[!b] > 0 and !s.count({x - 1, y})) dfs(x - 1, y);
	if(cnt[!b] > 0 and !s.count({x + 1, y})) dfs(x + 1, y);
	if(cnt[!b] > 0 and !s.count({x, y - 1})) dfs(x, y - 1);
	if(cnt[!b] > 0 and !s.count({x, y + 1})) dfs(x, y + 1);
}


void solv(){
	cin>>cnt[1]>>cnt[0];
	int l = cnt[0] + cnt[1];

	dfs(mid, mid);

	if(s.size() < l){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
		for(auto x: s){
			cout<<x.first<<" "<<x.second<<'\n';
		}
	}
	s.clear();
}

signed main()
{
 	int q;
 	cin>>q;
 	while(q--)solv();
}