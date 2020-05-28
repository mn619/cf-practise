#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int power(string A) {
    if(A == "0" or (A.size() == 0)) return 0;
    if(A == "1") return 1;
    
    while(A != "2"){
        int n = A.size();
        if((A[n - 1] - '0')&1) return 0;
        string s = "";
        int rem = 0;
        for(int i = 0; i < n; i++){
            rem = rem*10 + A[i] - '0';
            int dig = rem/2;
            assert(dig < 10);
            rem %= 2;
            s += (char)dig + '0';
        }
        cout<<A<<"\n";
        n = s.size();
        A = "";
        bool foundNonZero = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != '0') foundNonZero = 1;
            if(foundNonZero)
                A += s[i];
        }
    
}    
    return 1;
}


signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

   string a;
   cin>>a;
   cout<<power(a);
}