#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;

vector<int> manacher(string& s){
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max((int)0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    // for(int i=0;i<p.size();i++)cout<<p[i]<<" ";
    // cout<<"\n";
    return vector<int>(begin(p) + 1, end(p) - 1);
}

void solve(){
    string s;cin>>s;
    string st;
    for(auto c:s)
        st+=string("#")+c;
    st+="#";
    vector<int> p = manacher(st);
    for(int i=0;i<p.size();i++)cout<<p[i]<<" ";
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