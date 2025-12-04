//Trie
const int N = 10; // change here
const char base_char = '0';  // change here

struct TrieNode {
    int  cnt;
    TrieNode * nxt[N];
    TrieNode() {
        cnt=0;
        for(int i=0; i<N; i++){ nxt[i] = NULL;}
    }
} *root;

struct Trie{
    TrieNode *root;
    Trie(){root = new TrieNode();}

    void insert(const string &s){
        TrieNode *cur = root;
        int n=s.size();
        for (int i=0; i<n; i++) {
            int idx=s[i]-base_char;
            if((cur -> nxt[idx])== NULL){cur -> nxt[idx] = new TrieNode();}
            cur = cur -> nxt[idx];
        }
        cur->cnt++;
    return;
    }

    bool query(const string &s) { // "s" is a prefix of some element or not
        int n=s.size();
        TrieNode *cur = root;
        for(int i=0; i<n; i++) {
            int idx = s[i] - base_char;
            if (cur -> nxt[idx] == NULL) return 0;
            cur = cur -> nxt[idx];
        }
        if(cur->cnt!=1){return 0;}
        for(int i=0; i<N; i++){
            if(cur->nxt[i] != NULL){return 0;}
        }
        return 1;
    }

    void rem(string &s, int pos){
        rem(root, x, pos);
    }

    void rem(TrieNode *cur, string &s, int pos) {
        if(pos==s.size()){return;}
        int idx=s[pos]-base_char;
        rem(cur->nxt[idx], s, pos+1);
        cur->nxt[idx]->cnt--;
        if(cur->nxt[idx]->cnt==0) {
            free(cur->nxt[idx]);
            cur->nxt[idx]=NULL;
        }
    return;
    }

    ~Trie() {
        del(root);
    }

    void del(TrieNode *cur) {
        for(int i=0; i<N; i++){
            if(cur->nxt[i]!=NULL){del(cur->nxt[i]);}
        }
        delete(cur);
    return;
    }
};

//main function
    /*Trie root;*/