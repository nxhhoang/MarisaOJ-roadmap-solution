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
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve() {
    int n, m, u, v, w;
    cin >> n >> m;
    vector<vector<pii>> tre(MAXSIZE + 1);
    for (int i = 0; i < m; i++){
        cin >> u >> v >> w;
        tre[u].push_back({v, w});
        tre[v].push_back({u, w});
    }
    vector<set<pii>> vsec(n + 1);
    vector<int> dis(n + 1, 0);
    set<int> loaibo;

    queue<int> q;
    q.push(n);
    vector<bool> vis(n + 1, 0);
    vis[n] = 1;
    int maxD = INT_MAX - 3;
    while(q.size()) {
        int top = q.front();
        loaibo.insert(top);
        q.pop();
        for (int i = 0; i < tre[top].size(); i++) {
            if (tre[top][i].first == 1) maxD = min(maxD, dis[top] + 1);
            if (dis[top] + 1 > maxD) break;
            if (tre[top][i].first == 1 && dis[top] + 1 == maxD) {
                vsec[1].insert({tre[top][i].second, top});
                continue;
            }
            // if (vsec[tre[top][i].first].size() == 0)
            if (vis[tre[top][i].first] == 0) {
                vis[tre[top][i].first] = 1;
                q.push(tre[top][i].first);
                dis[tre[top][i].first] = dis[top] + 1;
            }
            if (loaibo.find(tre[top][i].first) == loaibo.end()) 
            vsec[tre[top][i].first].insert({tre[top][i].second, top});
        }
    }
    cout << maxD << endl;
    // for (int i = 1; i < n + 1; i++) {
    //     cout << "---------------------- " << i << endl;
    //     for (auto it : vsec[i]) {
    //         cout << "( weight:" << it.first << ", dinh: " << it.second << " )" << endl; 
    //     }
    // }
    queue<set<pii>> qset;
    queue<set<pii>> temp;
    vector<bool> visited(n + 1, 0);
    qset.push(vsec[1]);
    visited[1] = 1;
    for (int i = 0; i < maxD; i++) {
        int minV = INT_MAX;
        int val = qset.size();
        for (int j = 0; j < val; j++) {
            minV = min(minV, qset.front().begin()->first);
            temp.push(qset.front());
            qset.pop();
        }
        val = temp.size();
        for (int j = 0; j < val; j++) {
            auto it = temp.front();
            temp.pop();
            for (auto tmp = it.begin(); tmp != it.end(); ++tmp) {
                if (tmp->first == minV && visited[tmp->second] == 0) qset.push(vsec[tmp->second]), visited[tmp->second] = 1;
            }
        }
        cout << minV << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; LLLLLLLLLLLLLLLLLLLLL
    while(t--){
        solve();
    }
    return 0;
}

// 1
//2 3
//4 5
// 6
//7 8
//9 10
// 11
