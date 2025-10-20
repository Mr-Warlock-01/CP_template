///merge tree       //merge tree        //merge tree        //merge tree        //merge tree        //merge tree

int arr[N];
vector<int>m_tree[4*N];

void m_build(int node, int st, int en){
    if(st==en){m_tree[node].push_back(arr[st]); return;}
    int mid=((en-st)/2)+st;
    m_build(2*node, st, mid);
    m_build(2*node+1, mid+1, en);
    int i=0,j=0;
    while(i<m_tree[2*node].size() && j<m_tree[2*node+1].size()){
        if(m_tree[2*node][i] <= m_tree[2*node+1][j]){
            m_tree[node].push_back(m_tree[2*node][i]);      i++;
        }
        else{
            m_tree[node].push_back(m_tree[2*node+1][j]);    j++;
        }
    }
    while(i<m_tree[2*node].size()){
        m_tree[node].push_back(m_tree[2*node][i]);      i++;
    }
    while(j<m_tree[2*node+1].size()){
        m_tree[node].push_back(m_tree[2*node+1][j]);    j++;
    }
    return;
}

int m_query(int node, int st, int en, int l, int r, int val){//count of elemens < val in range [l,r]
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){
        int res= lower_bound( m_tree[node].begin(), m_tree[node].end(), val) - m_tree[node].begin();
        return res;
    }
    int mid=((en-st)/2)+st;
    int q1= m_query(2*node, st, mid, l, r, val);
    int q2= m_query(2*node+1, mid+ 1, en, l, r, val);
    return q1+q2;
}