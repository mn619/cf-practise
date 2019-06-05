#include <bits/stdc++.h>
using namespace std;
long gcdd(long a,long b)
{
	if(b==0)
		return a;
	return gcdd(b,a%b);
}
long maxx(long a,long b)
{
	if(a>b)
		return a;
	return b;
}long maxt(long a,long b,long c)
{
	return maxx(a,maxx(b,c));
}

int main() {
	ios_base::sync_with_stdio(false);
	long n,f=0,flag=0,i,count=0;
	cin>>n;
	string s;
	cin>>s;
	if(s[0]=='0')
	{
		count++;
		for(i=1;i<n;i++)
		{
			if(s[i]=='1' && i!=n-1)
			{
				if(s[i-1]!='0' || s[i+1]!='0')
				{
					flag=1;
					break;
				}
				count=0;
			}
			else if(s[i]=='1')
			{
				if(s[i-1]!='0')
				{
					flag=1;
					break;
				}
				count=0;
			}
			else
			{
				count++;
				if(count==3)
				{
					flag=1;
					break;
				}
				if(count==2 && (i==1 ||i==n-1))
				{	
					flag=1;
					break;
				}
			}
		}
	}
	else
	{
		if(s[1]!='0')
		{
			flag=1;
		}
		for(i=1;i<n;i++)
		{
			if(s[i]=='1' && i!=n-1)
			{
				if(s[i-1]!='0' || s[i+1]!='0')
				{
					flag=1;
					break;
				}
				count=0;
			}
			else if(s[i]=='1')
			{
				if(s[i-1]!='0')
				{
					flag=1;
					break;
				}
				count=0;
			}
			else
			{
				count++;
				if(count==3)
				{
					flag=1;
					break;
				}
				if(count==2 && (i==1 ||i==n-1))
				{	
					flag=1;
					break;
				}
			}
		}
	}
	if(flag==0)
	{
		cout<<"Yes"<<endl;
	}
	else
		cout<<"No"<<endl;


	return 0;
}
