#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

namespace LCA
{
    const int MAXN = 1e5 + 10, MAXLOG = 30;
    int deep[MAXN], fa[MAXN][MAXLOG];
    vector<int> g[MAXN];

    void buildtree(const int root, const vector<pair<int, int>> &v)
    {
        memset(deep, 0, sizeof(deep));
        for (auto &el : v)
        {
            g[el.first].push_back(el.second);
            g[el.second].push_back(el.first);
        }
    }

    void dfs(int u, int father)
    {
        deep[u] = deep[father] + 1;
        fa[u][0] = father;
        for (auto &v : g[u])
        {
            if (v == father)
                continue;
            dfs(v, u);
        }
    }

    void init(const int n, const int root, const vector<pair<int, int>> &v)
    {
        buildtree(root, v);
        dfs(root, 0);
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i <= n; i++)
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }

    int query(int u, int v)
    {
        if (deep[u] < deep[v])
            swap(u, v);
        for (int i = MAXLOG; i >= 0; i--)
            if ((1 << i) <= deep[u] - deep[u])
                u = fa[u][i];
        if (u == v)
            return u;
        for (int i = MAXLOG; i >= 0; i--)
            if (fa[u][i] != fa[v][i])
            {
                u = fa[u][i];
                v = fa[v][i];
            }
        return fa[u][0];
    }
} // namespace LCA
