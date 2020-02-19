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
	int n, m;
	cin>>n>>m;

	if(m == n - 1){
		cout<<n*(n + 1)/2 - 1<<'\n';
		return;
	}

	int k = (n - m)/(m + 1);
	int x = (n - m)%(m + 1);

	if(x == 0){
		int ans = n*(n + 1)/2 - (m + 1)*k*(k + 1)/2;
		cout<<ans<<'\n';
	}
	else{
		int ans = n*(n + 1)/2 - x*(k + 1)*(k + 2)/2 - (m + 1 - x)*k*(k + 1)/2;
		cout<<ans<<'\n';
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

    while(t--) solv();
}