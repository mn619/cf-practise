#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m;
vector <int> v[200001];
vector <pair<int, bool>> comp;
vector <int> clr(200001, -1), ans(200001, -1);
bool vis[200001];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH
    cin>>n>>m;

    for(int i = 1; i <= m; i++){
    	int a, b;
    	cin>>a>>b;
    	v[a].push_back(b);
    	v[b].push_back(a);
    }

    

    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += ans[i];
    cout<<cnt<<'\n';
	for(int i = 1; i <= n; i++){
		if(ans[i]) cout<<'A';
		else cout<<'E';
	}
}