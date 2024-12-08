class Solution {
public:
    void dfs (Node* copy , Node* node , vector<Node*>&vis ){
        vis[copy-> val] = copy ;
        for (auto it : node -> neighbors){
            if (vis[it -> val] == NULL){
                Node* newNode = new Node(it -> val);
                (copy->neighbors) .push_back(newNode);
                dfs (newNode, it , vis);
            }
            else {
                (copy -> neighbors).push_back(vis[it ->val]) ;
            }
        }
    }

    Node* cloneGraph(Node* node) {
         if(node == nullptr) return nullptr;
        vector<Node*> vis(1000 , NULL) ;
        Node* copy = new Node(node -> val);
        dfs (copy , node , vis );
        return copy ; 
    }
};