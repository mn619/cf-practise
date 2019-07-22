#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

signed main()
{
 	FLASH

 	int tests;
 	cin>>tests;
 	
 	while(tests--){
 		int n, s, t;
 		cin>>n>>s>>t;
 		cout<<max(n - s, n - t) + 1<<'\n';
 	}	
}