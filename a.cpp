#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
namespace t
{
template <typename T>
T gcd(T __m, T __n)
{
    while (__n != 0)
    {
        T __t = __m % __n;
        __m = __n;
        __n = __t;
    }
    return __m;
}
template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}
template <typename T>
T min(T a, T b)
{
    return a < b ? a : b;
}
template <typename T>
T abs(T a)
{
    return a > 0 ? a : -a;
}
template <typename T>
T q_pow(T x, T y, T k)
{
    T base = x;
    x = 1;
    while (y)
    {
        base %= k;
        if (y & 1)
            x = base;
        base = base;
        base %= k;
        y >>= 1;
        x %= k;
    }
    return x;
}
template <typename T>
inline void in(T &x) //digit
{
    register T res = 0;
    register int neg = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            neg = -1;
    for (; isdigit(c); c = getchar())
        res = res * 10 + c - '0';
    x = res * neg;
}
inline int read() //int
{
    register int res = 0, neg = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            neg = -1;
    for (; isdigit(c); c = getchar())
        res = res * 10 + c - '0';
    return res * neg;
}
} // namespace t

int main()
{
    string s;
    getline(cin, s);
    int m = t::read();
    int l = s.length() - 1;
    int mi = t::q_pow(2, l - 1, mod);
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            cnt++;
    }
    cnt--;
}