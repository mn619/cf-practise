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
#define double long double

using namespace std;

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int n;
    cin>>n;
    vector <int> a(n + 1), p_sum(n + 1),pref_min(n + 1);
    vector <double> ans(n + 1);

    fr(i, 1, n + 1){
    	cin>>a[i];
    	p_sum[i] = p_sum[i - 1] + a[i];
    	if(i == 1) pref_min[i] = a[i];
    	else pref_min[i] = min(a[i], pref_min[i]);
    }


    int i = 1;
    while(i <= n){
    	int las = i, ind = i;
    	double min_avg = a[i];


    	
    	for(int k = i; k <= ind; k++) ans[i] = min_avg;
    	i = ind + 1;
    }
    cout<<fixed<<setprecision(20);
    for(int i = 1; i <= n; i++) cout<<ans[i]<<" ";
}