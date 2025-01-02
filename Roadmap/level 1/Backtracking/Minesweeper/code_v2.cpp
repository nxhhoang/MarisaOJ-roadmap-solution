#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using ll = long long;
using namespace std;

const int N = 20;

int n, m;
int a[N][N];
short mine[N][N] = { 0 };
int dx[] = { -1, 0, 0, 1, -1, 1, -1, 1};
int dy[] = { 0, -1, 1, 0, -1, 1, 1, -1};

bool isValid(int r, int c) {
    int sum = 0;
    FOR(k, 0, 8) {
        int rrr = r + dx[k];
        int ccc = c + dy[k];
        if (rrr < 0 || rrr >= n || ccc < 0 || ccc >= m) continue;
        sum += mine[rrr][ccc];
    }
    if (sum != a[r][c]) return false;
    else return true;
}

bool checkCon(int can_r, int can_c) {
    if (can_r > 1) FOR(c, 0, m) if (!isValid(can_r - 2, c)) return false;
    if (can_r > 0) FOR(c, 0, can_c - 1) if (!isValid(can_r - 1, c)) return false;
    return true;
}

bool tryy(int r, int c) {
    if (r == n) {
        if (!checkCon(r + 1, c)) return 0;
        FOR(i, 0, n) {
            FOR(j, 0, m) cout << mine[i][j] << " ";
            cout << endl;
        }
        return 1;
    }
    if (!checkCon(r, c)) return 0;

    for (int k = 1; k >=0; k--) {
        mine[r][c] = k;
        if (c == m - 1) {
            if (tryy(r + 1, 0)) return 1;
        }
        else {
            if (tryy(r, c + 1)) return 1;
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> m;
    FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];
    tryy(0, 0);
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
