#include <iostream>

using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    cin >> A >> B;

    cout << 1000 * A + 10000 * B << '\n';

    return 0;
}