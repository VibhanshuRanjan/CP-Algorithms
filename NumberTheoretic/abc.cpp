#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;

//euler's totient or phi function for n ,O(rn)
void et(){
    int n;cin>>n;
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0)n/=i;
            ans-=ans/i;
        }
    }
    if(n>1)ans-=ans/n;
    cout<<ans;
}
//euler's totient for 1 to n ,O(nlln)
void et1n(){
    int n;cin>>n;
    vector<int> ans(n+1);
    for(int i=0;i<=n;i++)ans[i]=i;
    for(int i=2;i<=n;i++){
        if(ans[i]==i){
            for(int j=i;j<=n;j+=i){
                ans[j]-=ans[j]/i;
            }
        }
    }

    for(int i=0;i<=n;i++)cout<<ans[i]<<" ";
}

// Euler's totient divisor sum property ,O(nln)
void etds(){
    int n;cin>>n;
    vector<int> ans(n+1);ans[0]=0;ans[1]=1;
    for(int i=2;i<=n;i++)ans[i]=i-1;
    for(int i=2;i<=n;i++){
        for(int j=2*i;j<=n;j+=i)ans[j]-=ans[i];
    }

    for(int i=0;i<=n;i++)cout<<ans[i]<<" ";
}

signed main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    // int t;cin>>t; 
    // for(int i=1;i<=t;i++){
    //     cout<<"Case #"<<i<<": ";
    //     solve();
    // }
    etds();
}