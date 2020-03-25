#include<bits/stdc++.h>
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); 

using namespace std;

long long int rev(long long int x){
	long long int p = 1, ans = 0;
	while(x){
		ans += (11 - (x%10))*p;
		p *= 10;
		x /= 10;
	}
	return ans;
}

int main()
{
    FILEIO

    vector <long long int> v;

    for(int i = 1; i < (1<<13); i++){
    	int mask = i;
    	int a = 0, b = 0;
    	long long int num = 0, p = 1;
    	for(int j = 0; j < 13; j++){
    		if(mask>>j == 0) break;
    		if((mask>>j)&1)
    			num += 7*p, b++;
    		else num += 4*p, a++;
    		p *= 10;
    	}

    	if(a == b)
    		v.push_back(num), v.push_back(rev(num));
    }

    sort(v.begin(), v.end());

    int n;
    cin>>n;

    for(auto x: v){
    	if(x >= n){
    		cout<<x<<'\n';
    		return 0;	
    	}
    }

}