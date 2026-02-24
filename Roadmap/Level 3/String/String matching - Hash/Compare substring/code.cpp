// nxhhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
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
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
    string s;
    cin >> s;
    int q;
    cin >> q;

    int n = s.size();
    int lg2 = log2(n);
    vector<vi> sx(lg2, vi(n, -1));
    vector<vi> pos(lg2, vi(n, 0));

    for (int i = 0; i < n - 1; i++) sx[0][i] = i;
    
    sort(sx[0].begin(), sx[0].begin() + n - 1, [&](int a, int b) {
        return s.substr(a, 2) < s.substr(b, 2);
    });
    
    int cnt = 0;

    for (int i = 0; i < n - 2; i++) {
        int cur = sx[0][i];
        int net = sx[0][i + 1];
        if (s.substr(cur, 2) == s.substr(net, 2)) pos[0][cur] = cnt, pos[0][net] = cnt; 
        else pos[0][cur] = cnt++, pos[0][net] = cnt;
    }

    int val = 2;
    for (int i = 1; i < lg2; i++) {
        val *= 2;
        if (val > n) break;
        for (int j = 0; j < n - val + 1; j++) sx[i][j] = j;
        
        sort(sx[i].begin(), sx[i].begin() + n - val + 1, [&](int a, int b) {
            return (pos[i - 1][a] < pos[i - 1][b]) 
                || (pos[i - 1][a] == pos[i - 1][b] && pos[i - 1][a + val / 2] < pos[i - 1][b + val / 2]);
        });

        int cnt = 0;
        for (int j = 0; j < n - val; j++) {
            int cur = sx[i][j];
            int net = sx[i][j + 1];
            if (pos[i - 1][cur] == pos[i - 1][net] 
                    && pos[i - 1][cur + val / 2] == pos[i - 1][net + val / 2]) 
                pos[i][cur] = cnt, pos[i][net] = cnt;
            else pos[i][cur] = cnt++, pos[i][net] = cnt;
        }
    }
    
    int tmp = pow(2, lg2);
    while(q--) {
        int a, b, l;
        cin >> a >> b >> l;
        a--, b--, l++;
        int cu = tmp;
        int vall = lg2;
 
        while (l < cu) cu /= 2, vall--;
        vall--;
        if (l < 2) {
            string m = s.substr(a, l);
            string n = s.substr(b, l);
            if (m < n) cout << "<" << endl;
            else if (m > n) cout << ">" << endl;
            else cout << "=" << endl;
        } else if (pos[vall][a] < pos[vall][b]) 
            cout << "<" << endl;
        else if (pos[vall][a] > pos[vall][b]) 
            cout << ">" << endl;
        else if (pos[vall][a + l - cu] < pos[vall][b + l - cu]) 
            cout << "<" << endl;
        else if (pos[vall][a + l - cu] > pos[vall][b + l - cu]) 
            cout << ">" << endl;
        else cout << "=" << endl;
    }
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
