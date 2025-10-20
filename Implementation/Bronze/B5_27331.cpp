#include <iostream>

using namespace std;

int main(void) {

    // 入出力を高速化
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 入力
    int A, B;
    cin >> A >> B;

    // 出力
    cout << 10 * A + B << '\n';

    return 0;
}