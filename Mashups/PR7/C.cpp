#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;


int con(string s)
{
	if(s.size()==2) return (s[0]-'0')*10+(s[1]-'0');
	else return (s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
}

bool check(int dd,int mm,int yr)
{
	if(yr<2013 || yr>2015)return 0;
	if(dd<=0)return 0;
	if(dd>31)return 0;
	if(mm==2&&dd>28)return 0;
	if(mm==4 && dd>30)return 0;
	if(mm==6&&dd>30)return 0;
	if(mm==9&&dd>30)return 0;
	if(mm==11&&dd>30)return 0;
	return 1;
}
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin>>s;
	
	map < pair<int, pair <int,int> > , int> m;
	
	int n=s.size();
	
	for(int i=2;i<s.size();i++)
	{
		if(s[i]=='-')
		{
			if(i+7<n && i-2>=0)
			{
				if(s[i-2]!='-'&&s[i-1]!='-'&&s[i+1]!='-'&&s[i+2]!='-'&&s[i+3]=='-'&& s[i+4]!='-'&& s[i+5]!='-'&& s[i+6]!='-'&& s[i+7]!='-')
				{
					int dd=con(s.substr(i-2,2));
					int mm=con(s.substr(i+1,2));
					int yr=con(s.substr(i+4,4));
					pair<int,int>  my=mp(mm,yr);
					pair <int, pair<int,int> > date=mp(dd,my);
					if(check(dd,mm,yr))
					m[date]++;
				}
			}
		}
	}
	map < pair<int, pair <int,int> > , int> ::iterator it=m.begin(), ans=it;
	
	while(it!=m.end())
	{		
		if(m[it->first]>m[ans->first])ans=it;
		it++;
	}
	
	if(ans->first.first<10) cout<<"0"; cout<<ans->first.first<<"-";
	if(ans->first.second.first<10)cout<<"0"; cout<<ans->first.second.first<<"-";
	cout<<ans->first.second.second<<"\n";
	//cout<<ans->first.first<<"-"<<ans->first.second.first<<"-"<<ans->first.second.second;
	
}



