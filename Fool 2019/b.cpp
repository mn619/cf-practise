#include<bits/stdc++.h>
using namespace std;


int main()
{
	
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	int test = 1;
	while(t--){
		int n;
		cin>>n;

		cout<<"Case #"<<test++<<": ";
		for(int i = 1; i <= 2*n - 2; i++){
			char c;
			cin>>c;
			if(c == 'S') cout<<"E";
			else cout<<"S";
		}
		cout<<"\n";
	}


}