///2D BIT(point) 		//2D BIT(point) 		//2D BIT(point) 		//2D BIT(point) 

const int N=2502;

struct BIT2D{
    int BIT[N][N];

    int query(int x, int y){
        int ans=0;
        int xx=x;
        while(xx!=0){
            int yy=y;
            while(yy!=0){
                ans+=BIT[xx][yy];
                yy-=(yy&(-yy));
            }
            xx-=(xx&(-xx));
        }
        return ans;
    }

    void update(int x, int y, int val){
        int xx=x;
        while(xx<N){
            int yy=y;
            while(yy<N){
                BIT[xx][yy]+=val;
                yy+=(yy&(-yy));
            }
            xx+=(xx&(-xx));
        }
    }

    void update_range(int x1 ,int y1, int  x2, int y2, int val){
        update(x1, y1, val);
        update(x2+1, y1, -val);
        update(x1, y2+1, -val);
        update(x2+1, y2+1, val);
    }
};
