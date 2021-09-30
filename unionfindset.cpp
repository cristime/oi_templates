namespace UnionFindSet
{
    const int MAXN = 1e5 + 10;
    int fa[MAXN];

    void init(const int n)
    {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }

    int find(int x)
    {
        int r = x;
        while (r != fa[r])
            r = fa[r];
        while (r != x)
        {
            int p = fa[x];
            fa[x] = r;
            x = p;
        }
        return r;
    }

    void merge(const int u, const int v)
    {
        int fu = find(u), fv = find(v);
        if (fu != fv)
            fa[fu] = fv;
    }
} // namespace UnionFindSet
