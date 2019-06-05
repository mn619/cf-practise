#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;


int toint(int l, string s)
{
	return (s[l] - '0')*10 + (s[l + 1] - '0');
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int h1, h2, m1, m2;
 	string s;
 	cin>>s;
 	h1 = toint(0, s);
 	m1 = toint(3, s);
 	cin>>s;
 	h2 = toint(0, s);
 	m2 = toint(3, s);


 	int mm = (h2 - h1)*60 - m1 + m2;
 	mm /= 2;
 	int h = h1 + (mm + m1)/60, m = (mm + m1)%60;
 	if(h < 10) cout<<'0';
 	cout<<h<<":";
 	if(m < 10) cout<<0; 
 	cout<<m<<"\n";

}