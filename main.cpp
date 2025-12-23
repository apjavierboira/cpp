#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long x;
    long long mejor = LLONG_MIN;
    long long actual = 0;

    for (int i = 0; i < N; i++) {
        cin >> x;
        actual = max(x, actual + x);
        mejor = max(mejor, actual);
    }

    cout << mejor << "\n";
    return 0;
}



