#include<bits/stdc++.h>
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
int rrr[] = { -1,  -2,  -2,  -1,  +1,  +2,  +2,  +1 };
int ccc[] = { -2,  -1,  +1,  +2,  +2,  +1,  -1,  -2 };

bool tryy(int i, int j, int k) {

    if (k == n * m) {
        FOR(u, 0, n) {
            FOR(v, 0, m) {
                cout << setw(3) << a[u][v];
            }
            cout << endl;
        }
        return true;
    }

    FOR(u, 0, 8) {
        int aa = i + rrr[u];
        int bb = j + ccc[u];
        if (aa < 0 || aa >= n || bb < 0 || bb >= m) continue;
        if (a[aa][bb] != 0) continue;
        a[aa][bb] = k + 1;
        if (tryy(aa, bb, k + 1)) return true;
        a[aa][bb] = 0;
        aa -= rrr[u];
        bb -= ccc[u];
    }

    return false;
}

void solve()
{
    cin >> n >> m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            a[i][j] = 1;
            if (tryy(i, j, 1)) return;
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
