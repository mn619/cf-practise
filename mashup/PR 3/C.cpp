#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin>>s;
	int a[s.size()];
	int b[26]={0};
	for(int i=0;i<s.size();i++)
	{
		a[i]=int(s[i]-'a');
		b[a[i]]++;
	}
	
	vector <int> o; vector <int> e;
	
	for(int i=0;i<26;i++)
	{
		if(b[i]%2)o.pb(i);
		else e.pb(i);
	}
	
	if(s.size()%2)
	{
		//cout<<"size of o "<<o.size()<<endl;
		/*for(int i=0;i<o.size();i++)
		{
			cout<<o[i]<<endl;
		}
		cout<<"ehe";*/
		//cout<<o[0]<<"\n\n here";
		//for(int i=0;i<26;i++)cout<<b[i]<<endl;
		
		for(int i=0;i<o.size()/2;i++)
		{
			b[o[i]]++;
			b[o[o.size()-1-i]]--;
		}
		
		
		//for(int i=0;i<26;i++)cout<<b[i]<<endl;
		
		int k=o[o.size()/2]; //cout<<k<<endl;
		b[k]--;
		for(int i=0;i<26;i++)
		{
			//cout<<"b[i]"<<b[i]<<endl;
			for(int j=1;j<=b[i]/2;j++)
			{
				cout<<char(i+'a');
			}
			b[i]/=2;
		}
		cout<<char('a'+k);
		//for(int i=0;i<26;i++)cout<<b[i]<<endl;
		
		for(int i=25;i>=0;i--)
		{
			for(int j=0;j<b[i];j++)
			{
				cout<<char(i+'a');
			}
		}
	}
	else
	{
		for(int i=0;i<o.size()/2;i++)
		{
			b[o[i]]++;
			b[o[o.size()-1-i]]--;
		}
		
		for(int i=0;i<26;i++)
		{
			//cout<<"b[i]"<<b[i]<<endl;
			for(int j=1;j<=b[i]/2;j++)
			{
				cout<<char(i+'a');
			}
			b[i]/=2;
		}
		//cout<<char('a'+k);
		//for(int i=0;i<26;i++)cout<<b[i]<<endl;
		
		for(int i=25;i>=0;i--)
		{
			for(int j=0;j<b[i];j++)
			{
				cout<<char(i+'a');
			}
		}
	}
	
	
	
	
	
	
}


