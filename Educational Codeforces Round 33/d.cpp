#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 100000000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int a[100011], pre[100011], n, d, mx[100011];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH


 	cin>>n>>d;
 	int ans = 0;

 	fr(i, 1, n + 1){
 		cin>>a[i];
 		pre[i] = pre[i - 1] + a[i]; 	
 	}

 	mx[n + 1] = -inf;
 	for(int i = n; i >= 1; i--){
 		mx[i] = max(mx[i + 1], pre[i]);
 	}
 	if(mx[1] > d) return cout<<-1, 0;

 	int add = 0, addsum = 0;
 	fr(i, 1, n + 1){
 		pre[i] = pre[i - 1] + a[i];
 		mx[i] += addsum;

 		if(a[i] == 0 and pre[i] < 0){
 			add =  max(-pre[i], d - mx[i]);
 			addsum += add;
 			pre[i] += add;
 			ans++;
 		}

 		if(pre[i] > d || (a[i] == 0 and pre[i] < 0)) return cout<<-1, 0;
 	}

 	cout<<ans;
}