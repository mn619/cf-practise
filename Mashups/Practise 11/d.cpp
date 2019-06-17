#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n;
 	cin>>n;
	int cnt = n - 1;

	if(n <= 3) return cout<<"NO\n", 0;
	else{
		cout<<"YES\n";
		if(n%4 == 0){
			int las = 1;
			fr(i, 2, 5){
				cout<<las<<" * "<<i<<" = "<<las*i<<'\n';
				las *= i;
				cnt--;
			}
			for(int i = 5; i < n; i+=4){
				cout<<i<<" + "<<i + 3<<" = "<<2*i + 3<<"\n";
				cout<<i + 1<<" + "<<i + 2<<" = "<<2*i + 3<<'\n';
				cout<<2*i + 3<<" - "<<2*i + 3<<" = 0\n";
				cnt -= 3;
			}
		}
		else if(n%4 == 1){
			cout<<"5 * 4 = 20\n";
			cout<<"2 + 3 = 5\n";
			cout<<"5 - 1 = 4\n";
			cout<<"4 + 20 = 24\n";
			cnt -= 4;
			for(int i = 6; i < n; i+=4){
				cout<<i<<" + "<<i + 3<<" = "<<2*i + 3<<"\n";
				cout<<i + 1<<" + "<<i + 2<<" = "<<2*i + 3<<'\n';
				cout<<2*i + 3<<" - "<<2*i + 3<<" = 0\n";
				cnt -= 3;
			}
		}
		else if(n%4 == 2){
			cout<<"4 * 6 = 24\n";
			cout<<"1 * 2 = 2\n";
			cout<<"5 - 2 = 3\n";
			cout<<"3 - 3 = 0\n";
			cout<<"0 + 24 = 24\n";
			cnt -= 5;
			for(int i = 7; i < n; i+=4){
				cout<<i<<" + "<<i + 3<<" = "<<2*i + 3<<"\n";
				cout<<i + 1<<" + "<<i + 2<<" = "<<2*i + 3<<'\n';
				cout<<2*i + 3<<" - "<<2*i + 3<<" = 0\n";
				cnt -= 3;
			}
		}
		else{
			cout<<"6 * 7 = 42\n";
			cout<<"4 * 5 = 20\n";
			cout<<"3 - 2 = 1\n";
			cout<<"1 + 1 = 2\n";
			cout<<"42 - 20 = 22\n";
			cout<<"22 + 2 = 24\n";
			cnt -= 6;
			for(int i = 8; i < n; i+=4){
				cout<<i<<" + "<<i + 3<<" = "<<2*i + 3<<"\n";
				cout<<i + 1<<" + "<<i + 2<<" = "<<2*i + 3<<'\n';
				cout<<2*i + 3<<" - "<<2*i + 3<<" = 0\n";
				cnt -= 3;
			}
		}

		assert(cnt >= 0);
		fr(i, 1, cnt + 1) cout<<"0 + 24 = 24\n";
	}
}