# bfs
- [bfs](https://www.hackerearth.com/zh/practice/algorithms/graphs/breadth-first-search/tutorial/)
```
BFS (G, s)                   //Where G is the graph and s is the source node
      let Q be queue.
      Q.enqueue( s ) //Inserting s in queue until all its neighbour vertices are marked.

      mark s as visited.
      while ( Q is not empty)
           //Removing that vertex from queue,whose neighbour will be visited now
           v  =  Q.dequeue( )

          //processing all the neighbours of v  
          for all neighbours w of v in Graph G
               if w is not visited 
                        Q.enqueue( w )             //Stores w in Q to further visit its neighbour
                        mark w as visited.
```
- Applications
  - How to determine the level of each node in the given tree?(leetcode 1091. Shortest Path in Binary Matrix)
  ```python
  class Solution:
      def shortestPathBinaryMatrix(self, nums: List[List[int]]) -> int:
          if nums[0][0] or nums[-1][-1]:
              return -1
          m,n=len(nums),len(nums[0])
      
          level=[[0 for __ in range(n)]for __ in range(m)]
          queue=[(0,0) ]
          nums[0][0]=1
          while queue:
              v=queue.pop(0) 
              neighbors=[(v[0]+i,v[-1]+j) for i,j in [(a,b) for a in [-1,0,1] for b in [-1,0,1] if not a==b==0] if 0<=v[0]+i<m and 0<=v[1]+j<n and not nums[v[0]+i][v[1]+j]]
              for node in neighbors:
                  queue.append(node)
                  # visited[node[0]][node[-1]]=True
                  level[node[0]][node[1]]=level[v[0]][v[1]]+1
                  nums[node[0]][node[1]]=1
          return level[-1][-1]+1 if nums[-1][-1]==1 else -1
  ```
  - leetcode 994:rotting-oranges
  ```c++
  class Solution {
  public:
      int orangesRotting(vector<vector<int>>& grid) {
          const int m = grid.size();
          const int n = grid[0].size();
          queue<pair<int, int>> q;
          int fresh = 0;

          for (int i = 0; i < m; ++i)
              for (int j = 0; j < n; ++j)
                  if (grid[i][j] == 1)
                      ++fresh;
                  else if (grid[i][j] == 2)
                      q.emplace(j, i);
          
          vector<int> dirs = {1, 0, -1, 0, 1};

          int days = 0;
          while (!q.empty() && fresh)
          {
              int size = q.size();
              while (size--)
              {
                  int x = q.front().first;
                  int y = q.front().second;
                  q.pop();
                  for (int i = 0; i < 4; ++i)
                  {
                      int dx = x + dirs[i];
                      int dy = y + dirs[i + 1];
                      if (dx < 0 || dx >= n || dy < 0 || dy >= m || grid[dy][dx] != 1)
                          continue;
                      --fresh;
                      grid[dy][dx] = 2;
                      q.emplace(dx, dy);
                  }
              }
              ++days;
          }
          return fresh ? -1 : days;
      }
  };
  ```
  - find the shortest distance between connected components(both in dfs and bfs):leetcode 934 shortest-bridge
    ```c++
    class Solution
    {
    public:
      int shortestBridge(vector<vector<int>> &A)
      {
          queue<pair<int, int>> q;
          bool found = false;
          for (int i = 0; i < A.size() && !found; ++i)
              for (int j = 0; j < A[0].size() && !found; ++j)
                  if (A[i][j])
                  {
                      dfs(A, j, i, q);
                      found = true;
                  }
          int steps = 0;
          vector<int> dirs{0, 1, 0, -1, 0};
          while (!q.empty())
          {
              size_t size = q.size();
              while (size--)
              {
                  int x = q.front().first;
                  int y = q.front().second;
                  q.pop();
                  for (int i = 0; i < 4; ++i)
                  {
                      int tx = x + dirs[i];
                      int ty = y + dirs[i + 1];
                      if (tx < 0 || ty < 0 || tx >= A[0].size() || ty >= A.size() || A[ty][tx] == 2)
                          continue;
                      if (A[ty][tx] == 1)
                          return steps;
                      A[ty][tx] = 2;
                      q.emplace(tx, ty);
                  }
              }
              ++steps;
          }
          return -1;
      }

    private:
      void dfs(vector<vector<int>> &A, int x, int y, queue<pair<int, int>> &q)
      {
          if (x < 0 || y < 0 || x >= A[0].size() || y >= A.size() || A[y][x] != 1)
              return;
          A[y][x] = 2;
          q.emplace(x, y);
          dfs(A, x - 1, y, q);
          dfs(A, x, y - 1, q);
          dfs(A, x + 1, y, q);
          dfs(A, x, y + 1, q);
      }
    };
    ```