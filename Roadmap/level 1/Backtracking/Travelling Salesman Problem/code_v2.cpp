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

int n;
int a[N][N];
bool fla[N] = { 0 };
int minS = 2000000;
int sum = 0;

void tryy(int k, int dinh) {
    if (k == n - 1) {
        int tong = sum + a[dinh][0];
        if (minS > tong) minS = tong;
        return;
    }

    FOR(j, 0, n) {
        if (fla[j] || !a[dinh][j]) continue;
        sum += a[dinh][j];
        fla[dinh] = 1;
        tryy(k + 1, j);
        sum -= a[dinh][j];
        fla[dinh] = 0;
    }
}

void solve()
{
    cin >> n;
    FOR(i, 0, n) FOR(j, 0, n) {
        cin >> a[i][j];
    }
    tryy(0, 0);
    cout << minS << endl;
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
