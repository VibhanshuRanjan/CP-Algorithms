#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;

// fenwick for one dimenstional array and 0 based indexing
// can be easily implemented for 2-d array

// modify for -
// point update and range query
// range update and point query
// range update and range query
void update(vector<int>& ft,int id,int del){
    while(id<ft.size()){
        ft[id]+=del;
        id = (id|(id+1)); // i+(i&(-i)), for 1 indexing
    }
}

int find(vector<int>& ft,int id){
    int ans=0;
    while(id>=0){
        ans+=ft[id];
        id=(id&(id+1)); // i-(i&(-i))
        id-=1;
    }
    return ans;
}


void fenTree(){
    int n;cin>>n;
    vector<int> v(n),ft(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        update(ft,i,v[i]);
    }

    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        if(l==1)
            cout<<find(ft,r-1)<<" ";
        else
            cout<<find(ft,r-1)-find(ft,l-2)<<" ";
    }
}

signed main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    // int t;cin>>t; 
    // for(int i=1;i<=t;i++){
    //     cout<<"Case #"<<i<<": ";
    //     solve();
    // }
    fenTree();
}