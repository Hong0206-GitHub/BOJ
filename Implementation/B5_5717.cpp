#include <iostream>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int m = 0, f = 0;
        cin >> m >> f;
        if (m == 0 && f == 0) break;

        cout << m + f << '\n';
    }

    return 0;
}