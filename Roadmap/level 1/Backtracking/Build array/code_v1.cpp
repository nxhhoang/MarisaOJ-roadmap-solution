#include<iostream>
#include<iomanip>
#include<vector>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using ll = long long;
using namespace std;

const int N = 7;

int n, m, q;
int can[N];
int cost[N][3];
int matrix[N][N + 1] = { 0 };
vector<int> ans;
int coun = 0;


void tryy(int dem) {
    if (dem == n) {
        FOR(i, 0, q) {
            int sum = 0;
            FOR(j, 0, n) {
                sum += (ans[j] * matrix[i][j]);
            }
            if (sum != matrix[i][n]) return;
        }
        coun++;
        return;
    }
    FOR(i, 1, can[dem] + 1) {
        ans.push_back(i);
        tryy(dem + 1);
        ans.pop_back();
    }
}

void solve()
{
    cin >> n >> m >> q;
    FOR(i, 0, q) FOR(j, 0, 3) {
        cin >> cost[i][j]; // 1 2 3
    }
    FOR(i, 0, n) can[i] = m; 
    FOR(i, 0, q) {
        matrix[i][n] = cost[i][2];
        if (cost[i][2] == 1) {
            cout << 0 << endl;
            return;
        }
    }
    FOR(i, 0, q) FOR(j, 0, 2) {
        matrix[i][cost[i][j] - 1] = 1;
    }
    FOR(i, 0, q) FOR(j, 0, n) {
        if (matrix[i][j]) {
            if (can[j] > matrix[i][n] - 1) can[j] = matrix[i][n] - 1;
        }
    }
    tryy(0);
    cout << coun << endl;
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
