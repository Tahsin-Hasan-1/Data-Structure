#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, X;
    cin >> N;
    vector<int> A(N);
    for (int &x : A) {
        cin >> x;
    }
    int M;
    cin >> N;
    vector<int> B(M);
    for (int &x : B) {
        cin >> x;
    }
    cin >> X;
    A.insert(A.begin() + X, B.begin(), B.end());
    for (int x : A) {
        cout << x;
    }

    return 0;
}