// Approach 1: // USING BFS

class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {1, 0},{0, -1}, {-1, 0},{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        if(n==0 || m==0 || grid[0][0]!=0){
            return -1;
        }
        auto isValid = [&](int x, int y){
            if(x>=0 && x<n && y>=0 && y<m){
                return true;
            }
            return false;
        };
        queue<pair<int, int>> que;
        que.push({0, 0});
        // mark visited
        grid[0][0]=1;
        while(!que.empty()){
            int l = que.size();
            while(l--){
                auto node = que.front();
                que.pop();
                int x = node.first;
                int y = node.second;
                if(x==n-1 && y==m-1){
                    return cnt+1;
                }
                for(auto ngb:directions){
                    int x_d = x+ngb[0];
                    int y_d = y+ngb[1];

                    if(isValid(x_d, y_d) && grid[x_d][y_d]==0){
                        que.push({x_d, y_d});
                        grid[x_d][y_d] = 1;
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};

// Approach: 2
// Using Dijkstra Algo
class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {1, 0},{0, -1}, {-1, 0},{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        if(n==0 || m==0 || grid[0][0]!=0){
            return -1;
        }
        auto isValid = [&](int x, int y){
            if(x>=0 && x<n && y>=0 && y<m){
                return true;
            }
            return false;
        };
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        // minheap
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        res[0][0]=0;
        while(!pq.empty()){
            int d = pq.top().first;
            pair<int, int> node = pq.top().second;
            int x=node.first;
            int y=node.second;
            pq.pop();

            for(auto &ngb:directions){
                int x_d = x+ngb[0];
                int y_d = y+ngb[1];

                // dist=1;
                if(isValid(x_d, y_d) && grid[x_d][y_d]==0 && d + 1 < res[x_d][y_d]){
                    res[x_d][y_d] = d+1;
                    grid[x_d][y_d] = 1;
                    pq.push({d+1, {x_d, y_d}});
                }
            }

        }
        if(res[n-1][m-1]==INT_MAX) return -1;
        return res[n-1][m-1]+1;
        
    }
};
