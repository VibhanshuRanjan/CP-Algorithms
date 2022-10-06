#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;

// void insert(deque<int>& q,int a){
//     while(!q.empty() && q.back()>a){
//         q.pop_back();
//     }
//     q.push_back(a);
// }

// void remove(deque<int>& q,int a){
//     if(!q.empty() && q.front()==a)
//         q.pop_front();
// }

// //find min of each subarray of length m, 0 to m-1, m to 2m-1.....
// //here we should know what element to remove
// void minq1(){
//     int n,m;cin>>n>>m;
//     deque<int> q;
//     vector<int> ans;
//     vector<int> arr(n);
//     for(int i=1;i<=n;i++){
//         cin>>arr[i-1];
//         insert(q,arr[i-1]);
//         if(i>=m){
//             ans.push_back(q.front());
//             remove(q,arr[i-m]);
//         }
//     }

//     for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
// }
void insert(deque<pair<int,int>>& q,int a,int ind){
    while(!q.empty() && q.back().second>a)
        q.pop_back();
    q.push_back({ind,a});
}

void remove(deque<pair<int,int>>& q,int removed){
    if(!q.empty() && q.front().first==removed)
        q.pop_front();
}

void minq2(){
    int n,m;cin>>n>>m;
    deque<pair<int,int>> q;
    vector<int> ans;
    int removed = 0;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        insert(q,a,i-1);
        if(i>=m){
            ans.push_back(q.front().second);
            remove(q,removed);
            removed++;
        }
    }

    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}

signed main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    // int t;cin>>t; 
    // for(int i=1;i<=t;i++){
    //     cout<<"Case #"<<i<<": ";
    //     solve();
    // }
    // minq1();
    minq2();

}