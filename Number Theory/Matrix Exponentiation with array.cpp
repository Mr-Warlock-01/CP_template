#define int ll
const int N=5;
const int M=1e9+7;

int Seq[N][N]={{1,1,0,2,2},
               {1,0,0,0,0},
               {0,1,0,0,0},
               {0,1,0,0,1},
               {0,0,0,1,0}};

int Pat[N][N]={{2,0,0,0,0},     //f2
               {1,0,0,0,0},     //f1
               {1,0,0,0,0},     //f0
               {1,0,0,0,0},     //f0+
               {0,0,0,0,0}};    //0+

int I[N][N];
int res[N][N];
int temp[N][N];



void mul_I_P(int m_sz){
    for(int i=0; i<m_sz; i++){
        for(int j=0; j<m_sz; j++){
            ll ans=0;
            for(int k=0; k<m_sz; k++){
                ans= (ans + ((I[i][k] * temp[k][j])%M))%M;
            }
            res[i][j]=ans;
        }
    }
    for(int i=0; i<m_sz; i++){
        for(int j=0; j<m_sz; j++){
            I[i][j]=res[i][j];
        }
    }
}

void mul_P_P(int m_sz){
    for(int i=0; i<m_sz; i++){
        for(int j=0; j<m_sz; j++){
            ll ans=0;
            for(int k=0; k<m_sz; k++){
                ans= (ans + ((temp[i][k] * temp[k][j])%M))%M;
            }
            res[i][j]=ans;
        }
    }
    for(int i=0; i<m_sz; i++){
        for(int j=0; j<m_sz; j++){
            temp[i][j]=res[i][j];
        }
    }
}

void mul_I_Pat(int m_sz){
    for(int i=0; i<m_sz; i++){
        for(int j=0; j<m_sz; j++){
            ll ans=0;
            for(int k=0; k<m_sz; k++){
                ans= (ans + ((I[i][k] * Pat[k][j])%M))%M;
            }
            res[i][j]=ans;
        }
    }
}

int matrix_exp(int n, int m_sz){
    for(int i=0; i<m_sz; i++){
        for(int j=0; j<m_sz; j++){
            I[i][j]=0;
        }
    }
    for(int i=0; i<m_sz; i++){I[i][i]=1;}
    for(int i=0; i<m_sz; i++){
        for(int j=0; j<m_sz; j++){
            temp[i][j]=Seq[i][j];
        }
    }
    while(n){
        if(n&1){mul_I_P(m_sz);}
        if(n>0){mul_P_P(m_sz);}
        n>>=1;
    }
    mul_I_Pat(m_sz);
    return res[0][0];
    //final result in res;
}

