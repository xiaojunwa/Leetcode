62. Unique Paths
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:

Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


class Solution {
public:
    //Method 1: BFS
    int uniquePaths(int m, int n) {
        vector<vector<int>> graph(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> que;
        
        graph[0][0] = 1;
        visited[0][0] = true;
        que.push(make_pair(0,0));
        
        while(!que.empty()){
            pair<int,int> p = que.front();
            que.pop();
            if((p.first + 1) < m) {
                graph[p.first + 1][p.second] += graph[p.first][p.second];
                if(!visited[p.first+1][p.second]) que.push(make_pair(p.first + 1, p.second));
                visited[p.first + 1][p.second] = true;
            }
            if((p.second + 1) < n) {
                graph[p.first][p.second + 1] += graph[p.first][p.second];
                if(!visited[p.first][p.second+1]) que.push(make_pair(p.first, p.second + 1));
                visited[p.first][p.second + 1] = true;
            }
        }
        
        return graph[m-1][n-1];
    }
    
    //Method 2: DP
    int uniquePaths(int m, int n) {  
        if(m == 0 || n == 0)  return 0;  
        int **dp = new int*[m];  
        for(int i = 0; i < m; i++)  dp[i] = new int[n];  
 
        dp[0][0] = 1;  
        for(int i = 1; i < m; i++)   dp[i][0] = 1;  
        for(int j = 1; j < n; j++)   dp[0][j] = 1;  
        
        for(int i = 1; i < m; i++) 
            for(int j = 1; j < n; j++)  
                dp[i][j] = dp[i][j-1] + dp[i-1][j];  
 
        int res = dp[m-1][n-1];  
        for(int i = 0; i < m; i++)  delete [] dp[i];  
          
        delete [] dp;  
        return res;  
    }

};
