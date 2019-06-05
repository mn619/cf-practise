#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	//cout<<"hello";
	ll a[n];
	map <ll,vector<ll> > m;
	//cout<<"hello";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		m[a[i]].pb(i);
	}
	map <ll,vector<ll> >::iterator it;
	map <ll,vector<ll> >::iterator it1;
	it=m.begin();
	
	//cout<<"hello";
	do
	{
		map <ll,vector<ll> >::iterator it2=m.begin();
		
		
		bool b=1;
				
		for(int i=0;i<it->second.size()-1;i+=2)
		{
			m[2*it->first].pb(it->second[i+1]);
		}
		
		
		if(it->second.size()%2) b=0;
		if(b)
		{
			if(it!=m.end())
			{
				it2=it;
				it2++;
				//cout<<"\nit2 is "<<it2->first<<"\n";
				m.erase(it);
				it=it2;
			}
			else {m.erase(it); break;}
		}
		else 
		{
				if(it==m.end())break;
				else it++;
		}
		//cout<<it->first<<" "<<it->second.size()<<"\n";
	}
	while(it!=m.end());
	
	it=m.begin();
	vector <ll> v[m.size()];
	for(int i=0;i<m.size();i++)
	{
		
		v[i].pb(it->second[it->second.size()-1]);
		v[i].pb(it->first);
		it++;
	}
	
	sort(v,v+m.size());
	cout<<m.size()<<endl;
	for(int i=0;i<m.size();i++)
	{
		cout<<v[i][1]<<" ";
	}
}


