#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;

// seive of eratosthenes
void seive(){
    int n;cin>>n;
    vector<int> p(n+1,1);
    p[0]=0;p[1]=0;
    for(int i=2;i*i<=n;i++){
        if(p[i]){
            for(int j=i*i;j<=n;j+=i){
                p[j]=0;
            }
        }
    }

    for(int i=1;i<=n;i++)cout<<p[i]<<" ";
}

//segmented seive with pre generation of primes
void ss1(){
    int l,r;cin>>l>>r;
    int sqr = sqrt(r); 
    vector<int> isPrime(r+1,1);isPrime[0]=isPrime[1]=0;
    vector<int> primes;
    for(int i=2;i<=sqr;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j=i*i;j<=sqr;j+=i)isPrime[j]=0;
        }
    }
    vector<int> ans(r-l+1,1);
    for(auto x:primes){
        for(int j=max(x*x,(l+x-1)/x*x);j<=r;j+=x)ans[j-l]=0;
    }

    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}

//segment seive with no pre generation of primes
void ss2(){
    int l,r;cin>>l>>r;
    int sqr = sqrt(r);
    vector<int> ans(r-l+1,1);
    for(int i=2;i<=sqr;i++){
        for(int j=max(i*i,(l+i-1)/i*i);j<=r;j+=i)ans[j-l]=0;
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
    // seive();
    ss2();
}