//Min rotation for lexicographically smallest

int minLex(string &s) {  //return index
    int len=s.length();
    int n=2*len, i=0, j=1, k=0;
    int a, b;
    
    while((i+k<n) && (j+k<n)){
        a=s[(i+k)%len];
        b=s[(j+k)%len];

        if(a==b){k++;} 
        else if(a>b){
            i+=(k+1);
            if(i<=j){i=j+1;} 
            k=0;
        } 
        else{
            j+=(k+1);
            if(j<=i){j=i+1;}
            k=0;
        }
    }
    return min(i, j);
}