#include<iostream>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;

const int N = 10;

int n, k;
int a[N];
int sum[N] = { 0 };
int S = 0;

bool tryy(string& m, int i)
{
    if (m.size() == i) {
        //FOR(i, 1, k) if (sum[i - 1] == 0 || sum[i] == 0 || sum[i - 1] != sum[i]) return 0;
        return 1;
    }
    FOR(j, '1', k + '1') {
        m[i] = j;
        sum[m[i] - '1'] += a[i];
        if (sum[m[i] - '1'] > S / k) {
            sum[m[i] - '1'] -= a[i];
            continue;
        }
        if (tryy(m, i + 1)) return 1;
        sum[m[i] - '1'] -= a[i];
    }

    return 0;
}

void solve()
{
    cin >> n >> k;
    FOR(i, 0, n) {
        cin >> a[i];
        S += a[i];
    }
    string m(n, '0');

    if (S % k) {
        cout << "ze";
        return;
    }

    if (tryy(m, 0))
        FOR(i, 0, n) cout << m[i] << " ";
    else
        cout << "ze";
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
