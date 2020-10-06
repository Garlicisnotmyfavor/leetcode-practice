#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    //维护的三个向量
    vector<int> ans, sz, dp;
    vector<vector<int>> graph;
    //方法一
    void dfs(int u, int f) {
        sz[u] = 1;
        dp[u] = 0;
        //去找U的所有子节点，最孤儿的结点进不来循环直接用上面的值
        for (auto& v: graph[u]) {
            //这里保证不判断到相接的父节点，是一路向下的
            if (v == f) {
                continue;
            }
            dfs(v, u);
            dp[u] += dp[v] + sz[v];
            sz[u] += sz[v];
        }
    }
    //方法二
    void dfs2(int u, int f) {
        ans[u] = dp[u];
        for (auto& v: graph[u]) {
            if (v == f) {
                continue;
            }
            int pu = dp[u], pv = dp[v];
            int su = sz[u], sv = sz[v];

            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            dp[v] += dp[u] + sz[u];
            sz[v] += sz[u];

            dfs2(v, u);

            dp[u] = pu, dp[v] = pv;
            sz[u] = su, sz[v] = sv;
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        ans.resize(N, 0);
        sz.resize(N, 0);
        dp.resize(N, 0);
        graph.resize(N, {});
        //将vector形式的边的性质转化为邻接表状态，方便计数
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};

int main(){
    int N;
    printf("N:\n");
    scanf("%d", &N);
    vector<vector<int>> edges(N-1);
    printf("edges:\n");
    for(int i=0; i<N-1; i++){
        int m, n;
        scanf("%d %d", &m, &n);
        edges[i].push_back(m);
        edges[i].push_back(n);
    }
    Solution so;
    vector<int> result = so.sumOfDistancesInTree(N, edges);
    for(int i=0; i<N; i++)  printf("%d ", result[i]);
}