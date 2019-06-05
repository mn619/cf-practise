#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int k, n;
vector <int> v[300001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;

 	fr(i, 1, n + 1){
 		int a, b;
 		cin>>a>>b;
 		v[i].pb(b);
 		v[i].pb(a);
 	}


 	sort(v + 1, v + n + 1);
 	reverse(v + 1, v + n + 1);


	int ans = 0;
	priority_queue<int> pq;
	int len = 0;

	fr(i, 1, n + 1){
		if(i <= k){
			pq.push(-v[i][1]);
			len += v[i][1];
		}
		else{
			int lmin = -pq.top();
			if(lmin < v[i][1]){
				pq.pop();
				len += v[i][1] - lmin;
				pq.push(-v[i][1]);
			}
		}

		ans = max(ans, len*v[i][0]);
	} 	

	cout<<ans;




}