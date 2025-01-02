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

int n;
int a[N][N];
bool flag[N][N];
bool fla[N] = { 0 };
int minS = 2000000;
int sum = 0;
string path = "0";

void tryy(int k, int dinh) {
    if (k == n - 1) {
        int tong = sum + a[dinh][0];
        //cout << tong <<"  "<< path<< endl;
        if (minS > tong) minS = tong;
        return;
    }

    FOR(j, 0, n) {
        if (fla[j] || flag[dinh][j] || !a[dinh][j]) continue;
        sum += a[dinh][j];
        path.push_back('0' + j);
        FOR(i, 0, n) flag[i][j] = flag[dinh][i] = 1;
        fla[dinh] = 1;
        tryy(k + 1, j);
        sum -= a[dinh][j];
        path.pop_back();
        fla[dinh] = 0;
        FOR(i, 0, n) flag[i][j] = flag[dinh][i] = 0;
    }
}

void solve()
{
    cin >> n;
    FOR(i, 0, n) FOR(j, 0, n) {
        cin >> a[i][j];
        flag[i][j] = 0;
    }
    fla[0] = 1;
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
