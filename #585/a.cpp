#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int a1, a2, k1, k2, n;	
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>a1>>a2>>k1>>k2>>n;
 	if(k1 < k2){
 		swap(a1, a2);
 		swap(k1, k2);
 	}

 	int t2 = min(a2, n/k2);
 	int mx = t2 + max((int)0, min(a1, (n - t2*k2)/k1));
 	n -= a1*(k1 - 1) + a2*(k2 - 1);
 	int mn = max(n, (int)0);

 	cout<<mn<<" "<<mx<<'\n';		
}
