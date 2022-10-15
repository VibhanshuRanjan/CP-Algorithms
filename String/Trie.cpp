#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
bool ans=false;

struct node{
    char c;
    int pc; //prefix count
    int we; //word end
    node* child[26];
};

node* getNode(char c){
    node* newNode = new node();
    newNode->c = c;
    newNode->we = 0;
    newNode->pc=0;
    for(int i=0;i<26;i++)
        newNode->child[i]=NULL;
    return newNode;
}

void insert(node* root,string& s){
    node* curr = root;
    for(int i=0;i<s.size();i++){
        if(curr->child[s[i]-'a']==NULL)
            curr->child[s[i]-'a'] = getNode(s[i]);   
        curr = curr->child[s[i]-'a'];
        curr->pc+=1;
    }
    curr->we+=1;
}

int countPrefix(node* root,string& s){
    node* curr = root;
    for(int i=0;i<s.size();i++){
        if(curr->child[s[i]-'a']==NULL || curr->child[s[i]-'a']->pc==0)return 0;
        curr=curr->child[s[i]-'a'];
    }
    return curr->pc;
}

int Tsearch(node* root,string& s){
    node* curr = root;
    for(int i=0;i<s.size();i++){
        if(curr->child[s[i]-'a']==NULL || curr->child[s[i]-'a']->pc==0)return 0;
        curr=curr->child[s[i]-'a'];
    }
    return curr->we;
}

int Tdelete(node* root,string& s){
    node* curr=root;
    for(int i=0;i<s.size();i++){
        if(curr->child[s[i]-'a']==NULL || curr->child[s[i]-'a']->pc==0)return 0;
        curr=curr->child[s[i]-'a'];
    }
    if(curr->we==0)return 0;
    curr->we-=1;
    return 1;
}

void solve(){
    node* root = getNode('/');

    //Trie or dictionary building
    //Example input strings
    // army,arm,arms,ary,amy,api
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        insert(root,s);  
    }
    
    
    //No of strings with given prefix
    //To check 
    // a,ar,arm,army,armi,ary
    // int p;cin>>p;
    // for(int i=0;i<p;i++){
    //     string s;cin>>s;
    //     cout<<countPrefix(root,s)<<" ";
    // }
    // cout<<"\n";

    //Search a string is present or not
    //ar,ap,api,arm,army
    int pt;cin>>pt;
    for(int i=0;i<pt;i++){
        string s;cin>>s;
        cout<<Tsearch(root,s)<<" ";
    }
    cout<<"\n";
    

    //Trie Delete- delete some words 
    //To check
    //arm,api,apq,arm
    // int d;cin>>d;
    // for(int i=0;i<d;i++){
    //     string s;cin>>s;
    //     cout<<Tdelete(root,s)<<" "; //1 if deleted , 0 if string was not there
    // }
    // cout<<"\n";  
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