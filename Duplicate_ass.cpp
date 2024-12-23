#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int f = 0;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) {
            f = 1;
            break;
        }
    }
    (f == 1) ? cout << "YES" : cout << "NO";
    return 0;
}