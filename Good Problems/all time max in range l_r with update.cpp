#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
//using u128 = __uint128_t;
 
#define read()          freopen("folding.in","r",stdin)
#define write()         freopen("folding.out","w",stdout)
 
#define ff              first
#define ss              second
#define pb              push_back
#define endl            "\n"
#define ll              long long
#define double          long double
#define ull             unsigned long long
#define all(x)          x.begin(), x.end()
#define rall(x)         x.rbegin(), x.rend()
#define uniq(x)         unique(x.begin(), x.end()) - x.begin()
#define deci(x)         cout << fixed << setprecision(x);
#define war()           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
 
const ll LLMax = 1e18;
const ll LLMin = -1e18;
const ll MOD   = 1e9+7;
const double PI = acos(-1);       //3.1415926535897932384626
 
int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};
 
//pbds
//template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//template<typename T>using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
//debug
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define db(x)
#endif
 
//sc
template<typename T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x : a) cin >> x; return cin; }
 
// nCr = n! / r! * (n-r)!
// nPr = n! / (n-r)!
// .order_of_key(x)
// *    .find_by_order(x)
//substr
//cin.ignore();
//__builtin_popcount()
//memset(dp, -1, sizeof(dp));
//cout<<"Case "<<T<<": ";
 
 
#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}
#define IMP {cout<<"-1"<<endl;}
 
 
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

#define int ll

const int N=1e5+7;

int arr[N];
int treee[4*N], treee_mx[4*N]; //cur_mx,mx_mx
int lazy[4*N], lazy_mx[4*N];  //cur_mx,mx_mx



void relax(int node, int st, int en){
    if(st!=en){
        int L=2*node, R=(2*node)+1;
        treee_mx[L]=max(treee_mx[L], lazy_mx[node]+treee[L]);
        treee_mx[R]=max(treee_mx[R], lazy_mx[node]+treee[R]);
        treee[L]+=lazy[node];
        treee[R]+=lazy[node];
        lazy_mx[L]=max(lazy_mx[L], lazy_mx[node]+lazy[L]);
        lazy_mx[R]=max(lazy_mx[R], lazy_mx[node]+lazy[R]);
        lazy[L]+=lazy[node];
        lazy[R]+=lazy[node];
    }
    lazy[node]=lazy_mx[node]=0;
    return;
}

void lazy_update(int node, int st, int en, int l, int r, int val){
    relax(node,st,en);
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        treee[node]+=val;
        lazy[node]+=val;
        treee_mx[node]=max(treee_mx[node], treee[node]);
        lazy_mx[node]=max(lazy_mx[node], lazy[node]);
        return;
    }
    int mid=((en-st)/2)+st;
    lazy_update(2*node, st, mid, l, r, val);
    lazy_update(2*node+1, mid+1, en, l, r, val);
    treee[node]=max(treee[2*node],treee[2*node+1]);
    treee_mx[node]=max(treee_mx[2*node],treee_mx[2*node+1]);
    return;
}

int lazy_query(int node, int st, int en, int l, int r){
    relax(node,st,en);
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){return treee_mx[node];}
    int mid=((en-st)/2)+st;
    int q1= lazy_query(2*node, st, mid, l, r);
    int q2= lazy_query(2*node+1, mid+ 1, en, l, r);
    return max(q1,q2);
}






void solve(int T){
    int n;  cin>>n;
    int q;  cin>>q;
    while(q--){
        int t,l,r;  cin>>t>>l>>r;
        if(t==1){
            int x;  cin>>x;
            lazy_update(1, 1, n, l, r, x);
        }
        else{cout<<lazy_query(1, 1, n, l, r)<<endl;}
    }
}




//DRINK WATER
int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////

    /////////////////////////////////////
    int tc=1;
    //cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}