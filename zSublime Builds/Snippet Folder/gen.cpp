#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

mt19937 rng(chrono :: system_clock :: now(). time_since_epoch().count());

int random(int a, int b){
    if (a > b) return 0;
    return a + rng() % (b - a + 1);
}

//^^^^^^^^^^^^^^^NO CHANGE ^^^^^^^^^^^


int32_t main() {
    cout<<1<<endl;
    int n=random(0,1<<29);
    int m=random(0,1<<29);
    cout<<n<<" "<<m;
}

