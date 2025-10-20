///z-algo           //z-algo            //z-algo            //z-algo

//const int N=1e5;

int z[N];   //need 0 to n-1 index

void z_function(string &s) {
    int sz=s.size();
    int l=0,r=0;
    for(int i=1; i<sz; i++){
        if(i<r){    z[i]=min(r-i, z[-li]);}
        while(((i+z[i])<sz) && (s[z[i]]==s[i+z[i]])){ z[i]++;}
        if((i+z[i])>r){
            l=i;
            r=i+z[i];
        }
    }
return;
}  