#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, k;

int sum(int x){
	return x*(x + 1)/2;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;

 	int l = 0, r = n, ans = 0;

 	while(l <= r){
 		int mid = (l + r)/2;
 		if(sum(n - mid) - mid == k){
 			ans = mid;
 			break;
 		}
 		
 		if(sum(n - mid) - mid < k){
 			r = mid - 1;
 		}
 		else l = mid + 1;

 	}

 	cout<<ans;
}