#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 40000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

vector <int> d[maxn + 1];

void solv(){
	int a, b, c;
	cin>>a>>b>>c;

	int ans = inf;
	int A, B, C;

	for(int i = 1; i <= maxn; i++){
		int a1, b1 = i, c1;
		int mna1 = inf, mnc1 = inf;

		for(auto x: d[i]){
			if(mna1 > abs(a - x)){
				mna1 = abs(a - x);
				a1 = x;
			}
		}

		for(int j = i; j <= maxn; j += i){
			if(mnc1 > abs(c - j)){
				mnc1 = abs(c - j);
				c1 = j;
			}
		}

		if(abs(a - a1) + abs(b - b1) + abs(c - c1) < ans){
			ans = abs(a - a1) + abs(b - b1) + abs(c - c1);
			A = a1, B = b1, C = c1;
		}
	}

	cout<<ans<<'\n'<<A<<" "<<B<<" "<<C<<"\n";

}
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    for(int i = 1; i <= maxn; i++)
    	for(int j = i; j <= maxn; j += i)
    		d[j].pb(i);
    	
    
    int t;
    cin>>t;

    while(t--) solv();
}