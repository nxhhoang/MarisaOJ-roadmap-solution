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

const int N = 10;

int a[10][10];
ll maxS = 0;
ll sum = 0;
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };

void tryy(int i, int j) {
    if (i == 3 && j == 3) {
        sum += a[i][j];
        if (maxS < sum) maxS = sum;
        sum -= a[i][j];
        return;
    }
    
    FOR(k, 0, 2) {
        sum += a[i][j];
        if (dx[k] + i < 4 && dy[k] + j < 4) tryy(i + dx[k], j + dy[k]);
        sum -= a[i][j];
    }
}

void solve()
{
    FOR(i, 0, 4) FOR(j, 0, 4) cin >> a[i][j];
    tryy(0, 0);
    cout << maxS << endl;
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
