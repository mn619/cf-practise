#include<bits/stdc++.h>
#define int long long
#define inf 1000000000
#define maxn 200000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, a[maxn + 1];

vector <int> d(maxn + 1, inf);
vector <int> pwr[maxn + 1];
vector <bool> in(maxn + 1, 0);
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    for(int i = 2; i <= maxn; i++){
    	if(d[i] == inf){
    		d[i] = i;
    		for(int j = i*i; j <= maxn; j += i){
    			d[j] = min(d[j], i);
    		}
    	}
    }	


    cin>>n;
    for(int i = 1; i <= n; i++) {cin>>a[i]; in[a[i]] = 1;}

    for(int i = 1; i <= n; i++){
    	int temp = a[i];
    	while(temp > 1){
    		int c = 0;
    		int p = d[temp];

    		while(temp%p == 0){
    			temp /= p;
    			c++;
    		}
    		pwr[p].push_back(c);
    	}
    }


    int ans = 1;
    for(int i = 2; i <= maxn; i++){
    	if((int)pwr[i].size() < n - 1) continue;
    	sort(pwr[i].begin(), pwr[i].end());
    	int t = 0;
    	if((int)pwr[i].size() == n - 1){
    		t = pwr[i][0];
    	}
    	else t = pwr[i][1];
    	while(t--) ans *= i;
    }

    cout<<ans<<'\n';
}