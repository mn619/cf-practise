#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a1,b1,c1,a2,b2,c2;
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	
	if((a1==0 && b1==0)||(a2==0 &&b2==0))
	return cout<<0<<"\n",0;
	
	if(a1*b2-b1*a2==0)
	{
		if(a1==0 && a2==0)
		{
			if(b2*c1-c2*b1==0)cout<<-1<<"\n";
			else cout<<0;
		}
		else if(b1==0 && b2==0)
		{
			if(a2*c1-a1*c2==0)cout<<-1<<"\n";
			else cout<<0<<"\n";
		}
		else if(c1==0 && c2==0)
		{
			if(a2*b1-b2*a1==0)cout<<-1<<"\n";
			else cout<<0<<"\n";
		}
		else if(b1*c2-c1*b2==0)cout<<-1<<"\n";
		else cout<<0<<"\n";
		
	}
	else cout<<1<<"\n";
}

