#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int lcd(int a, int b){
	return a*b/__(a, b);
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int a, b;
 	cin>>a>>b;
 	if(a < b) swap(a, b);

 	int d = a - b;
 	int ans = 0, anslcm = lcm(a, b);

 	fr(i, 1, d + 1){
 		if(d%i == 0){
 			int j = a/i + (a%i != 0);
 			while(1){
 				int k = j*i - a;
 				if(lcm(a + k, b + k))
 			}
 		}
 	}	
}