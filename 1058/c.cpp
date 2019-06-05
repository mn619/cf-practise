#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n;
 	cin>>n;

 	int a[n + 1], sum = 0;

 	fr(i, 1, n + 1){
 		char c;
 		cin>>c;
 		a[i] = c - '0';
 		sum += a[i];
 	}
 	if(sum == 0) return cout<<"YES", 0;
 	
 	fr(i, 1, sum){
 		if(sum%i == 0){
 			int sum1 = 0;
 			bool ok = 1;
 			fr(j, 1, n + 1){
 				if(sum1 + a[j] > i) ok = 0;
 				sum1 += a[j];
 				sum1%=i;
 			}
 			if(ok) return cout<<"YES", 0;
 		}
 	}
 	cout<<"NO";

}