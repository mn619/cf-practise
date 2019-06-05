#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,m,cnt=0,segcnt=0;
char s[333333];

void padh_le_baita()
{
	bool b=0;
	cin>>n>>m>>s;
	
	for(int i=0;i<n;i++)
	{
		if(s[i]=='.')cnt++;
		
		if(s[i]=='.'&&b==0)
		{
			b=1;
			segcnt++;
		}
		if(s[i]!='.'&&b==1)
		{
			b=0;
		}
	}
}

void kuch_kar_le_baita()
{
	int ind;
	char c;
	while(m--)
	{
		cin>>ind>>c;
		ind--;
		if(c=='.'&&s[ind]!='.')cnt++;
		else if(c!='.'&&s[ind]=='.')cnt--;
		
		if(c=='.')
		{
			if(ind!=0&&ind!=n-1)
			{
				if(s[ind-1]!='.'&&s[ind+1]!='.'&&s[ind]!='.')segcnt++;
				else if(s[ind-1]=='.'&&s[ind+1]=='.'&&s[ind]!='.')segcnt--;
			}
			else if(ind==0){if(s[1]!='.'&&s[0]!='.')segcnt++;}
			else if(ind==n-1)if(s[n-2]!='.'&&s[n-1]!='.')segcnt++;
		}
		else
		{
			if(ind!=0&&ind!=n-1)
			{
				if(s[ind-1]=='.'&&s[ind+1]=='.'&&s[ind]=='.')segcnt++;
				else if(s[ind-1]!='.'&&s[ind+1]!='.'&&s[ind]=='.')segcnt--;
			}
			else if(ind==0)
			{
				if(s[1]!='.'&&s[0]=='.')segcnt--;
			}
			else if(ind==n-1)
			{
				if(s[n-2]!='.'&&s[n-1]=='.')segcnt--;
			}
		}
		s[ind]=c;
		cout<<cnt-segcnt<<"\n";
	}
}
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	padh_le_baita();
	if(n==1)
	{
		while(m--)cout<<0<<"\n";
	}
	else if(n==2)
	{
		int ind; char c;
		while(m--)
		{
			cin>>ind>>c;
			ind--;
			s[ind]=c;
			if(s[0]=='.'&&s[1]=='.')cout<<1<<"\n";
			else cout<<0<<"\n";
		}
	}
	else
	kuch_kar_le_baita();
}

/*
 © Copyright 			all rights reserved
     __           __      __       __    	   __	   _
    //\\         //||    //||     //\\        //||    //
   //  \\       // ||   // ||    //  \\      // ||   //
  //----\\     //  ||  //  ||   //----\\    //  ||  //
 //      \\   //   || //   ||  //      \\  //   || //
//        \\ //    ||//    || //        \\//    ||//

*/

