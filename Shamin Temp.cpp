

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};

ll gcd(ll a, ll b){if(b==0){return a;} else{return gcd(b,a%b);}}
ll lcm(ll a, ll b){return ((a/gcd(a,b))*b);}

ll countDigit(ll n){return floor(log10(n) + 1);}

ll log_base_n(double n, double b){return (ll)(log2(n)/log2(b));}

//int lastbit(int n){bitset<64>x(n); for(int i=63; i>=0; i--)if(x[i]==1)return i; return 0;}



int BigMul(int a,int b, int M){int x=0; int y=a%M;while(b){if(b%2==1){x=(x+y)%M;}y=(y+y)%M;b/=2;}return x;}
/////////////////
ll powMod(ll x, ll n){ll res=1; while(n){if(n&1){res=(res*x);} x=(x*x); n>>=1;} return res;}
ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
ll invMod(ll x, ll M){return powMod(x, M-2, M);}
/////////////////

ll digitSum(ll a){ll sum=0; for(ll i=a; i>0; i/=10){sum+=(i%10);} return sum;}

ll coprime(ll n){ll ans=n; for(ll i=2; i*i<=n; i++){ if(n%i==0){ans/=i; ans*=(i-1); while(n%i==0){n/=i;}}}if(n>1){ ans/=n; ans*=(n-1);} return ans;}

ll Count_One(ll n){int count = 0; while (n) {count++; n = n & (n - 1);} return count;}

//int lastSetBit(int n) {bitset<64>x(n); for (int i = 63; i >= 0; i--)if (x[i] == 1)return i; return 0;}//(n&(-n))

bool isPalindrome(string s){int i=0, j=s.size()-1; for(i, j; i<=j; i++, j--){if(s[i]!=s[j]) return 0;} return 1;}

bool IsPrime(ll n){for(ll i=2; i*i<= n; i++) if((n%i)==0){return false;} return true;}

