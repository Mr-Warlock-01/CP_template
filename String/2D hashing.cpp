///2D Hashing           //2D Hashing           //2D Hashing           //2D Hashing           //2D Hashing           //2D Hashing


int arr[N][N];
int hash_1[N][N];
int hash_2[N][N];
int p1=137, q1=277, M1=14457881;
int p2=455, q2=541, M2=11457857;
int p1_d_b, q1_c_a;
int p2_d_b, q2_c_a;

int n,m;

void build_hash(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            hash_1[i][j]=( ((hash_1[i-1][j]*q1)%M1) + ((hash_1[i][j-1]*p1)%M1) - ((hash_1[i-1][j-1]*p1*q1)%M1) + (arr[i][j]) )%M1;
            hash_2[i][j]=( ((hash_2[i-1][j]*q2)%M2) + ((hash_2[i][j-1]*p2)%M2) - ((hash_2[i-1][j-1]*p2*q2)%M2) + (arr[i][j]) )%M2;
            hash_1[i][j]=(hash_1[i][j]+M1)%M1;
            hash_2[i][j]=(hash_2[i][j]+M2)%M2;
        }
    }
}

pair<int,int>find_hash(int a, int b, int c, int d){
    //(a+1,b+1) to (c,d)   
    int h_1=( hash_1[c][d] - ((hash_1[a][d]*q1_c_a)%M1) - ((hash_1[c][b]*p1_d_b)%M1) + ((hash_1[a][b] * ((q1_c_a*p1_d_b)%M1))%M1) )%M1;  
    int h_2=( hash_2[c][d] - ((hash_2[a][d]*q2_c_a)%M2) - ((hash_2[c][b]*p2_d_b)%M2) + ((hash_2[a][b] * ((q2_c_a*p2_d_b)%M2))%M2) )%M2; 
    h_1=(h_1+M1)%M1; 
    h_2=(h_2+M2)%M2; 
    return {h_1,h_2};
}

    //take input as int not char
    /*
    p1_d_b=powMod(p1, d-b, M1);
    q1_c_a=powMod(q1, c-a, M1);
    p2_d_b=powMod(p2, d-b, M2);
    q2_c_a=powMod(q2, c-a, M2);

    */
