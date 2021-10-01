namespace SegmentTree
{
    const int MAXN = 1e5 + 10;
    int tree[MAXN << 2], tag[MAXN << 2];

    // 左孩子和右孩子
    inline int lson(const int k) { return k << 1; }
    inline int rson(const int k) { return (k << 1) + 1; }

    inline void pushup(const int k)
    {
        tree[k] = tree[lson(k)] + tree[rson(k)];
    }
    inline void pushdown(const int p, const int l, const int r)
    {
        const int mid = l + (r - l >> 1);
        tree[lson(p)] += (mid - l + 1) * tag[p];
        tree[rson(p)] += (r - mid) * tag[p];
        tag[lson(p)] += tag[p];
        tag[rson(p)] += tag[p];
        tag[p] = 0;
    }

    // 建树
    void buildtree(int *arr, int l, int r, int p)
    {
        if (l == r)
        {
            tree[p] = arr[l];
            return;
        }
        int mid = l + (r - l >> 1);
        buildtree(arr, l, mid, lson(p));
        buildtree(arr, mid + 1, r, rson(p));
        pushup(p);
    }

    // 区间修改
    void update(int l, int r, int s, int t, int delta, int p)
    {
        // [l, r] 为修改区间, c 为被修改的元素的变化量, [s, t] 为当前节点包含的区间, p
        // 为当前节点的编号
        if (l <= s && t <= r)
        {
            tree[p] += (t - s + 1) * delta;
            tag[p] += delta;
            return;
        }
        int mid = s + (t - s >> 1);
        if (tag[p] && s != t)
            pushdown(p, s, t);
        if (l <= mid)
            update(l, r, s, mid, delta, lson(p));
        if (r > mid)
            update(l, r, mid + 1, t, delta, rson(p));
        pushup(p);
    }

    // 区间查询
    int query(int l, int r, int s, int t, int p)
    {
        if (l <= s && t <= r)
            return tree[p];
        int mid = s + (t - s >> 1), sum = 0;
        if (tag[p])
            pushdown(p, s, t);
        if (l <= mid)
            sum += query(l, r, s, mid, lson(p));
        if (r > mid)
            sum += query(l, r, mid + 1, t, rson(p));
        return sum;
    }
}