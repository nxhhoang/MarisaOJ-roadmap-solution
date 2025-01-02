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

int n;
char a[10][10];
int r[N] = { 0 };
int c[N] = { 0 };
int cheo_tr[2 * (N - 1)] = { 0 };
int cheo_ph[2 * (N - 1)] = { 0 };
int dem = 0;
int goc = 0;

void tryy(int k) {
    if (k == n) dem++;

    FOR(j, 0, n) {
        if (r[goc] || c[j] || cheo_ph[goc + j] || cheo_tr[goc - j + n - 1]) continue;
        a[goc][j] = 'x';
        r[goc]++; c[j]++; cheo_ph[goc + j]++; cheo_tr[goc - j + n - 1]++;
        ++goc;
        tryy(k + 1);
        --goc;
        a[goc][j] = '.';
        r[goc] = c[j] = 0;
        cheo_ph[goc + j] = cheo_tr[goc - j + n - 1] = 0;
    }
}

void solve()
{
    cin >> n;
    FOR(i, 0, n) FOR(j, 0, n) a[i][j] = '.';
    tryy(0);
    cout << dem << endl;
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
