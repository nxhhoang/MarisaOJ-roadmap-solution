#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using ll = long long;
using namespace std;

const int N = 10;

void solve()
{
    string S;
    cin >> S;
    vector<int> a(2*S.size(), 0);
    int sum = 0;
    FOR(i, 0, S.size()) {
        if (S[i] == '0') sum--;
        else sum++;
        a[sum + (int)S.size()]++;
    }
    ll cnt = 0;
    FOR(i, 0, S.size()) {
        if (i == 0) cnt += a[int(S.size())];
        cnt += a[i + int(S.size())] * (a[i + int(S.size())] - 1) / 2;
        cnt += a[i] * (a[i] - 1) / 2;
    }
    cout << cnt << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
