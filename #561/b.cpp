#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int k;


void solve(int a, int b){
	char c[] = {'a', 'e', 'i', 'o', 'u'};
	fr(i, 1, a + 1){
		fr(j, 1, b + 1){
			cout<<c[(i + j)%5];
		}
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>k;
 	fr(i, 5, k + 1){
 		if(k%i == 0 and k/i >= 5) {solve(i, k/i);  return 0;}
 	}

 	cout<<-1;

}