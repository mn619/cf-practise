#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int q;
 	cin>>q;
 	while(q--){
 		std::vector<int> a(3);
 		cin>>a[0]>>a[1]>>a[2];
 		int ans = (int)inf*10;
 		fr(i, 0, 27){
 			std::vector <int> b = a;
 			int mask = i, bit = 0;
 			while(bit < 3){
 				if(mask%3 == 2) b[bit]++;
 				else if(mask%3 == 0) b[bit]--;
 				bit++;
 				mask /= 3;
 			}
 			ans = min(ans, abs(b[0] - b[1]) + abs(b[1] - b[2]) + abs(b[0] - b[2]));
 		}
 		cout<<ans<<'\n';
 	}	

}