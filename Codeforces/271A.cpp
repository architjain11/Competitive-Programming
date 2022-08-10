#include<bits/stdc++.h>

using namespace std;

void nextDistinct(int n) {
     for (int i = n + 1;; i++) {
        string s = to_string(i);
        set<int> uniDigits(s.begin(), s.end());
        if (s.size() == uniDigits.size()) {
            cout << i;
            break;
        }
    }
}

int main() {
    int n;
    cin>>n;
    nextDistinct(n);
    return 0;
}