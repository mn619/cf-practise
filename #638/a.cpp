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

    int t;
    cin>>t;
	int p[31] = {1};
	for(int i = 1; i < 31; i++) p[i] = 2*p[i - 1];

    while(t--){
    	int n;
    	cin>>n;
    	int a = p[n], b = 0;
    	for(int i = 1; i < n/2; i++) a += p[i];
    	for(int i = n/2; i < n; i++) b += p[i];
    	cout<<a - b<<'\n';
    }
}