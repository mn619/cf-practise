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
	int o = 0, e = 0;
	fr(i, 1, n + 1){
		int a;
		cin>>a;

		if(a&1) o++;
		else e++;
	}

	if(o == 0){
		cout<<"NO\n";
		return ;
	}

	if(o&1){
		cout<<"YES\n";
	}
	else{
		if(e == 0) cout<<"NO\n";
		else cout<<"YES\n";	
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