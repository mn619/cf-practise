#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int search(string S,int i)
{
	int n=S.size();
	for(int k=i;k<n;k++)
	{
		if(S[k]=='3')return k;
	}
	return n;
}

int search_String(string S,string s,int i)
{	
	int j=0,k=i;
	for(;k<S.size();k++)
	{
		if(S[k]==s[j])j++;
		if(j==s.size())break;
	}
	return k;
}
int main()
{
	int n;
	cin>>n;
	string s[n],S;
	for(int i=0;i<n;i++)cin>>s[i];
	cin>>S;
	int m=S.size();
	bool b=0;int j=0;
	for(int i=0;i<m;i++)
	{
		if(!b && S[i]=='<')
		{
			i=search(S,i);
			if(i<m)b=1;
			continue;
		}
		
		if(b && j<n)
		{
			i=search_String(S,s[j],i);
			j++;
			b=0;
			continue;
		}
	}
	if(j==n && b)cout<<"yes\n";
	else cout<<"no\n";
}

