#include <iostream>

using namespace std;

int main()
{
    int w;
    cin >> w;
    w % 2 == 0 && w > 2 ? cout << "YES\n" : cout << "NO\n";
    return 0;
}