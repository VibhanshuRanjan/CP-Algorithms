#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;

void Z_function(string& s,vector<int>& z){
    int n=s.size();
    int l=0,r=0,h;
    for(int i=1;i<n;i++){
        if(i<=r)
            z[i]=min(r-i+1,z[i-l]);
        while(s[i+z[i]]==s[z[i]])++z[i];
        if(z[i]-i+1>r){
            l=i;
            r=i+z[i]-1;
        }
    }
}

void solve(){
    string s;cin>>s;
    int n=s.size();
    vector<int> z(n,0);
    Z_function(s,z);
    for(int i=0;i<n;i++)cout<<z[i]<<" ";
}

signed main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    // int t;cin>>t; 
    // for(int i=1;i<=t;i++){
    //     cout<<"Case #"<<i<<": ";
    //     solve();
    // }
    solve();
}