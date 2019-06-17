#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

ll gcd(ll p,ll q)
{
	if(q==0)return p;
	else return gcd(q,p%q);
}

int main()
{
	SPEED;
	cout<<gcd(123456,1234);
	int n;
	cin>>n;
	ll p,q,b;
	
	for(int i=0;i<n;i++)
	{
		string  ans="Infinite\n";
		cin>>p>>q>>b;
		
		q=q/gcd(p,q);
		if(q==1||p==0){
			cout<<"Finite\n";
			continue;
		}
		
		b=gcd(q,b);
		while(b!=1)
		{
		//cout<<q<<"\t"<<gcd(q,b)<<endl;
		//cout<<k<<endl;
			while(q%b==0)
			{
				q=q/b;
			}
			
			if(q==1)
			{
				ans="Finite\n"; break;
			}
			b=gcd(q,b);	
		}
		
	cout<<ans;
	
	}
}

