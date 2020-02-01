#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 300000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, m, a[maxn + 1];
vector <int> v[maxn + 1];
vector<bool> b(maxn + 1);

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;
    fr(i, 1, n + 1){
    	v[i].pb(n - i + 1);
    }

    fr(i, 1, m + 1){
    	cin>>a[i];
    	b[a[i]] = 1;
    	v[a[i]].pb(n + i);
    }

    fr(i, 1, n + 1){
    	int mn = (b[i] + !(b[i])*i), mx = v[i][0];
    	cout<<v[i][0]<<" ";
    	fr(j, 1, (int)v[i].size()){
    		cout<<v[i][j]<<" ";
    		mx = max(mx, v[i][j] - v[i][j - 1]);
    	}
    	cout<<mn<<" and "<<mx<<'\n';
    }
}
