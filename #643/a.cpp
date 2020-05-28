#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


void solv(){
	int a, k;
	cin>>a>>k;

	for(int i = 2; i <= k ; i++){
		int mn= 10, mx = 0;
		int temp = a;
		while(temp){
			mn = min(mn, temp%10);
			mx = max(mx, temp%10);
			temp /= 10;
		}

		a = a + mn*mx;
		if(mn == 0){
			cout<<a<<'\n';
			return;
		}
	}

	cout<<a<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t;
    cin>>t;
    while(t--) solv();
}