#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;
bool rw[51]={0},cl[51]={0};

set <int> sr;
set <int> sc;

void f(char ch,int k, char c[][51],int n, int m)
{
	cout<<ch<<" "<<k<<"\n";
	if(ch=='r'&& k>n)return;
	if(ch=='c'&& k>m)return;
	
	if(ch=='c')
	{
		for(int i=1;i<=n;i++)
		{
			if(c[i][k]=='#')
			{
				
					sr.insert(i);
					c[i][k]='.';
					f('r',i,c,n,m);
				
				
			}
		}
	}
	
	if(ch=='r')
	{
		for(int i=1;i<=m;i++)
		{
			if(c[k][i]=='#')
			{
				
				c[k][i]='.';
				sc.insert(i);
				f('c',i,c,n,m);
			}
		}
	}
	
	
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	char c[51][51];
	//vector <int> v[2];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c[i][j];
			
		}
	}
	
	string ans="Yes";
	for(int i=1;i<=m;i++)
	{
		if(rw[i]==0)
		{
			
			f('r',i,c,n,m);
			
			set <int>::iterator it;
			cout<<sr.size()<<"\n"<<sc.size()<<"\n\n";
			
			if(sr.size()==0)continue;
			
			for(;; sr.erase(it))
			{
				it=sr.begin();
				cout<<*it<<"\n";
				
				if(rw[*it]==0) rw[*it]=1;
				else {cout<<"No\n"; return 1;}
				
				if(sr.size()==1) {sr.erase(it);break;}
			}
			cout<<"change here \n";
			it=sc.begin();
			
			for(;; sc.erase(it))
			{
				it=sc.begin();
				cout<<*it<<"\n";
				if(cl[*it]==0) cl[*it]=1;
				else {cout<<"No\n"; return 1;}
				
				if(sc.size()==1){ sc.erase(it); break;}
			}
			
		}
	}
	
	cout<<"Yes\n";
}

