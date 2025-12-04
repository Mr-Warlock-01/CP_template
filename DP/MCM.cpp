//Matrix Chain Multiplication
const int N=100;
int arr[N];
int dp[N][N];

int MCM(int n){ //pass matrix count
    n++;
    for(int len=2; len<n; len++){
        for(int i=0; i<(n-len); i++){
            int j=i+len;
            dp[i][j] = INT_MAX;
            for(int k=i+1; k<j; k++){
                int cost = dp[i][k] + dp[k][j] + (arr[i] * arr[k] * arr[j]);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}