#include<bits/stdc++.h>
#define inf 1000000000000000000
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


int a, b,	x, y;

void solv(){
	cin>>a>>b>>x>>y;
	x -= a, y -= b;
	
	// if(x == 0 or y == 0){
	// 	cout<<"1\n";
	// 	return;
	// }

	if(x > y) swap(x, y);
	
	int ans = x*(x + 1)/2 + (y - x)*x + x*(x - 1)/2 + 1;
	cout<<ans<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t = 1;
    cin>>t;

    while(t--) solv();
}