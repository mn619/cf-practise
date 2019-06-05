#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

const int N = 1000000;

set <int> s;

void compute(){
	int p = 2;
	while(p <= N){
		s.insert(p - 1);
		p *= 2;
	}
}

int n = N,source,end;
priority_queue <pair<int,int> > pq;
int dist[N + 1];
bool in[N + 1]={0};
int parent[N + 1]={0};//stores parent in the shortest path from source

void dij(int source)
{
	pq.push({0, source});
	for(int i = 1; i <= N; i++) dist[i] = inf, in[i]=0;
	dist[source] = 0;
	
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(in[u])continue;
		in[u]=1;
		
		for(int i = 0;i < 20;i++)
		{
			int v = ((u^((int) pow(2, i) - 1)) + 1);
			if(v > N) continue;
			if(dist[v] > dist[u] + 1 && !in[v] && dist[u] + 1 <= 40)
			{
				dist[v] = dist[u] + 1;
				pq.push({-dist[u] - 1, v}), parent[v] = u;
			}
		}
	}
}

signed main()
{
 	FLASH

 	compute();
 	cin>>source;
	
 	dij(source);
 	int end = 1; 
 	
 	for(auto x: s){
 		if(dist[x] < dist[end]){
 			end = x;
 		}
 	}


 	vector <int> ans;
 	int p = end;
 	
 	parent[source] = source;
 	p = end;

 	while(p != source){
 		int x = parent[p], y = p;
 		int pwr = 1, cnt = 0;

 		while(pwr <= 2*N){
 			if(((x^(pwr - 1)) + 1) == y){ans.pb(cnt); break;}
 			cnt++;
 			pwr *= 2;
 		}
 		p = parent[p];
 	}
	
	
 	reverse(ans.begin(), ans.end());
 	cout<<ans.size()*2<<'\n';
 	for(auto x: ans) cout<<x<<" ";
}
