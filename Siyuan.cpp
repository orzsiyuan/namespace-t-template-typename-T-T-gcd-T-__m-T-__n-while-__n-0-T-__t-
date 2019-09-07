#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, m, v[N + 5];
char s[N + 5];

void add(int &x, int y)
{
    (x += y) >= MOD && (x -= MOD);
}
int add(int x)
{
    return x >= MOD ? x - MOD : x;
}
int sub(int x)
{
    return x < 0 ? x + MOD : x;
}
template <int MAX>
struct SegmentTree
{
#define lson p << 1
#define rson p << 1 | 1

    static const int N = MAX << 2;

    int ans[N + 5], sum[N + 5];
    bool tag[N + 5];

    void pushUp(int p)
    {
        ans[p] = add(ans[lson] + ans[rson]);
    }
    void update(int p)
    {
        tag[p] ^= 1;
        ans[p] = sub(sum[p] - ans[p]);
    }
    void pushDown(int p)
    {
        if (tag[p])
        {
            update(lson);
            update(rson);
            tag[p] = false;
        }
    }
    void build(int p, int l, int r)
    {
        if (l == r)
        {
            sum[p] = v[l];
            ans[p] = (s[l] == '1' ? v[l] : 0);
            return;
        }
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushUp(p);
        sum[p] = add(sum[lson] + sum[rson]);
    }
    void modify(int p, int l, int r, int x, int y)
    {
        if (x > y)
            return;
        if (x == l && r == y)
            return update(p);
        pushDown(p);
        int mid = (l + r) >> 1;
        if (y <= mid)
        {
            modify(lson, l, mid, x, y);
        }
        else if (x > mid)
        {
            modify(rson, mid + 1, r, x, y);
        }
        else
        {
            modify(lson, l, mid, x, mid);
            modify(rson, mid + 1, r, mid + 1, y);
        }
        pushUp(p);
    }

#undef lson
#undef rson
};

SegmentTree<N> seg;

int main()
{
    scanf("%s%d", s + 1, &m);
    n = strlen(s + 1);
    int end = s[n] - '0', cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt ^= s[i] - '0';
    v[n] = v[n - 1] = 1;
    for (int i = n - 2; i >= 1; i--)
        v[i] = 2LL * v[i + 1] % MOD;
    seg.build(1, 1, n);
    printf("%d\n", seg.ans[1] + (cnt == 0 && end == 0));
    for (int l, r, i = 1; i <= m; i++)
    {
        scanf("%d%d", &l, &r);
        if (l > r)
            std::swap(l, r);
        seg.modify(1, 1, n, l, r);
        if (r == n)
            end ^= 1;
        cnt ^= (r - l + 1) & 1;
        printf("%d\n", seg.ans[1] + (cnt == 0 && end == 0));
    }
    return 0;
}