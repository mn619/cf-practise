#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, q;
int bit[1000001];

void update(int x, int val){
	while(x <= n){
		bit[x] += val;
		x += x&-x;
	}
}

int sum(int x){
	int ans = 0;
	while(x){
		ans += bit[x];
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

    cin>>n>>q;

    for(int i = 1; i <= n; i++){
    	int a;
    	cin>>a;
    	update(a, 1);
    }
    while(q--){
    	int k;
    	cin>>k;
    	if(k > 0){
    		update(k, 1);
    	}
    	else{
    		k = -k;
    		int l = 1, r = n, ans = n;

    		while(l <= r){
    			int mid = (l + r)>>1;
    			if(sum(mid) >= k){
    				ans = mid;
    				r = mid - 1;
    			}
    			else l = mid + 1;
    		}

    		update(ans, -1);
    	}
    }

    for(int i = 1; i <= n; i++){
    	if(sum(i) - sum(i - 1) >= 1) return cout<<i, 0;
    }
    cout<<0;
}