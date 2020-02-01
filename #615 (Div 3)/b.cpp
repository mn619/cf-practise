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

bool comp(pair<int, int> p, pair<int, int> q){
	if(p.S != q.S) return p.S < q.S;
	return p.F < q.F;
}

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
    	pair <int, int> p[n + 1];
    	fr(i, 1, n + 1){
    		cin>>p[i].F>>p[i].S;
    	}
    	sort(p + 1, p + n + 1);
    	bool ok = 1;
    	fr(i, 1, n){
    		if(p[i].F != p[i + 1].F){
    			if(p[i].S > p[i + 1].S) ok = 0;
    		}
    	}

    	sort(p + 1, p + n + 1, comp);

    	fr(i, 1, n){
    		if(p[i].S != p[i + 1].S){
    			if(p[i].F > p[i + 1].F) ok = 0;
    		}
    	}

    	sort(p + 1, p + n + 1);

    	if(!ok){
    		cout<<"NO\n";
    	}
    	else{
    		cout<<"YES\n";
	    	int x = 0, y = 0;
	    	fr(i, 1, n + 1){
	    		while(x < p[i].F){
	    			cout<<"R";
	    			x++;
	    		}
	    		while(y < p[i].S){
	    			cout<<"U";
	    			y++;
	    		}
	    	}
	    	cout<<'\n';
    	}
    }
}