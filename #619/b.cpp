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

    int t;
    cin>>t;

    while(t--){
    	int n;
    	cin>>n;
    	int a[n + 1];
    	bool ok = 1;

    	int cursum = 0, sum = 0, l = 1, r = 1, maxsum = 0;
    	fr(i, 1, n + 1){
    		cin>>a[i];
    		cursum += a[i];
    		if(cursum <= 0){
    			l = i + 1;
    			cursum = 0;
    		}
    		if(maxsum < cursum){
    			r = i;
    			maxsum = cursum;
    		}
    		sum += a[i];
    	}

    	if(l != 1 or r != n or maxsum > cursum){
    		ok = 0;
    	}

    	if(ok)
    	cout<<"YES\n";
    	else cout<<"NO\n";
    }
}