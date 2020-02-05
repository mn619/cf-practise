#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, k, dist[maxn];
vector <int> v[maxn];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>k;
    fr(i, 1, n){
    	int a, b;
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
    }

    queue <int> q;
    fr(i, 1, n + 1){
    	dist[i] = inf;
    	if(v[i].size() == 1){
    		dist[i] = 0;
    		q.push(i);
    	}
    }


    while(!q.empty()){
    	int node = q.front();
    	q.pop();
    	for(auto x: v[node]){
    		if(dist[x] > dist[node] + 1){
    			dist[x] = dist[node] + 1;
    			q.push(x);
    		}
    	}
    }

    int center;
    bool found = 0;
    fr(i, 1, n + 1){
    	if(dist[i] == k){
    		if(found){
	    		cout<<"No\n";
	    		exit(0);
    		}
    		else {
    			found = 1;
    			center = i;
    		}
    	}
    }

    if(!found){
    	cout<<"No\n";
    	exit(0);
    }

    bool ok = 1;
    q.push(center);
    fr(i, 1, n + 1)
    	ok &= ((i == center or (v[i].size() > 3 or dist[i] == 0)) and (i != center or v[i].size() >= 3)),
    	dist[i] = inf;

    dist[center] = 0;

    while(!q.empty()){
    	int node = q.front();
    	q.pop();
    	for(auto x: v[node]){
    		if(dist[x] > dist[node] + 1){
    			dist[x] = dist[node] + 1;
    			q.push(x);
    		}
    	}
    }

    fr(i, 1, n + 1){
    	ok &= ((v[i].size() == 1 or dist[i] < k) and (v[i].size() > 1 or dist[i] == k) );
    }


    if(ok) cout<<"Yes\n";
    else cout<<"No\n";
}