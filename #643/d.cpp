#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int n, s;
    cin>>n>>s;

    if(s < 2*n){
    	cout<<"NO\n";
    	return 0;
    }

    cout<<"YES\n";
    for(int i = 1; i <= n - 1; i++) cout<<1<<" ";
    cout<<s - (n - 1)<<'\n';
	cout<<n<<'\n';

}