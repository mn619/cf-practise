#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, r, avg, a[100001], b[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	priority_queue <pair<int, int>> pq;
 	cin>>n>>r>>avg;
 	int sum = 0;
 	fr(i, 1, n + 1){
 		cin>>a[i]>>b[i];
 		sum += a[i];
 		pq.push({-b[i], a[i]});
 	}

 	int ans = 0;

 	while(sum < avg*n){
 		int rem = min(n*avg - sum, r - pq.top().second);
 		sum += rem;
 		ans -= pq.top().first*rem;
 		pq.pop();
 	}

 	cout<<ans;
}