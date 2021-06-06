/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node == NULL) return NULL;
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
    queue<UndirectedGraphNode*> bfs;
    UndirectedGraphNode* x;
    bfs.push(node);
    while(!bfs.empty()) {
       x = bfs.front();
       bfs.pop();
       if(visited.find(x) == visited.end()) {
           UndirectedGraphNode* tmp = new UndirectedGraphNode(x -> label);
           visited.insert({x, tmp});
           for(int i = 0; i < (x -> neighbors).size(); i++) {
                if(visited.find((x -> neighbors)[i]) == visited.end()) 
                    bfs.push((x -> neighbors)[i]);
           }
       }
    }
    for(auto i = visited.begin(); i != visited.end(); i++) {
        x = i -> first;
        for(int j = 0; j < (x -> neighbors).size(); j++) {
            (i-> second -> neighbors).push_back(visited[(x -> neighbors)[j]]);
        }
    }
    return visited[node];   
}