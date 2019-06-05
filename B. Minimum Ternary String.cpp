#include<bits/stdc++.h>
#define fr(i,a,b) for(i=a;i<b;i++)
#define pb push_back

using namespace std;

signed main()
{
 	//start_routine
 	string s;
 	cin>>s;
 	int n = s.size();
 	int i,j=n;

 	int z=0,o=0;
 	fr(i,0,n)if(s[i]=='1')o++;
 	fr(i,0,n)
 	{
 		if(s[i]=='0')z++;
 		if(s[i]-'0'==2)
 		{
 			j=i;
 			break;
 		}
 	}
 	while(z--)
 	{
 		cout<<0;
 	}
 	while(o--)cout<<1;
 	z=0;
 	if(i!=n && s[j]=='2')cout<<2;
 	while(j<n)
 	{
 		while(j<n)
 		{
 			j++;
 			if(s[j]=='0')z++;
 			if(s[j]=='2')break;
 		}
 		while(z>0){cout<<0; z--;}
 		if(s[j]=='2')cout<<2;
 	}
 	//end_routine
}



