#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	
	ll w[n];
	vector <ll> vw[n];
	ll vi[n],ve[n];
	
	for(int i=0;i<n;i++){cin>>w[i]; vw[i].pb(w[i]); vw[i].pb(i);}
	
	char a[2*n];
	int intro=0,extro=0;
	for(int i=0;i<2*n;i++)	
	{
		cin>>a[i];
		if(a[i]=='0')
		{
			vi[intro]=i;
			intro++;
		}
		else 
		{
			ve[extro]=i;
			extro++;
		}
	}
	ll ans[2*n];
	sort(vw,vw+n);
	//for(int i=0;i<n;i++){cout<<vw[i][0]<<" ";}
	//cout<<endl;
	intro=0; extro=0;
	stack <ll> s;
	
	for(int i=0;i<2*n;i++)
	{
		if(a[i]=='0')
		{
			ans[i]=vw[intro][1];
			intro++;
			s.push(ans[i]);
		}
		else
		{
			ans[i]=s.top();
			s.pop();
		}
	}
	
	for(int i=0;i<2*n;i++)cout<<ans[i]+1<<" ";
}


