#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;

void KMP(string& s,vector<int>& pi){
    int n=s.size();
    for(int i=1;i<n;i++){
        int l = pi[i-1];
        while(l>0 && s[i]!=s[l])
            l=pi[l-1];
        if(s[i]==s[l])l++;
        pi[i]=l;
    }
}

void solve(){
    string s;cin>>s;
    int n=s.size();
    vector<int> pi(n,0);
    KMP(s,pi);
    for(int i=0;i<n;i++)cout<<pi[i]<<" ";
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