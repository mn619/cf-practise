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
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;


int n;
vector <int>  v[2];
map <int, char> m;

void compute()
{
	int i;\
	fr(i,1,9)
	{
		m[i] = char('a' + i - 1);
	}
}
signed main()
{
	//FILEIO
 	//start_routine
	
	cin>>n;
	n++;
	
	compute();

	int x = 1, y = 1;
	int a = 1, b = 1;

	while(n >= 2 && b != 7)
	{
		if(n == 2)
		{
			if(b == 8)
			{
				v[1].pb(a + 1);
				v[2].pb(b);
			}
			else 
			{
				if( a!=8 ) v[1].pb(a), v[2].pb(8);
				else
				{
					v[1].pb(a), v[2].pb(b + 1);
					b++;
					n--;
				}
			}
			n--;
			break;
		}

		if(x == 1)
		{
			if(a == 8)
			{
				v[1].pb(a);
				v[2].pb(b + 1);
				b++;
				x = -1;
			}
			else v[1].pb(a + 1), v[2].pb(b), a++;
		}
		if(x == -1)
		{
			if(a == 1)
			{
				v[1].pb(a);
				v[2].pb(b + 1);
				b++;
				x = 1;
			}
			else v[1].pb(a - 1), v[2].pb(b), a--;
		}
		n--;
	}

	x = 1, y = 1;

	if(b == 7 && n > 1)
	{
		if(n%4 == 1 || n%4 == 2)
		{
			while(n>=1)
			{
				if(x == 1)
				{
					v[1].pb(a + 1), v[2].pb(b);
					a++;
					x = 0, y *=-1;
				}
				else if(y == 1)
				{
					v[1].pb(a), v[2].pb(b + 1);
					b++;
					x = 0;
				}
				else if(y == -1)
				{

				}
			}
		}
	}

	cout<<'a'<<1<<" ";

	int i;
	fr(i,0,v[1].size())
	{
		cout<<m[v[1][i]]<<v[2][i]<<" ";
	}
	cout<<"h8";
 	//end_routine
}
