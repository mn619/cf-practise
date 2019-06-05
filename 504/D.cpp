#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define inf 1000000007

using namespace std;
int n,q,a[200001] = {inf}, segtree[800001];


void buildtree(int l, int r, int node)
{
	if(l==r)
	{
		segtree[node] = a[l];
		return;
	}
	int mid = (l+r)/2;

	buildtree(l,mid,2*node);
	buildtree(mid+1,r,2*node+1);

	segtree[node] = min(segtree[2*node], segtree[2*node+1]);
}


int segmin(int l,int r, int lrange, int rrange, int node)
{
	if(l<=lrange && rrange<=r)return segtree[node];
	if(rrange<l || lrange>r) return inf;
	int mid = (lrange+rrange)/2;

	int temp1 = segmin(l , r, lrange, mid, 2*node);
	int temp2 = segmin(l, r, mid+1, rrange, 2*node+1);
	return min(temp1, temp2);
}

bool check()
{
	int Lqueri[q+1],Rqueri[q+1], i;

	fr(i,1,q+1) Lqueri[i] = -1, Rqueri[i] = -1;

	buildtree(1,n,1);

	fr(i,1,n+1)
	{
		if(a[i]!=inf)
		{
			if(Lqueri[a[i]]!=-1) Rqueri[a[i]] = i;
			else Lqueri[a[i]] = i;
		}
	}

	fr(i,1,q+1)
	{
		if(Rqueri[i]!=-1)
		{
			int min = segmin(Lqueri[i], Rqueri[i], 1, n, 1); 
			if(min<i)return false;
		}
	}
	return true;
}


signed main()
{
 	//start_routine
 	cin>>n>>q;
 	bool in[q+1] = {0};
 	int i;
 	fr(i,1,800001) segtree[i] = inf;
 	fr(i,1,n+1) {cin>>a[i]; if(a[i] == 0) a[i] = inf; else in[a[i]] = 1;}
 	

 	if(check()==0) return cout<<"NO\n",0;

 	priority_queue <int> pq;

 	fr(i,1,q+1)
 	{
 		if(!in[i]) {pq.push(i);}
 	}
 	
 	fr(i,1,n+1)
 	{
 		if(a[i] == inf)
 		{
 			int j;
 			fr(j,i+1,n+1)
 			{
 				if(a[j]!=inf)
 				{
 					j--; break;
 				}
 			}
 			if(pq.empty()) 
 			{
 				int k, val;
 				if(a[i-1]!=inf)val =a[i-1];
 				else val = a[j+1];
 				fr(k,i,j+1) a[k]=val;
 			}
 			else
 			{
	 			int val = pq.top(),k;
	 			in[val] = 1;
	 			fr(k,i,j+1) a[k]=val;
	 			pq.pop();
 			}
 			i=j;
 		}
 	}

 	if(in[q]==0)return cout<<"NO",0;
 	cout<<"YES\n";
 	fr(i,1,n+1)cout<<a[i]<<" ";

 	//end_routine
}



