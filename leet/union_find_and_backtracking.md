# backtracking  
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