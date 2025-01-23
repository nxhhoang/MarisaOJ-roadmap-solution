#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define ub upper_bound
#define lb lower_bound

#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;

void solve() {
    string a,b;
    cin >> a >> b;
    int na = a.size();
    int nb = b.size();
    ll sum = 0;

    vector<vector<int>> pos(26, vector<int>(0));
    for (int i = 0; i < na; i++) pos[a[i] - 'a'].push_back(i);
	

    for (int i = 0; i < nb; i++) 
        sum += (ub(all(pos[b[i] - 'a']), i + na - nb) - lb(all(pos[b[i] - 'a']), i));
    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
