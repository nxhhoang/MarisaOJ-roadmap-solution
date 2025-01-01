#include<iostream>
#include<iomanip>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;

const int N = 10;

int n, m;
int a[7][7] = { 0 };
int r[49] = { 0 };
int c[49] = { 0 };

bool tryy(int k)
{
    if (k == n * m) {
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                cout << setw(3) << a[i][j];
            }
            cout << endl;
        }
        return true;
    }

    FOR(i, 0, n) FOR(j, 0, m) {
        if (a[i][j] != 0) continue;
        if (k != 0 && (r[k - 1] - i) * (r[k - 1] - i) + (c[k - 1] - j) * (c[k - 1] - j) != 5) continue;
        a[i][j] = k + 1;
        r[k] = i;
        c[k] = j;
        if (tryy(k + 1)) return true;
        a[i][j] = 0;
        r[k] = c[k] = 0;
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    if (tryy(0) == 0) {
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                cout << setw(3) << 0;
            }
            cout << endl;
        }
    }
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
