#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int lef(int n){
	int ans = n%10;
	while(n){
		ans = n%10;
		n /= 10;
	}
	return ans;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int a, b;
 	cin>>a>>b;
 	fr(i, 1, 10000){
 		int x = lef(i), y = lef(i + 1);
 		if(x == a and y == b){
 			cout<<i<<" "<<i + 1<<'\n';
 			return 0;
 		}
 	}

 	cout<<-1;
 		
}