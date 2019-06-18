# dfs
- [dfs](https://www.hackerearth.com/zh/practice/algorithms/graphs/depth-first-search/tutorial/)
```

DFS-iterative (G, s):                                   //Where G is graph and s is source vertex
    let S be stack
    S.push( s )            //Inserting s in stack 
    mark s as visited.
    while ( S is not empty):
        //Pop a vertex from stack to visit next
        v  =  S.top( )
       S.pop( )
       //Push all the neighbours of v in stack that are not visited   
      for all neighbours w of v in Graph G:
          if w is not visited :
                   S.push( w )         
                  mark w as visited


  DFS-recursive(G, s):
      mark s as visited
      for all neighbours w of s in Graph G:
          if w is not visited:
              DFS-recursive(G, w)

```
- Applications
  - find connected components(leetcode 200)
  ```c++
  // number of islands
  class Solution
  {
  public:
      int numIslands(vector<vector<char>> &grid)
      {
          if (grid.empty())
              return 0;
          int m = grid.size();
          int n = grid[0].size();
          int ans = 0;
          for (int y = 0; y < m; ++y)
              for (int x = 0; x < n; ++x)
              {
                  ans += grid[y][x] - '0';
                  dfs(grid, x, y, m, n);
              }
          return ans;
      }

  private:
      void dfs(vector<vector<char>> &grid, int x, int y, int m, int n)
      {
          if (x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == '0')
              return;
          grid[y][x] = '0';
          dfs(grid, x + 1, y, m, n);
          dfs(grid, x - 1, y, m, n);
          dfs(grid, x, y + 1, m, n);
          dfs(grid, x, y - 1, m, n);
      }
  };
  ```
   - find connected components in graph
  ```c++
    #include <iostream>
     #include <vector>
      using namespace std;

      vector <int> adj[10];
      bool visited[10];

      void dfs(int s) {
          visited[s] = true;
          for(int i = 0;i < adj[s].size();++i)    {
           if(visited[adj[s][i]] == false)
               dfs(adj[s][i]);
          }
      }

      void initialize() {
          for(int i = 0;i < 10;++i)
           visited[i] = false;
      }

      int main() {
          int nodes, edges, x, y, connectedComponents = 0;
          cin >> nodes;                       //Number of nodes
          cin >> edges;                       //Number of edges
          for(int i = 0;i < edges;++i) {
           cin >> x >> y;     
       //Undirected Graph 
           adj[x].push_back(y);                   //Edge from vertex x to vertex y
           adj[y].push_back(x);                   //Edge from vertex y to vertex x
          }

          initialize();                           //Initialize all nodes as not visited

          for(int i = 1;i <= nodes;++i) {
           if(visited[i] == false)     {
               dfs(i);
               connectedComponents++;
           }
          }
          cout << "Number of connected components: " << connectedComponents << endl;
          return 0;
      }

  ```