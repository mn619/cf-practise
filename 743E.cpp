#include<bits/stdc++.h>
#define inf 100000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


int n, a[1001], dp[1011][1<<8];
int cnt[8][1011];

int check(int len){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < (1<<8); j++){
			dp[i][j] = -inf;
		}
	}

	dp[0][0]= 0;

	for(int i = 0; i < n; i++){
		int x = a[i + 1];

		int l = i + 1, r = n, ind1 = n + 1, ind2 = n + 1;
		while(l <= r){
			int mid = (l + r)>>1;
			if(cnt[x][mid] - cnt[x][i] >= len - 1){
				ind1 = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		assert(ind1 > 0);

		l = i + 1, r = n;
		while(l <= r){
			int mid = (l + r)>>1;
			if(cnt[x][mid] - cnt[x][i] >= len){
				ind2 = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		assert(ind2 > 0);

		for(int j = 0; j < 1<<8; j++)
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

		for(int j = 0; j < (1<<8); j++){
			if(j>>x&1) continue;
			dp[ind1][j^(1<<x)] = max(dp[ind1][j^(1<<x)], dp[i][j] + len - 1);
			dp[ind2][j^(1<<x)] = max(dp[ind2][j^(1<<x)], dp[i][j] + len);
		}
	}

	return dp[n][255];
}

int main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;
    for(int i = 1; i <= n; i++) {
    	cin>>a[i];
    	a[i]--;
    	for(int j = 0; j < 8; j++) cnt[j][i] = cnt[j][i - 1];
    	cnt[a[i]][i]++;
    }

    int z = 0;
    for(int i = 0; i < 8; i++)
    	z += cnt[i][n] == 0;
    if(z){
    	cout<<8 - z<<'\n';
    	return 0;
    }
   
    int ans = 0;
    int l = 1, r = 125;
    while(l <= r){
    	int mid = (l + r)>>1;
    	int t = check(mid);
    	if(t > 0){
    		ans = t;
    		l = mid + 1;
    	}
    	else r = mid - 1;
    }

    cout<<ans<<'\n';
}