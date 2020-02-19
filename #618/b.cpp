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
int dist(int a, int b, int c, int d){
	return (a - c)*(a - c) + (b - d)*(b - d);
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int n;
    cin>>n;
    vector <int> x(n + 1), y(n + 1);

    fr(i, 1, n + 1){
    	cin>>x[i]>>y[i];
    }

    if(n&1) return cout<<"NO\n", 0;

    for(int i = 1; i <= n/2; i++){
    	int p1 = i, p2 = i + 1, p3 = p1 + n/2, p4 = (p2 + n/2);
    	if(p4 == n + 1) p4 = 1;

    	if((y[p2] - y[p1])*(x[p4] - x[p3]) != (y[p4] - y[p3])*(x[p2] - x[p1]) or dist(x[p1], y[p1], x[p2], y[p2]) != dist(x[p3], y[p3], x[p4], y[p4])) return cout<<"NO\n", 0;
    }

    cout<<"YES\n";
}