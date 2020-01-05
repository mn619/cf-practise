#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define maxn 200000
#define int long long
#define mod 1000000007
#define inf 1000000000000000007

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace __gnu_pbds;
using namespace std;


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int n, m, inva[maxn + 1], b[maxn + 1];
ordered_set s[maxn + 1];

void update(int ind, bool in){
	int x = ind;
	while(x <= n){
		if(in) s[x].insert(b[ind]);
		else s[x].erase(b[ind]);
		x += x&-x;
	}
}


int queri(int la, int ra, int lb, int rb){
	int ans = 0, x = rb;
	while(x){
		ans += s[x].order_of_key(ra + 1) - s[x].order_of_key(la);
		x -= x&-x;
	}	
	x = lb - 1;
	while(x){
		ans -= s[x].order_of_key(ra + 1) - s[x].order_of_key(la);
		x -= x&-x;
	}
	return ans;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;
    fr(i, 1, n + 1){
    	int x;
    	cin>>x;
    	inva[x] = i;
    }

    fr(i, 1, n + 1){
    	cin>>b[i];
    	b[i] = inva[b[i]];
    	update(i, 1);
    }

    while(m--){
    	int t;
    	cin>>t;
    	if(t == 1){
    		int la, ra, lb , rb;
    		cin>>la>>ra>>lb>>rb;
    		cout<<queri(la, ra, lb, rb)<<'\n';
    	}
    	else{
    		int x, y;
    		cin>>x>>y;
    		update(x, 0);
    		update(y, 0);
    		swap(b[x], b[y]);
    		update(x, 1);
    		update(y, 1);
    	}
    }
}