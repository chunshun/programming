- 684:Redundant Connection
1042,721
```c++
// 684 
/* 题目中，每个数字代表一个点，定义一个起点与终点的数组begin，begin有2001个元素，begin的下标代表终点，begin的元素代表原始起点（最开始的起点），题目可以化简为找出第一个edge，这个edge的起点和终点都有同样的一个原始起点，即形成环。 begin 的下标为 0 1 2 3 ... ...

初始化后元素为 0 1 2 3

[1 2] 进入后的为 0 1 1 3，2的原始起点更新为1

[1 3] 进入后的为 0 1 1 1，3的原始起点更新为1

[2 3] 进入后，发现2与3的原始起点一致，均为1，发现环。*/

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
  int s=2001;
  vector<int> begin(s);
for(int i=0;i<s;i++){
	begin[i] = i;
}
for(int i=0;i<edges.size();i++)
{
	  int x=edges[i][0];
	  int y=edges[i][1];
                      // cout<<x<<"and"<<y<<endl;
	  if(begin[x] == begin[y])
		  return {x,y};
	  int needUpdate=begin[y];
	  for(int j=0;j<s;j++)
	  {
		    if(begin[j]==needUpdate)
				begin[j]=begin[x];
	  }
}
return edges[0];
  }



// 1042
vector<int> gardenNoAdj(int N, vector<vector<int>> &paths)
{
    using path = vector<int>;
    vector<path> G(N);
    for (auto pa : paths)
    {
        G[pa[0] - 1].push_back(pa[1] - 1);
        G[pa[1] - 1].push_back(pa[0] - 1);
    }
    vector<int> res(N);
    for (int i = 0; i < N; ++i)
    {
        vector<bool> used(5);
        for(auto item:G[i]) used[res[item]]=true;
        for(int j=4;j!=0;--j){
            if(!used[j]) res[i]=j;
        }
    }
    return res;
}

```
```python
# 721 accounts merge
class Solution(object):
    def accountsMerge(self, accounts):
        from collections import defaultdict
        visited_accounts = [False] * len(accounts)
        emails_accounts_map = defaultdict(list)
        res = []
        # Build up the graph.
        for i, account in enumerate(accounts):
            for j in range(1, len(account)):
                email = account[j]
                emails_accounts_map[email].append(i)
        # DFS code for traversing accounts.
        def dfs(i, emails):
            if visited_accounts[i]:
                return
            visited_accounts[i] = True
            for j in range(1, len(accounts[i])):
                email = accounts[i][j]
                emails.add(email)
                for neighbor in emails_accounts_map[email]:
                    dfs(neighbor, emails)
        # Perform DFS for accounts and add to results.
        for i, account in enumerate(accounts):
            if visited_accounts[i]:
                continue
            name, emails = account[0], set()
            dfs(i, emails)
            res.append([name] + sorted(emails))
        return res

```