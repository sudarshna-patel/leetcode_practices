// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    // ============Backtracking===============
//     void dfsUtil(vector<vector<int>>& graph, vector<vector<int>>& results, vector<int>& path, int v) {
//         path.push_back(v);
        
//         if (v == graph.size()-1)
//             results.push_back(path);
//         else
//             for (auto u : graph[v])
//                 dfsUtil(graph, results, path, u);
        
//         path.pop_back();
//     }
    
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         vector<vector<int>> results;
//         vector<int> path;
        
//         dfsUtil(graph, results, path, 0);
        
//         return results;
//     }
    
    // =================simple dfs and recursion===================
    void dfs (vector<vector<int>>& graph, vector<vector<int>>& results, vector<int> path, int v) {
        path.push_back(v);
        
        if (v == graph.size() - 1) {
            results.push_back(path);
            return;
        } else
            for (auto u : graph[v])
                dfs(graph, results, path, u);
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> results;
        
        if (graph.size() == 0) return results;
        
        vector<int> path;
        
        dfs(graph, results, path, 0);
        
        return results;
    }
};