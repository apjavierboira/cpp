#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;
    BIT(int n): n(n), bit(n + 1, 0) {}

    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    long long sum(int idx) const {
        long long r = 0;
        for (; idx > 0; idx -= idx & -idx) r += bit[idx];
        return r;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> v(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];

    BIT ft(n);

    // Construimos el array de diferencias en el BIT:
    // diff[i] = v[i] - v[i-1]
    for (int i = 1; i <= n; i++) {
        ft.add(i, v[i] - v[i - 1]);
    }

    while (q--) {
        int question;
        cin >> question;

        if (question == 1) {
            int l, r;
            long long x;
            cin >> l >> r >> x;
            ft.add(l, x);
            if (r + 1 <= n) ft.add(r + 1, -x);
        } else { // question == 2
            int k;
            cin >> k;
            cout << ft.sum(k) << "\n";
        }
    }

    return 0;
}