#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

void solv(){
	int n;
	cin>>n;

	vector <int> a(n + 2);
	for(int i = 1; i <=n; i++){
		cin>>a[i];
	}

	int mn = inf, mx = -inf;
	for(int i = 1; i <= n; i++){
		if(a[i] == -1){
			if(i - 1 > 0 and a[i - 1] != -1) mn = min(mn, a[i - 1]), mx = max(mx, a[i - 1]);
			if(i + 1 <= n and a[i + 1] != -1) mn = min(mn, a[i + 1]), mx = max(mx, a[i + 1]);
		}
	}

	int k = (mn + mx)/2;
	int m = -inf;
	for(int i = 1; i <= n; i++){
		if(a[i] == -1) a[i] = k;
		if(i > 1) m = max(m, abs(a[i] - a[i - 1]));
	}

	cout<<m<<" "<<k<<'\n';
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