#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i - 1] + a[i];
    }
 
    for (int i = n; i > 0; i--) {
        cout << a[i] << " ";
    }
    return 0;
}