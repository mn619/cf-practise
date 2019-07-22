#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000
 
using namespace std;
 
int n, a[maxn];
map <int, int> cnt;
 
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 
 	cin>>n;
 	bool ok = 0;
 	fr(i, 1, n + 1){
 		cin>>a[i];
 		cnt[a[i]]++;
 		if(cnt[a[i]] >= 2 and !ok) {ok = 1; continue;}
 		if(cnt[a[i]] >= 2 and ok) return cout<<"cslnb", 0;
 	}
 	if(cnt[0] >= 2){
 		return cout<<"cslnb", 0;
 	}
 
 	a[0] = -mod;
 
 	int sum = 0;
 	sort(a + 1, a + n + 1);
 
 	fr(i, 1, n){
 		if(a[i] == a[i + 1] and a[i - 1] == a[i] - 1){
 			return cout<<"cslnb", 0;
 		}
 	}
 	
 	fr(i, 1, n + 1){
 		sum += max((int)0, a[i] - i + 1);
 	}
 
 	if(sum&1){
 		cout<<"sjfnb";
 	}
 	else cout<<"cslnb";
}