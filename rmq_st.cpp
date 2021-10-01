#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

namespace RMQ
{
    const int MAXN = 1e5 + 10, MAXLOG = 30;
    int st[MAXN][MAXLOG], logn[MAXN];

    void init(int *arr, int size)
    {
        // 提前计算 logn 的值
        logn[1] = 0;
        logn[2] = 1;
        for (int i = 3; i < MAXN; i++)
            logn[i] = logn[i >> 1] + 1;

        // 初始化 ST 表
        memset(st, 0, sizeof(st));
        for (int i = 1; i <= size; i++)
            st[i][0] = arr[i];
        for (int j = 1; j <= MAXLOG; j++)
            for (int i = 1; i + (1 << j) - 1 <= size; i++)
                st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
    }

    int query(int l, int r)
    {
        int k = logn[r - l + 1];
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }
} // namespace RMQ
