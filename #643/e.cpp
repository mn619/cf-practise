#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, a, r, m, h[100001];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>a>>r>>m;
	vector <int> pre(n + 1);
    for(int i = 1; i <= n; i++){
    	cin>>h[i];
    	pre[i] = pre[i - 1] + h[i];
    }
    sort(h + 1, h + n + 1);
	int ans1 = (int) 100000000000000;
	for(int i = 1; i <= n; i++){
		int req = (i - 1)*h[i] - pre[i - 1] , rem = (pre[n] - pre[i]) - (n - i)*h[i];
		
		cout<<req<<" "<<rem<<'\n';
		
		int ans = 0;
		if(m <= a + r){
			if(rem > req){
				ans = (rem - req)*r + req*m;
			}
			else{
				ans = (req - rem)*a + rem*m;
			}
		}
		else{
			ans = rem*r + req*a;
		}

		ans1 = min(ans, ans1);
	}

	cout<<ans1<<'\n';
}