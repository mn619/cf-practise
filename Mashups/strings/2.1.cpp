#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mod 1000000007
#define p 101
/*
	4
	hello this is aman
	<3hello<23sdsjdthis<3is<3<<<3aman<3
*/

using namespace std;


int search(int i, string s)
{
	for(int j=i;j<s.size();j++)
	{
		if(s[j]=='3') return j;
	}
}

int searchString(string s,string S, int i)
{
		int j=0, k=i;
		for(;k<S.size();k++)
		{
			if(S[k]==s[j])
			{
				j++;
			}
		}
		if(j==s.size())return k;
		else return -1;
}

int main()
{	
	int n;
	cin>>n;
	
	string s[n],S;
	
	for(int i=0;i<n;i++)cin>>s[i];
	cin>>S;
	
	//for(int i=0;i<S.size();i++)cout<<i<<"\t\t\t"<<a[i]<<endl;
	int j=0;
	for(int i=0;i<S.size();i++)
	{
		cout<<i<<" ";
		int k;
		bool t=0;
		if(S[i]=='<') 
		{
			k=search(i,S);
			i=k;
			t=1;
		}
		
		cout<<i<<" "<<j<<" "<<s[j]<<endl;
		if(i>=S.size())break;
		
		if(t)
		{
			k=searchString(s[j],S, i);
			i=k;
			j++;
		}
		
		
		if(i>=S.size())break;
	}
	
	if(j==n)cout<<"yes\n";
	else cout<<"no\n";
}

