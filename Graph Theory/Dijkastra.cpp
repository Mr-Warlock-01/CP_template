///Dijkastra		//Dijkastra			//Dijkastra			//Dijkastra

vector<int>graph[N];
int cost[N];

//set cost to LLMAX

void dijkastra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    //weight,node
    pq.push({0,1});
    cost[1]=0;
    while(!pq.empty()){
        int dis=pq.top().ff;
        int node=pq.top().ss;
        int new_dis=dis+1;
        pq.pop();
 
        if(dis!=cost[node]){continue;}
        
        for(auto u: graph[node]){
            if(cost[0][u]>new_dis){
                cost[0][u]=new_dis;
                pq.push({new_dis,u});
            }
        }
    }
}