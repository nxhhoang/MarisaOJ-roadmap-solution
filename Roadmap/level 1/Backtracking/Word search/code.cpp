#include<iostream>
#include<iomanip>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using ll = long long;
using namespace std;

const int N = 6;

int n, m;
string S;
string chuoi[N];
bool vi[N][N] = { 0 };
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
bool flag = 0;

bool tryy(int r, int c, int dem) {
    dem++;
    if (dem == S.size()) return 1;

    FOR(i, 0, 4) {
        int a = r + dx[i];
        int b = c + dy[i];
        if (vi[a][b] || a < 0 || a >= n || b < 0 || b >= m) continue;
        if (chuoi[a][b] == S[dem]) {
            vi[a][b] = 1;
            if (tryy(a, b, dem)) return 1;
            vi[a][b] = 0;
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> m;
    FOR(i, 0, n) cin >> chuoi[i];
    cin >> S;
    FOR(i, 0, n) FOR(j, 0, m) {
        if (chuoi[i][j] == S[0]) {
            if (tryy(i, j, 0)) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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
