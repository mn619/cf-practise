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
	cout<<s<<"\n";
	cout<<s[0]<<"\t"<<s[1]<<"\n";
	if(s.size()==2) return (s[0]-'0')+(s[1]-'0')*10;
	else return s[0]+s[1]*10+s[2]*100+s[3]*1000;
}

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s="12";
	cout<<con(s.substr(0,2));
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

