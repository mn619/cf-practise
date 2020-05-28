#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, k, a[101];

vector <int> check(){
	set <int> s;
	vector <int> ans;
	for(int i = 0; i < n; i++){
		s.insert(a[i]);
	}
	if((int)s.size() > k) return ans;

	vector <int> dist;
	for(auto x: s) dist.push_back(x);
	while((int)dist.size() < k) dist.push_back(1);

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (int) dist.size(); j++) ans.push_back(dist[j]);
	}
	return ans;
}
void solv(){
	cin>>n>>k;
	for(int i = 0; i < n; i++) cin>>a[i];

	vector <int> ans = check();
	if(ans.size() == 0)
	cout<<"-1\n";
	else{
		cout<<ans.size()<<'\n';
		for(auto x: ans) cout<<x<<" ";
			cout<<'\n';
	}

}
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t;
    cin>>t;

    while(t--)  solv();

}