// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MSIZE = 1e5 + 5;
const int MAXN = 2e5 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

const int cont = 1500 + 4;
int n, m;
vector<string> mat(cont);
vector<pii> pos;
queue<pii> q, st;
vector<vector<vector<int>>> val(cont, vector<vi>(cont, vi(3, 0)));

void print(int n, int m) {
    for (int i= 0; i < n; i++) {
        for (int j=0; j < m; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'L') pos.push_back({i, j});
        }
    }

    val[pos[0].first][pos[0].second] = {1, 0, 1};
    val[pos[1].first][pos[1].second] = {0, 1, 1};
    mat[pos[0].first][pos[0].second] = '.';
    mat[pos[1].first][pos[1].second] = '.';

    q.push(pos[0]);
    q.push(pos[1]);
    st.push(pos[0]);
    st.push(pos[1]);

    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (a < 0 || b < 0 || a >= n || b >= m 
                    || val[x][y] == val[a][b] || mat[a][b] == 'X') continue;

            val[a][b][0] = max(val[x][y][0], val[a][b][0]);
            val[a][b][1] = max(val[x][y][1], val[a][b][1]);
            val[a][b][2] = max(val[x][y][2], val[a][b][2]);
            st.push({a, b});
            q.push({a, b});
            if (val[a][b][0] + val[a][b][1] + val[a][b][2] == 3) {
                cout << 0;
                return;
            }
        }
    }

    vector<int> res = {0,0,0}, sr = {1,1,1},
             s101 = {1, 0, 1}, s011 = {0, 1, 1}, s001 = {0, 0, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.' && res == val[i][j]) {
                st.push({i, j});
                val[i][j] = s001;
            }
        }
    }
    
    int cnt = 1;
    while (st.size()) {
        int len = st.size();
        queue<pii> st101, st011;
        for (int i = 0; i < len; i++, st.pop()) {
            auto [x, y] = st.front();

            for (int k = 0; k < 4; k++) {
                int a = x + dx[k];
                int b = y + dy[k];
                if (a < 0 || b < 0 || a >= n || b >= m || val[a][b] == val[x][y]) continue;
                mat[a][b] = '.';
                // cout << a << " " << b << endl;
                if (val[a][b] == res) {
                    val[a][b] = val[x][y];
                    if (val[a][b] == s101) st101.push({a, b});
                    else if (val[a][b] == s011) st011.push({a, b});
                    st.push({a, b});
                    continue;
                } else if (val[a][b] == s001) {
                    // cout << val[x][y][0] << " ";
                    // cout << val[x][y][1] << " ";
                    // cout << val[x][y][2] << " ";
                    // cout << endl;
                    if (val[x][y] == s101) {
                        val[a][b] = val[x][y];
                        st101.push({a, b}); // duyejt sau
                    } else if (val[x][y] == s011) {
                        val[a][b] = val[x][y];
                        st011.push({a, b}); // duyejt sau
                    }
                    st.push({a, b});
                    continue;
                }
                
                val[a][b][0] = max(val[x][y][0], val[a][b][0]);
                val[a][b][1] = max(val[x][y][1], val[a][b][1]);
                val[a][b][2] = max(val[x][y][2], val[a][b][2]);
                if (val[a][b] == sr) {
                    cout << cnt;
                    return;
                } else if (val[a][b] == s101) {
                    st101.push({a, b});
                    for (int h = 0; h < 4; h++) {
                        int aa = a + dx[h];
                        int bb = b + dy[h];
                        if (aa < 0 || bb < 0 || aa >= n || bb >= m || val[aa][bb] == val[a][b]) continue;
                        if (val[aa][bb] == s011) {
                            cout << cnt;
                            return;
                        }
                    }
                }
                else if (val[a][b] == s011) {
                    st011.push({a, b});
                    for (int h = 0; h < 4; h++) {
                        int aa = a + dx[h];
                        int bb = b + dy[h];
                        if (aa < 0 || bb < 0 || aa >= n || bb >= m || val[aa][bb] == val[a][b]) continue;
                        if (val[aa][bb] == s101) {
                            cout << cnt;
                            return;
                        }
                    }
                }
            }
        }
        // cout << "           " << endl;
        // print(n, m);

        while (st101.size()) {
            auto [x, y] = st101.front();
            st101.pop();

            for (int i = 0; i < 4; i++) {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a < 0 || b < 0 || a >= n || b >= m 
                    || mat[a][b] == 'X' || val[a][b] == val[x][y]) continue;
                
                val[a][b][0] = max(val[x][y][0], val[a][b][0]);
                val[a][b][1] = max(val[x][y][1], val[a][b][1]);
                val[a][b][2] = max(val[x][y][2], val[a][b][2]);
                if (val[a][b] == sr) {
                    cout << cnt;
                    return;
                }
                st101.push({a, b});
            }
        }

        while (st011.size()) {
            auto [x, y] = st011.front();
            st011.pop();

            for (int i = 0; i < 4; i++) {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a < 0 || b < 0 || a >= n || b >= m 
                    || mat[a][b] == 'X' || val[a][b] == val[x][y]) continue;
                
                val[a][b][0] = max(val[x][y][0], val[a][b][0]);
                val[a][b][1] = max(val[x][y][1], val[a][b][1]);
                val[a][b][2] = max(val[x][y][2], val[a][b][2]);
                if (val[a][b] == sr) {
                    cout << cnt;
                    return;
                }
                st011.push({a, b});
            }
        }
        cnt++;
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
    while (t--)
    {
        solve();
    }
    return 0;
}
