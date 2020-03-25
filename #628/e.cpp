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

vector <int> p;
int n, a[maxn];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    vector <bool> b(1000001, 0);

    for(int i = 2; i <= 1000000; i++){
    	if(!b[i]){
    		p.push_back(i);
			for(int j = i; j <= 1000000; j += i) b[j] = 1;
    	}
    }

	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	
}