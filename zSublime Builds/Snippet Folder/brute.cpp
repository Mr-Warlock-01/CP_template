#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 x, y;
    std::cin >> x >> y;
    i64 min = 1e18, p, q;
    auto upd = [&](i64 _p, i64 _q) -> void {
        if ((_p & _q) == 0 && abs(_p - x) + abs(_q - y) < min) {
            min = abs(_p - x) + abs(_q - y);
            p = _p;
            q = _q;
        }  
    };
    upd(x, y);
    for (int i = 29; i >= 0; i--) {
        if ((x & y) >> i & 1) {
            upd((x >> i << i) + (1LL << i), y);
            upd(x, (y >> i << i) + (1LL << i));
            upd(x >> i << i, (y >> i << i) - 1);
            upd((x >> i << i) - 1, y >> i << i);
        }
    }
    //std::cout <<p<<" "<<q<< "\n";
    std::cout << abs(p-x)+ abs(q-y) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}