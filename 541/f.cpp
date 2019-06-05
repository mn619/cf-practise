#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, l[200001], r[200001], nex[200001];

int lef(int node)
{
	if(l[node] == node) return node;
	return l[node] = lef(l[l[node]]);
}

int rig(int node)
{
	if(r[node] == node) return node;
	return r[node] = rig(r[r[node]]);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i,1,n + 1)
 	{
 		l[i] = r[i] = i;
 	}

 	fr(i,1,n)
 	{
 		int x,y;
 		cin>>x>>y;
 		int lf = lef(y), ri = rig(x);
 		r[ri] = rig(lf);
 		l[lf] = lef(ri);
 		nex[ri] = lf;
 	}

 	int prev[n + 1] = {0};
 	fr(i,1,n + 1) prev[nex[i]] = i;
 	int st = 0;

 	fr(i,1,n + 1) if(nex[i]==0){st = i; break;}
 	while(prev[st] != 0) {cout<<st<<" "; st = prev[st];}
 	cout<<st<<'\n';

}