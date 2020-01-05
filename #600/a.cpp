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
	int a[n + 1], b[n + 1];

	fr(i, 1, n + 1) cin>>a[i];
	fr(i, 1, n + 1) cin>>b[i];

	fr(i, 1, n + 1){
		a[i] = b[i] - a[i];
	}

	int l = 1, r = n;
	while(a[l] == 0 and l <= n) l++;
	while(a[r] == 0 and r >= 1) r--;

	if(l == n + 1){
		cout<<"YES\n";
		return;
	}

	bool ok = (a[l] > 0);

	fr(i, l + 1, r + 1){
		if(a[i] != a[l]) ok = 0;
	}


	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
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