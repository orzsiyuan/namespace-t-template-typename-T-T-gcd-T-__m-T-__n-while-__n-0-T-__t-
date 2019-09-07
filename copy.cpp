#include <bits/stdc++.h>
using namespace std;
string s;
#define ULL unsigned long long
#define mod 1000000007
ULL n, m, l, r, ans;
ULL ksm(ULL x, ULL y, ULL k)
{
    int base = x;
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
int main()
{
    cin >> s;
    int cnt = 0;
    ULL x = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            cnt++;
            ans += max(ksm(2, s.length() - i - 2, mod), x);
        }
    }
    if (s[s.length() - 1] == '0' && cnt % 2 == 0)
        ans++;
    cout << ans % mod << endl;
    cin >> m;
    while (m--)
    {
        cin >> l >> r;
        ans = 0;
        for (int i = l - 1; i < r; i)
        {
            if (s[i] == '0')
                s[i] = '1';
            else if (s[i] == '1')
                s[i] = '0';
        }
        cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                cnt++;
                ans += max(ksm(2, s.length() - i - 2, mod), x);
            }
        }
        if (s[s.length() - 1] == '0' && cnt % 2 == 0)
            ans++;
        cout << ans % mod << endl;
    }
    return 0;
}