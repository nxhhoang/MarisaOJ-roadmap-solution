// nxhhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
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
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

const int mod = 998244353;
const int siz = pow(2,20) + 1;

void func(int a, float b, int c=0) {cout <<1;}
void func(float a, int b, int c=0) {cout << 2;}
void func(float a, float b){cout << 3;}

int n;
vector<vi> tre(MAXSIZE);
vector<int> visited(MAXSIZE, 0);
vector<int> den(MAXSIZE, 0);
vector<int> tra(MAXSIZE, 0);

void dfs(int dinh) {
    bool flag = 0;
    for (int i = 0; i < tre[dinh].size(); i++) {
        if (visited[tre[dinh][i]] == 0) {
            visited[tre[dinh][i]] = 1;
            flag = 1;
            dfs(tre[dinh][i]);
            den[dinh] += tra[tre[dinh][i]];
            tra[dinh] += max(den[tre[dinh][i]], tra[tre[dinh][i]]);
        }
    }
    den[dinh]++;
}

void solve()
{
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        tre[a].push_back(b);
        tre[b].push_back(a);
    }
    visited[1] = 1;
    dfs(1);
    cout << max(den[1], tra[1]) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
