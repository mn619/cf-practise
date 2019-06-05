#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	int x,hh,mm;
	cin>>x>>hh>>mm;
	ll ans=0;
	for(;;)
	{
		if(hh%10==7||mm%10==7||hh/10%10==7||mm/10%10==7)break;
		mm-=x;
		ans++;
		if(mm<0){mm+=60;hh--;}
		if(hh<0){hh+=24;}
		
		
		
		
	}
	
	cout<<ans<<endl;
}

