#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int s(int l, int r){
	return r*(r + 1)/2 - l*(l - 1)/2;
}

int n, x, d[2000001], pre[2000001], pre1[2000001];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>x;
    for(int i = 1;  i <= 2*n; i++){
    	if(i <= n)
    		cin>>d[i];
    	else d[i] = d[i - n];
    	pre[i] = pre[i - 1] + d[i];
    	pre1[i] = pre1[i - 1] + d[i]*(d[i] + 1)/2;
    }

    int ans = 0;
    for(int i = 1; i <= 2*n; i++){
    	int l = 0, r = i, ind = 0;

    	while(l <= r){
    		int mid = (l + r)>>1;
    		if(pre[i] - pre[mid] <= x){
    			ind = mid;
    			r = mid - 1;
    		}
    		else l = mid + 1;
    	}

    	int ans1 = pre1[i] - pre1[ind];
    	if(ind != 0){
    		int t = x - (pre[i] - pre[ind]);
    		assert(t <= d[ind]);
    		ans1 += s(d[ind] - t + 1, d[ind]);
    	}

    	ans = max(ans, ans1);
    }

    cout<<ans<<'\n';
}