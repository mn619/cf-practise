#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;

struct node
{
	int cntr = 0;
	struct node* even;
	struct node* odd;
};

node* root;

int m;
string s[100001];
int cnt[100001][26] = {{0}};

void add(int pos)
{
	node * t = root;
	int ind = 0;

	while(ind<26)
	{
		cout<<ind<<" "<<cnt[pos][ind]<<' '<<(cnt[pos][ind]&1)<<'\n';
		
		if(cnt[pos][ind]%2 == 1)
		{
			if(t->odd == NULL)
			{
				t->odd = new node;
			}
			t = t->odd;
		}
		else
		{
			cout<<"HOLA\n";
			if(t->even == NULL )
			{
				t->even = new node;
			}
			t = t->even;
		}
		ind = ind + 1;
	}

	t->cntr++;
}

int queriE(int  pos)
{
	node * n = root;
	int ind = 0;

	while(ind < 26)
	{
		if(cnt[pos][ind]&1)
		{
			if(n->odd == NULL) n->odd = new node;
			n = n->odd;
		}
		else
		{
			if(n->even == NULL) n->even = new node;
			n = n->even;
		}
		ind++;
	}

	return n->cntr;
}

int queriO(int c, int pos)
{
	int ind = 0;
	node *n = root;

	while(ind<26)
	{
		cout<<"ind = "<<ind<<'\n';
		if(ind!=c)
		{
			if(cnt[pos][ind]&1)
			{
				if(n->odd == NULL) n->odd = new node;
				n = n->odd;
			}
			else
			{
				if(n->even == NULL) n->even = new node;
				n = n->even;
			}
		}
		else
		{
			if(cnt[pos][ind]&1)
			{
				if(n->even == NULL) n->even = new node;
				n = n->even;
			}
			else 
			{
				if(n->odd == NULL) n->odd = new node; 
				n = n->odd;
			}
		}
		ind++;
	}

	return n->cntr;
}

signed main()
{
 	//start_routine
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	root = new node;

	cin>>m;

	int i;
	fr(i,1,m+1)
	{
		cout<<"hole\n";
		cin>>s[i];
		int j;
		fr(j,0,s[i].size())
		{
			cnt[i][s[i][j]-'a']++;
		}
		add(i);
	}
	//for even length

	int ans = 0;
	fr(i,1,m+1)
	{
		cout<<i<<"\n";
		ans += queriE(i);
	}
	cout<<ans<<'\n';

	fr(i,0,26)
	{
		cout<<i<<'\n';
		int j;
		fr(j,1,m+1)
		{
			cout<<j<<"\n";
			ans+=queriO(i,j);
		}
	}
 	cout<<ans<<'\n';
 	//end_routine
}
