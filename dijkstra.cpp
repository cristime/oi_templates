#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
using namespace std;

inline int read();

namespace Dijkstra
{
    const int MAXN = 5e5 + 10;
    vector<pair<int, int>> g[MAXN];
    int dis[MAXN], vis[MAXN], n, m, s;

    void init()
    {
        n = read();
        m = read();
        s = read();
        for (int i = 1; i <= m; i++)
        {
            int u = read(), v = read(), w = read();
            g[u].push_back(make_pair(v, w));
            g[v].push_back(make_pair(u, w));
        }
    }

    void dijkstra()
    {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));
        dis[s] = 0;
        for (int i = 1; i <= n; i++)
        {
            int u = 0, mind = 0x3f3f3f3f;
            for (int j = 1; j <= n; j++)
                if (!vis[j] && dis[j] < mind)
                    u = j, mind = dis[j];
            vis[u] = 1;
            for (auto &ed : g[u])
            {
                int v = ed.first, w = ed.second;
                if (dis[v] > dis[u] + w)
                    dis[v] = dis[u] + w;
            }
        }
    }
} // namespace Dijkstra
