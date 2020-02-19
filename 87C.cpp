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

int n, dp[maxn];

vector <int> bit(maxn, 0);
void update(int x, int val){    	
	while(x <= n){
		bit[x] ^= val;
		x += x&-x; 
	}
}

int query(int x){
	int ans = 0;
	while(x){
		ans ^= bit[x];
		x -= x&-x;
	}
	return ans;
}

int mex(vector <int> v){
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	v.pb(inf);

	int i = 0;
	while(v[i] == i) i++;
	return i;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;
    
    fr(i, 3, n + 1){
		vector<int> v;
    	for(int j = 2; j*(j + 1)/2 <= i; j++){
    		if((2*i - j*(j + 1))%(2*j) != 0) continue;

			int l = (2*i - j*(j + 1))/(2*j) + 1;
			int r = l + j - 1;
			v.pb(query(r)^query(l - 1));
    	}

		dp[i] = mex(v);
		update(i, dp[i]);
    }


    if(!dp[n])
    	cout<<"-1\n";
    else{
    	for(int j = 2; j*(j + 1)/2 <= n; j++){
    		if((2*n - j*(j + 1))%(2*j) != 0) continue;

    		int l = (2*n - j*(j + 1))/(2*j) + 1;
			int r = l + j - 1;

			if((query(r)^query(l - 1)) == 0)
				return cout<<j<<'\n', 0;
    	}
    }
}
// (x + j)*(x + j + 1)/2 - x*(x + 1)/2
// 1/2(x*x + 2*x*j + j*j + x + j - x*x - x)
// 1/2(2*x*j + j*j + j) = i
// 2*x*j + j*(j + 1) = 2*i
// x = (2*i - j*(j + 1))/(2*j)
// x = i/j - (j + 1)/2