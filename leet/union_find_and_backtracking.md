# backtracking  
- reference:https://www.geeksforgeeks.org/backtracking-introduction/
  1. Pseudo Code for Backtracking :
  ```
     void findSolutions(n, other params) :
         if (found a solution) :
             solutionsFound = solutionsFound + 1;
             displaySolution();
             if (solutionsFound >= solutionTarget) : 
                 System.exit(0);
             return

         for (val = first to last) :
             if (isValid(val, n)) :
                 applyValue(val, n);
                 findSolutions(n+1, other params);
                 removeValue(val, n);
  ```
  2. Finding whether a solution exists or not
  ```
     boolean findSolutions(n, other params) :
         if (found a solution) :
             displaySolution();
             return true;

         for (val = first to last) :
             if (isValid(val, n)) :
                 applyValue(val, n);
                 if (findSolutions(n+1, other params))
                     return true;
                 removeValue(val, n);
             return false;
  ```
- 打印矩阵左上角到右下角的所有可能路径
```python
# Python3 program to Print all possible paths from 
# top left to bottom right of a mXn matrix 
allPaths = [] 
def findPaths(matrix,m,n): 
	path = [0 for d in range(m+n-1)] 
	findPathsUtil(matrix,m,n,0,0,path,0) 
	
def findPathsUtil(matrix,m,n,i,j,path,indx): 
	global allPaths 
	# if we reach the bottom of matrix, we can only move right 
	if i==m-1: 
		for k in range(j,n): 
			#path.append(matrix[i][k]) 
			path[indx+k-j] = matrix[i][k] 
		# if we hit this block, it means one path is completed. 
		# Add it to paths list and print 
		print(path) 
		allPaths.append(path) 
		return
	# if we reach to the right most corner, we can only move down 
	if j == n-1: 
		for k in range(i,m): 
			path[indx+k-i] = matrix[k][j] 
		#path.append(matrix[j][k]) 
		# if we hit this block, it means one path is completed. 
		# Add it to paths list and print 
		print(path) 
		allPaths.append(path) 
		return
	
	# add current element to the path list 
	#path.append(matrix[i][j]) 
	path[indx] = matrix[i][j] 
	
	# move down in y direction and call findPathsUtil recursively 
	findPathsUtil(matrix, m, n, i+1, j, path, indx+1) 
	
	# move down in y direction and call findPathsUtil recursively 
	findPathsUtil(matrix, m, n, i, j+1, path, indx+1) 

if __name__ == '__main__': 
	matrix = [[1,2,3], 
			[4,5,6], 
			[7,8,9]] 
	findPaths(matrix,3,3) 
	#print(allPaths) 
```
- leetcode131 Palindrome Partitioning
```c++
/* Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
] */
class Solution
{
public:
    vector<vector<string>> result;
    vector<string> list;
	
    vector<vector<string>> partition(string s)
    {
        if (s.size() == 0)
            return result;
        // 进行回溯搜索
        search(s, 0);
        return result;
    }
    // 回溯搜索
    void search(string s, int n)
    {
        if (n == s.size())
        {
            // 搜索结束
            result.push_back(list);
            return;
        }
        for (int i = n; i < s.size(); ++i)
        {
            string sub = s.substr(n, i - n + 1);
            if (isPartition(sub))
            {
                list.push_back(sub);
                search(s, i + 1);
                list.pop_back();
            }
        }
    }
    bool isPartition(string str)
    {
        for (int i = 0, j = str.size() - 1; i <= j; ++i, --j)
        {
            if (str.at(i) != str.at(j))
            {
                return false;
            }
        }
        return true;
    }
};

```
- permutation
```python
class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        visited = [0] * len(nums)
        res = []
        
        def dfs(path):
            if len(path) == len(nums):
                res.append(path)
            else:
                for i in range(len(nums)):
                    if not visited[i]:
                        visited[i] = 1
                        dfs(path + [nums[i]])
                        visited[i] = 0
        
        dfs([])
        return res
```

```c++
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        const int N = nums.size();
        vector<vector<int>> res;
        vector<int> path;
        vector<int> visited(N, 0);
        
        dfs(nums, 0, visited, res, path);
        return res;
    }

private:
    void dfs(vector<int> &nums, int pos, vector<int> &visited, vector<vector<int>> &res, vector<int> &path)
    {
        const int N = nums.size();
        if (pos == N)
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                path.push_back(nums[i]);
                dfs(nums, pos + 1, visited, res, path);
                path.pop_back();
                visited[i] = 0;
            }
        }
    }
};
```

# union-find
```c++
class DSU
{
public:
    DSU(int size) : size_(size), parent_(size), ranks_(size)
    {
        iota(begin(parent_), end(parent_), 0);
    }

    int Find(int n)
    {
        if (parent_[n] != n)
            parent_[n] = Find(parent_[n]);
        return parent_[n];
    }

    void Union(int x, int y)
    {
        int px = Find(x);
        int py = Find(y);
        if (px == py)
            return;
        if (ranks_[py] > ranks_[px])
            swap(px, py);
        else if (ranks_[py] == ranks_[px])
            ++ranks_[px];
        parent_[py] = px;
        --size_;
    }

    int Size() const
    {
        return size_;
    }

private:
    int size_;
    vector<int> ranks_;
    vector<int> parent_;
};

```

- Application
    - leetcode 839:similar-string-groups
    ```c++
    class Solution
    {
    public:
      int numSimilarGroups(vector<string> &A)
      {
          DSU dsu(A.size());
          for (int i = 0; i < A.size(); ++i)
              for (int j = i + 1; j < A.size(); ++j)
                  if (similar(A[i], A[j]))
                      dsu.Union(i, j);
          return dsu.Size();
      }

    private:
        bool similar(const string &a, const string &b)
        {
            int diff = 0;
            for (int i = 0; i < a.length(); ++i)
                if (a[i] != b[i] && ++diff > 2)
                    return false;
            return true;
        }
    };
    ```
