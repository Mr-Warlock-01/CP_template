#define int ll
const int N=16;
const int M=1e9+7;

using Matrix = array<array<ll, N>, N>;

Matrix matrix_mul(Matrix &A, Matrix &B, int M_sz) {
    Matrix res = {};
    for(int i=0; i<M_sz; i++){
        for(int j=0; j<M_sz; j++){
            for(int k=0; k< M_sz; k++){
                res[i][j] = (res[i][j] + ((A[i][k] * B[k][j]) % M)) % M;
            }
        }
    }
    return res;
}

Matrix matrix_pow(Matrix mat, int n, int M_sz) {
    Matrix res = {};
    for(int i=0; i<M_sz; i++){res[i][i]=1;}
    while(n){
        if(n&1){res = matrix_mul(res, mat, M_sz);}
        if(n>0){mat = matrix_mul(mat, mat, M_sz);}
        n>>=1;
    }
    return res;
}



//-----------in main-----------------
	Matrix Seq={{}};
	Matrix Pat={{}};  //need only [0][N] size
	////build Seq
	//for(int i=0; i<(d-1); i++){Seq[i+1][i]=1;}
	//for(int i=0; i<d; i++){Seq[0][i]=a[i]%M;}
	//for(int i=0; i<d; i++){Pat[d-i-1][0]=f[i]%M;}
	Seq = matrix_pow(Seq, n-1, sz);
	Matrix res = matrix_mul(Seq, Pat, sz);
	cout<<res[0][0]<<endl;