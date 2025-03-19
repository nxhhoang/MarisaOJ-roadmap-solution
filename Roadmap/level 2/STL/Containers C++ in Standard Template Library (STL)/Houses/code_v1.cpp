#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int m = n;
    set<int> house;
    multiset<int> dist;

    while(n--) {
        int x;
        cin >> x;
        set<int>::iterator it = house.find(x);
        if (it != house.end()) {
            if (it == house.begin()) {
                auto temp = next(it);
                if (temp != house.end()) {
                    auto dist_it = dist.find(*temp - *it);
                    if (dist_it != dist.end()) dist.erase(dist_it); 
                }
            } else {
                auto pre = prev(it);
                auto temp = next(it);
                if (temp != house.end()) {
                    auto dist_it1 = dist.find(*temp - *it);
                    auto dist_it2 = dist.find(*it - *pre);
                    if (dist_it1 != dist.end()) dist.erase(dist_it1); 
                    if (dist_it2 != dist.end()) dist.erase(dist_it2);
                    dist.insert(*temp - *pre);
                }
                else {
                    auto dist_it = dist.find(*it - *pre);
                    if (dist_it != dist.end()) dist.erase(dist_it); 
                }
            }
            house.erase(x);
        }
        else {
            house.insert(x);
            set<int>::iterator i = house.find(x);
            if (i == house.begin()) {
                auto temp = next(i);
                if (temp != house.end()) dist.insert(*temp - *i);
            } else {
                auto pre = prev(i);
                auto temp = next(i);
                if (temp != house.end()) {
                    auto dist_it = dist.find(*temp - *pre);
                    if (dist_it != dist.end()) dist.erase(dist_it); 
                    dist.insert(*temp - *i); 
                    dist.insert(*i - *pre);
                }
                else {
                    dist.insert(*i - *pre);
                }
            }
        }
        if (house.size() <= 1) cout << -1 << endl;
        else cout << *dist.begin() << endl; 
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
