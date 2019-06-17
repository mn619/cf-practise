#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	string s,ans="YES";
	
	getline(cin,s);
	int t=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') t++;
	}
	
	if(t!=5)
	{
		ans="NO";
	}
	t=0;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') t++;
	}
	
	if(t!=7)
	{
		ans="NO";
	}
	t=0;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') t++;
	}
	
	if(t!=5)
	{
		ans="NO";
	}
	
	cout<<ans<<"\n";
}

