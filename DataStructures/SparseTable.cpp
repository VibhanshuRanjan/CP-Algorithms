#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;
// for any function other than min replace min with f e.g. sum;
void create(vector<vector<int>>& st,vector<int>& v,int n,int k){
    for(int i=0;i<n;i++)st[i][0]=v[i];
    for(int j=1;j<=k;j++){
        for(int i=0;i+(1<<(j-1))<n;i++)st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        // for(int i=0;i+(1<<(j-1))<n;i++)st[i][j]=st[i][j-1]+st[i+(1<<(j-1))][j-1];
    }
}


int find(vector<vector<int>>& st,vector<int>& lg,int l,int r){
    int n=st.size(),k=st[0].size();
    // int ans=LLONG_MAX;
    int ans = 0;
    // directly we could have used following for finding min
    // int j = lg[r-l+1];
    // ans = min(st[l][j],st[r-(1<<j)+1][j]);
    //or else use this 
    //note below can be use for sum also but above one can't
    for(int i=k;i>=0;i--){
        if((1<<i)<=r-l+1){
            ans = min(ans,st[l][i]);
            // ans+=st[l][i];
            l+=1<<i;
        }
    }
    return ans;
}

void stable(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int k = log2(n);
    vector<vector<int>> st(n,vector<int>(k+1));
    create(st,v,n,k);
    vector<int> lg(n+1);
    lg[1]=0;
    for(int i=2;i<=n;i++)lg[i]=lg[i/2]+1; //lg will be used in minm range queries to find log of r-l+1 frequently
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<find(st,lg,l-1,r-1)<<" ";
    }
    
}


signed main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    // int t;cin>>t; 
    // for(int i=1;i<=t;i++){
    //     cout<<"Case #"<<i<<": ";
    //     solve();
    // }
    stable();
}