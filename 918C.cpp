#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	string s;
	cin>>s;
	int n=s.size();
	
	ll ans=0;
	
	for(int i=0;i<n;i++)
	{
		int l=0,r=0,x=0;
		int ans0=0;
		if(s.at(i)==')') continue;
		bool b=0,b2=0;
		
		for(int j=i;j<n;j++)
		{
			bool b1=0;
			if(s.at(j)=='(') l++;
			if(s.at(j)==')') r++;
			if(s.at(j)=='?') {x++; b=1;}
			
			
		if(r>l+x)	{break;}
	
		if((l-r==x || r-l==x)) {ans0++; b1=true;}
		else if(x%2==0 && l==r) {ans0++;b1=true;}
				
		if(b1==1 && s.at(j)=='(')ans0--;
		cout<<ans0<<" "<<j<<s.at(j)<<endl; 
		}
		
	
		
		ans+=ans0;
			cout<<ans<<endl;
	}
	cout<<ans<<endl;
}

