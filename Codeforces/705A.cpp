#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s0 = "I hate ", s1 = "I love ", s2 = "that ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            cout << s0;
        else
            cout << s1;
        if (i != n - 1)
            cout << s2;
    }
    cout << "it";
    return 0;
}