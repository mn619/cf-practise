#include<bits/stdc++.h>
#define FLASH cin.tie(0); ios_base::sync_with_stdio(false);

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

vector <VI> ptr(601, VI(601, -1));
void rec(int i, int j){
	int k = ptr[i][j];
	assert(k != -1);

	cout<<'(';
	if(ptr[i][j] > i)
		rec(i + 1, k);
	cout<<')';
	if(ptr[i][j] < j)
		rec(k + 1, j);
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int n;
    cin>>n;

    VI l(n), r(n);

    fr(i, 0, n) cin>>l[i]>>r[i];

    vector<vector<bool>> dp(n, vector<bool>(n, 0));

    for(int len = 0; len < n; len++){
    	for(int i = 0; i + len < n; i++){
    		int j = i + len;
    		if(len == 0)
    			dp[i][j] = (l[i] == 1), ptr[i][j] = (l[i] == 1)? i : -1;
    		else if(dp[i][i] and dp[i + 1][j])
    			dp[i][j] = 1, ptr[i][j] = i;
    		else if(dp[i + 1][j] and l[i] <= 2*len + 1 and 2*len + 1 <= r[i])
	    			dp[i][j] = 1, ptr[i][j] = j;
    		else
	    		for(int k = i + 1; k < j; k++)
	    			if(dp[i + 1][k] and dp[k + 1][j] and l[i] <= 2*(k - i) + 1 and 2*(k - i) + 1 <= r[i])
	    				dp[i][j] = 1, ptr[i][j] = k;
    	}
    }

    if(!dp[0][n - 1]) cout<<"IMPOSSIBLE\n";
	else
		rec(0, n - 1);
}