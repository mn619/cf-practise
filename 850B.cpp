#include<bits/stdc++.h>
#define maxn 1000000
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, x, y, p[2000001], p1[2000001];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>x>>y;

    for(int i = 1; i <= n; i++){
    	int a;
    	cin>>a;
    	p[a]++;
    	p1[a] += a;
    }

    for(int i = 1; i <= 2*maxn; i++) p[i] += p[i - 1], p1[i] += p1[i - 1];

    int ans = (int)1000000000000000000;
    for(int i = 2; i <= maxn; i++){
    	int k = min(i - 1, x/y);
    	int ans1 = 0;
    	for(int j = i; j <= 2*maxn; j += i){
    		ans1 += (p[j - k - 1] - p[j - i])*x + ((p[j] - p[j - k - 1])*j - (p1[j] - p1[j - k - 1]))*y;
    	}
    	ans = min(ans, ans1);
    }

    cout<<ans<<'\n';
}