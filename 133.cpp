class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        unordered_set<int> set;
        unordered_map<int, UndirectedGraphNode *> set2;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        set.insert(node->label);
        UndirectedGraphNode * root = new UndirectedGraphNode(node->label);
        set2[root->label] = root;
        queue<UndirectedGraphNode *> q_cop;
        q_cop.push(root);
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            auto cur_cop = q_cop.front(); q_cop.pop();
            for(auto neigh : cur->neighbors){
                if(set.find(neigh->label) == set.end()){
                    set.insert(neigh->label);
                    UndirectedGraphNode * nnode = new UndirectedGraphNode(neigh->label);
                    cur_cop->neighbors.push_back(nnode);
                    q_cop.push(nnode);
                    q.push(neigh);
                    set2[neigh->label] = nnode;
                }
                else{
                    cur_cop->neighbors.push_back(set2[neigh->label]);
                }
            }
            
        }
        return root;
    }
};