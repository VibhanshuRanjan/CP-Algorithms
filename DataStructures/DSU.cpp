#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;

int find_set(int a,vector<int>& p){
    if(a==p[a])return a;
    return p[a]=find_set(p[a],p);
}
void union_set(int a,int b,vector<int>& p,vector<int>& r){
    int pa = find_set(a,p);
    int pb = find_set(b,p);
    if(pa!=pb){
        if(r[a]<r[b])
            swap(a,b);
        p[b]=a;
        if(r[a]==r[b])r[a]+=1;
    }
}
void DSU(){
    int n;cin>>n;
    vector<int> p(n+1),r(n+1,0);
    for(int i=0;i<n;i++){
        int a;cin>>a;p[a]=a;
    }
    // union_set(2,3,p,r);
    // union_set(3,4,p,r);
    // cout<<find_set(1,p)<<" "<<find_set(2,p)<<" "<<find_set(3,p)<<" "<<find_set(4,p)<<" ";
    
}


signed main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    // int t;cin>>t; 
    // for(int i=1;i<=t;i++){
    //     cout<<"Case #"<<i<<": ";
    //     solve();
    // }
    DSU();
}