#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int a, b, c, d;

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>a>>b>>c>>d;

    int ans = 0;
    for(int i = c; i <= d; i++){
    	int x0 = i - b; // x <= x0
    	if(x0 < a) continue;
    	if(x0 <= b) {
			int diff = min(x0 - a, c - b);
			ans += (diff + 1)*(x0 - a + 1) - (diff + 1)*diff/2; 	
    	}
    	else{
    		int diff = min(x0 - b, c - b);
    		ans += (b - a + 1)*(diff + 1);
    		int y0 = x0 +  1;
    		if(y0 > c) continue;
    		diff = min(b - 1 - a, c - y0);
    		assert((diff + 1)*(b - a) - diff*(diff + 1)/2 >= 0);
    		ans += (diff + 1)*(b - a) - diff*(diff + 1)/2;
    	}
    }

    ans = (b - a + 1)*(c - b + 1)*(d - c + 1) - ans;
    cout<<ans<<'\n';
}