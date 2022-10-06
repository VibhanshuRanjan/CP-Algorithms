#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;

int combine(int a,int b){
    return a+b;
}

//segment tree is indexed 1
void build(vector<int>& st, vector<int>& v,int curr,int l,int r){
    if(l==r)
        st[curr]=v[l];
    else{
        int m = (l+r)/2;
        build(st,v,2*curr,l,m);
        build(st,v,2*curr+1,m+1,r);
        st[curr]=combine(st[2*curr],st[2*curr+1]);
    }

}

int query(vector<int>& st,int l,int r,int curr,int s,int e){
    if(l>r)return 0;
    if(s==l && e==r)return st[curr];
    int m = (s+e)/2;
    return combine(query(st,l,min(m,r),2*curr,s,m),query(st,max(m+1,l),r,2*curr+1,m+1,e));
    
}

void update(vector<int>& st,int pos,int del,int curr,int l,int r){
    if(l==r)st[curr]+=del;
    else{
        int m = (l+r)/2;
        if(pos<=m)
            update(st,pos,del,2*curr,l,m);
        else update(st,pos,del,2*curr+1,m+1,r);
        st[curr]=combine(st[2*curr],st[2*curr+1]);
    }
}

void segTree(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<int> st(4*n+4,0);
    build(st,v,1,0,n-1);
    // for(int i=0;i<st.size();i++)cout<<st[i]<<" ";
    int q;cin>>q;
    while(q--){
        // update(st,0,2-v[0],1,0,n-1);
        int l,r;cin>>l>>r; // l & r are 1 indexed
        l--;r--;
        cout<<query(st,l,r,1,0,n-1)<<" ";
    }
}


signed main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    // int t;cin>>t; 
    // for(int i=1;i<=t;i++){
    //     cout<<"Case #"<<i<<": ";
    //     solve();
    // }
    segTree();
}