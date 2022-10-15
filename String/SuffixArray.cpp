#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;

void suffixArray(string& s,vector<int>& p){
    int n=s.size(),cntmax = 256;
    vector<int> cnt(cntmax,0);
    vector<int> c(n); 
    for(int i=0;i<n;i++)cnt[s[i]]++;
    for(int i=1;i<cntmax;i++)cnt[i]+=cnt[i-1];
    for(int i=0;i<n;i++)p[--cnt[s[i]]]=i;
    c[p[0]]=0;
    int totalc=1;//total no of classes
    for(int i=1;i<n;i++){
        if(s[p[i]]!=s[p[i-1]])
            ++totalc;
        c[p[i]]=totalc-1;
    }

    vector<int> pn(n),cn(n);
    // k represents lenth of substrings
    for(int k=0;(1<<k)<n;k++){
        for(int i=0;i<n;i++){
            pn[i]=p[i]-(1<<k);
            if(pn[i]<0)pn[i]+=n;
        }

        for(int i=0;i<totalc;i++)cnt[i]=0;
        for(int i=0;i<n;i++)cnt[c[pn[i]]]++;
        for(int i=1;i<totalc;i++)cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--){
            p[--cnt[c[pn[i]]]]=pn[i];
        }
        cn[p[0]]=0;
        totalc=1;
        for(int i=1;i<n;i++){
            pair<int, int> curr = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
            if (curr != prev)
                ++totalc;
            cn[p[i]] = totalc - 1;
        }
        c.swap(cn);
    }
    
}

void solve(){
    string s;cin>>s;
    // s+="$";
    int n=s.size();
    vector<int> p(n,0);//p[i] contains index of the ith substring in the sorted order
    suffixArray(s,p);
    for(int i=0;i<n;i++)cout<<p[i]<<" ";
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