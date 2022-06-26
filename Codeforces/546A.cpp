#include <iostream>

using namespace std;

int main()
{
    int k, n, w;
    cin >> k >> n >> w;
    int borrow = (w * (w + 1) * k / 2) - n;
    borrow = borrow > 0 ? borrow : 0;
    cout<<borrow;
    return 0;
}