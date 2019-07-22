#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[100001], queri;

vector<int> q[300001];
deque<int> dq;
pair<int, int> ans[300001];

void operat(){
	int t1 = dq.front();
	dq.pop_front();
	int t2 = dq.front();
	dq.pop_front();

	if(t1 > t2){
		dq.push_front(t1);
		dq.push_back(t2);
	}
	else{
		dq.push_front(t2);
		dq.push_back(t1);
	}
}

pair<int, int> find_(){
	int t1 = dq.front();
	dq.pop_front();
	int t2 = dq.front();
	dq.push_front(t1);

	return make_pair(t1, t2);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>queri;
 	int mx = 0, ind = 0;

 	fr(i, 1, n + 1){
 		cin>>a[i];
 		mx = max(mx, a[i]);
 	}

 	fr(i, 1, queri + 1){
 		int m;
 		cin>>m;
 		q[i].pb(m);
 		q[i].pb(i);
 	}


 	sort(q + 1, q + queri + 1);

 	int cnt = 1;
 	fr(i, 1, n + 1){
 		dq.push_back(a[i]);
 	}	

 	map<int,int> mp;

 	fr(i, 1, queri + 1){
 		while(cnt < min(n, q[i][0])){
 			cnt++;
 			operat();
 		}

 		if(dq.front() == mx){
	 		int temp = 0;
	 		dq.pop_front();
	 		
	 		while(!dq.empty()){
	 			
	 			mp[temp++] = dq.front();
	 			dq.pop_front();
	 		}
 			break;
 		}

 		ind = i;
 		ans[q[i][1]] = find_();
 	}

 	fr(i, ind + 1, queri + 1){
 		int m = q[i][0];
 		ans[q[i][1]] = {mx, mp[(m - cnt)%(n - 1)]};
 	}

 	fr(i, 1, queri + 1){
 		cout<<ans[i].first<<" "<<ans[i].second<<'\n';
 	}
	
}