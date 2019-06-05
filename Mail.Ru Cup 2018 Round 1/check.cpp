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

	int x,y,z,t1,t2,t3;

int my()
{
	if(t1*(abs(x-y)) >= 3*t3 + t2*(abs(z-x) + abs(y-x))) return 1;
	else 0;
}

int f()
{
	int a = (x-y)*t1;
 	int b = (x-z)*t2;
 	int b1 = b+ (t3*2);
 	int b2 = t2*(x-y);
 	int sum = b1 +b2+t3;
 	if(a>sum)
 	{
 		return 1;
 	}
 	else return 0;
}
signed main()
{
 	//start_routine
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

 	int tests = 1000;
 	while(tests--)
 	{
 		x  = rand()%1000 +1,y = rand()%1000 +1,z = rand()%1000 +1,t1 = rand()%1000 +1,t2= rand()%1000 +1,t3= rand()%1000 +1;
 		if(my() != f())
 		{
 			cout<<x<<" "<<y<<" " <<" "<<z<<" "<<t1<<" "<<t2<<" "<<t3<<"\n";
 		}
 	}
 	//end_routine
}
