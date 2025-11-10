///Dijkastra		//Dijkastra			//Dijkastra			//Dijkastra

vector<int>graph[N];
int main_cost[N];

//set cost to LLMAX
for(int i=0; i<N; i++){main_cost[i]=LLMax;}

void dijkastra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    //cost,node

    main_cost[source]=0;
    pq.push({0,source});

    while(!pq.empty()){
        auto [cost, node]=pq.top();
        pq.pop();
        if(cost!=main_cost[node]){continue;}
        for(auto [u,w]: graph[node]){
            int new_cost=cost+w;
            if(main_cost[u]>new_cost){
                main_cost[u]=new_cost;
                pq.push({new_cost,u});
            }
        }
    }
}