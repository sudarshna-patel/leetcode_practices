// https://leetcode.com/problems/course-schedule-ii/

class Solution {

private:
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        for (auto p : prerequisites)
            graph[p[1]].push_back(p[0]);

        return graph;
    }
    
    //Graph coloring: 0->not visited...1->visited...2->visited & processed
    bool detectCycle_util(vector<vector<int>>& graph, vector<int>& visited, int v) {
        if(visited[v] == 1)
            return true;
        
        if(visited[v] == 2)
            return false;
        
        visited[v] = 1;   //Mark current as visited
        for(int i = 0; i < graph[v].size(); ++i)
            if(detectCycle_util(graph, visited, graph[v][i]))
                return true;
        
        visited[v] = 2;   //Mark current node as processed
        
        return false;
    }
    
    bool detectCycle(vector<vector<int>>& graph, int numCourses) {
        vector<int> visited(numCourses, 0);
        
        for(int i = 0; i < numCourses; ++i)
            if(!visited[i])
                if(detectCycle_util(graph, visited, i))
                    return true;
        
        return false;
    }
    
    //Topological sort
    void dfs(vector<vector<int>>& graph, int v, vector<bool>& visited, stack<int>& mystack) {
        visited[v] = true;
        
        for(int i = 0; i < graph[v].size(); ++i)
            if(!visited[graph[v][i]])
                dfs(graph, graph[v][i], visited, mystack);
        
        mystack.push(v);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        
        //Detect CYCLE...If present then return empty array
        vector<int> ans;
        if(detectCycle(graph, numCourses))
            return ans;
        
        //Find toposort and store it in stack
        stack<int> mystack;
        vector<bool> visited(numCourses, false);
        
        //Apply DFS and find topological sort
        for(int i = 0; i < numCourses; ++i)
            if(!visited[i])
                dfs(graph, i, visited, mystack);
        
        while(!mystack.empty()) {
            ans.push_back(mystack.top());
            mystack.pop();
        }
        
        return ans;
    }
};