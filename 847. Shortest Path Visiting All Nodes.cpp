// bitmasking 
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        set<pair<int, int>> vis;
        queue<pair<int,pair<int, int>>> queue;
        for(int i = 0; i< graph.size(); i++){
            queue.push({i, {0, (1<<i)}});
            vis.insert({i, (1<<i)});
        }
        while(queue.size() != 0){
            auto n = queue.front();
            queue.pop();
            int node = n.first;
            int dist = n.second.first;
            int nmask = n.second.second;
            for(int i=0; i<graph[node].size(); i++){
                int mask = (nmask | (1<<graph[node][i]));
                if(mask == ((1<<graph.size())-1)){
                    return dist+1;
                }else if(vis.count({graph[node][i], mask})){
                    continue;
                }
                vis.insert({graph[node][i], mask});
                queue.push({graph[node][i], {dist+1, mask}});
            }
        }
        return 0;
    }
};