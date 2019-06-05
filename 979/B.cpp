#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	ll n,a=0,b=0,c=0;
	string x,y,z;
	cin>>n>>x>>y>>z;
	
	int  kuro[26]={0},shiro [26]={0}, katie[26]={0};
	
	for(int i=0;i<x.size();i++)
	{
		kuro[x[i]-'a']++;
	}
	for(int i=0;i<x.size();i++)
	{
		shiro[y[i]-'a']++;
	}
	for(int i=0;i<x.size();i++)
	{
		katie[z[i]-'a']++;
	}
	
	for(int i=0;i<26;i++)
	{
		if(a<kuro[i])a=kuro[i];
		if(b<shiro[i])b=shiro[i];
		if(c<katie[i])c=katie[i];
	}
	
	if(n>=x.size()-a)a=x.size();
	else a=a+n;
	if(n>=y.size()-b)b=y.size();
	else b=b+n;
	if(n>=z.size()-c)c=z.size();
	else c=c+n;
	
	///cout<<a<<b<<c;
	int l=a;
	if(l<b)l=b;
	if(l<c)l=c;
	
	if(l==a)if(l!=b && l!=c)cout<<"Kuro";else cout<<"Draw";
	else if(l==b)if(l!=a&&l!=c)cout<<"Shiro";else cout<<"Draw";
	else cout<<"Katie";
	
	
}

