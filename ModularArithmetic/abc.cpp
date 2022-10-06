#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;

//modular inverse 1 to n-1
void mi1n(){
    int m;cin>>m;
    vector<int> ans(m);
    ans[1]=1;
    for(int i=2;i<m;i++)ans[i]=m-(m/i)*ans[m%i]%m;
    for(int i=1;i<m;i++)cout<<ans[i]<<" ";
}

signed main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    // int t;cin>>t; 
    // for(int i=1;i<=t;i++){
    //     cout<<"Case #"<<i<<": ";
    //     solve();
    // }
    mi1n();
}