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
signed main()
{
 	//start_routine
 	int n,k,s;
 	cin>>n>>k>>s;
 	if(n==1)
 	{
 		cout<<"NO";
 		return 0;
 	}
 	if(n==2)
 	{
 		if(k!=s)
 		{
 			cout<<"NO\n";
 			return 0;
 		}
 		else
 		{
 			cout<<"YES\n";
 			int pos = 1;
 			while(k--)
 			{
 				if(pos==1){cout<<2<<" "; pos=2;}
 				else {cout<<1<<" "; pos = 1;}
 			}
 		}
 		return 0;
 	}
 	if(k>s || k*(n-1)<s)
 	{
 		cout<<"NO";
 		return 0;
 	}
 	cout<<"YES\n";
 	int diff = s-k;
 	bool b = 0;
 	while(diff>=n-1 && k)
 	{
 		if(!b)
 		cout<<n<<" ";
 		else cout<<1<<" ";
 		b = !b;
 		diff-=n-2;
 		k--;
 	}

 	//cerr<<diff<<"\n";
 	// b= 1 then last at n else last at 1;
 	int pos ;
 	if(b) pos = n;
 	else pos = 1;

 	//cout<<pos<<"\n";
 	//cout<<"pos = "<<pos<<'\n';

 	if(pos == n && diff>0)
 	{
 		cout<<n-diff-1<<" ";
 		pos = n-diff-1;
 		k--;
 	}
 	else if(diff>0){cout<<diff+2<<" ";pos = diff+2;k--;}

 	
 	//cout<<"pos="<<pos<<" "<<k<<'\n';
 	//cout<<'\n'<<diff<<'\n';
 	if(pos==1)
 	{
 		//cerr<<"hereat1 \n";
 		b=0;
 		while(k--)
 		{
 			if(!b){cout<<2<<" "; b= !b;}
 			else {cout<<1<<" "; b= !b;}
 		}
 	}
 	else if(pos==n)
 	{
 		//cerr<<"hereat2 \n";
 		b=0;
 		while(k--)
 		{
 			if(!b)
 				{cout<<n-1<<" "; b= !b;}
 			else {cout<<n<<" ";  b= !b;}
 		}
 	}
 	else 
 	{
	//cerr<<"hereat3 \n";
	//cout<<"\npos = "<<pos<<'\n';
 		b= 0;
 		//cout<<"k="<<k<<'\n';
 		while(k--)
 		{
 			if(!b)
 			{
 				cout<<pos+1<<" ";
 				b = !b;
 			}
 			else 
 			{
 				cout<<pos<<" ";
 				b = !b;
 			}
 		}
 	}
 	//end_routine
}



