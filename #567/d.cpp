#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, q;
int cnt[500001], ans[500001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n>>m>>q;
	int mx = 0;

	fr(i, 1, n + 1){
		int a;
		cin>>a;
		cnt[a]++;
		mx = max(mx, cnt[a]);
	} 	

	vector<int> queri[q + 1];

	fr(i, 1, q + 1){
		int x;
		cin>>x;
		queri[i].pb(x);
		queri[i].pb(i);
	}

	sort(queri + 1, queri + q + 1);
	int las = n;
	int d = 0;
	fr(i, 1, m + 1){
		d += mx - cnt[i];
	}
	int k = n + d;

	priority_queue<pair<int,int>> pq;
	fr(i, 1, m + 1){
		pq.push({-cnt[i], -i});
	}

	fr(i, 1, q + 1){
		int yr = queri[i][0];
		if(yr > k){
			ans[queri[i][1]] = (yr - k)%m + m*((yr - k)%m == 0);
			continue;
		}
		else{
			if(las == yr){
					ans[queri[i][1]] = ans[queri[i - 1][1]];
			}
			else
			while(las < yr){
				auto p = pq.top();
				pq.pop();
				int q = -pq.top().first;
				int d = min(yr - las, q - (-p.first));
				if(d == 0){
					pq.push({p.first - 1, p.second});
					las++;
				}
				else{
					las += d;
					pq.push({p.first - d, p.second});
				}
				if(las == yr){
					ans[queri[i][1]] = -p.second;
				}
			}
		}
	}

	fr(i, 1, q + 1) cout<<ans[i]<<'\n';
}