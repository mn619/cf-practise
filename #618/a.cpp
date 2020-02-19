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


signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH


    int n;
    cin>>n;

    vector <int> a(n), p(n), s(n);

    fr(i, 0, n){
    	cin>>a[i];
    	if(i > 0) p[i] = p[i - 1]|a[i];
    	else p[i] = a[i];
    }


    for(int i = n - 1; i >= 0; i--)
    	if(i == n - 1) s[i] = a[n - 1];
    	else s[i] = s[i + 1]|a[i];

    int ans = -1, ind = 0;

    for(int i = 0; i < n; i++){
    	int l = (i > 0)? p[i - 1] : 0, r = (i < n - 1)? s[i + 1] : 0;

    	if(s[0] - (l|r) > ans){
    		ans = s[0] - (l|r);
    		ind = i;
    	}
    }

    swap(a[ind], a[0]);
    for(auto x: a) cout<<x<<" "; 
}	