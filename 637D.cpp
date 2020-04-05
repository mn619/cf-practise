#include<bits/stdc++.h>
#define int long long
#define maxn 200000
#define inf 10000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m, s, d, a[maxn + 2], dp[maxn + 2];

signed main(){
	//FILEIO

	cin>>n>>m>>s>>d;
	if(d == 1) return cout<<"IMPOSSIBLE\n", 0;

	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a + 1, a + n + 1);
		
	queue <pair<int, int>> q;
	if(a[1] <= s){
		return cout<<"IMPOSSIBLE\n", 0;
	}

	q.push({a[1] - 1, 1});
	dp[1] = 1;

	for(int i = 2; i <= n; i++){
		
		if(a[i] - a[i - 1] - 2 >= s){
			q.push({a[i] - 1, i});
		}

		while(!q.empty() and a[i] + 1 - q.front().first > d){
			q.pop();
		}

		if(q.empty()){
			return cout<<"IMPOSSIBLE\n", 0;
		}
	
		dp[i] = q.front().second;
	}

	vector <pair<string, int>> ans;
	if(a[n] != m - 1)
		ans.push_back({"RUN", m - a[n] - 1});
	int pos = n;
	a[0] = -1;

	while(pos){
		ans.push_back({"JUMP", a[pos] - a[dp[pos]] + 2});
		ans.push_back({"RUN", a[dp[pos]] - a[dp[pos] - 1] - 2});
		pos = dp[pos] - 1;
	}

	reverse(ans.begin(), ans.end());

	for(auto x: ans){
		cout<<x.first<<" "<<x.second<<'\n';
	}

}
