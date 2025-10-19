#include <iostream>

using namespace std;

int main(void) {

    // 入出力を高速化
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 入力
    int A, B;
    cin >> A >> B;

    // 条件を従って出力
    if (A == B) cout << 0 << '\n';
    else if (A < B) cout <<-1 << '\n';
    else cout << 1 << '\n';

    return 0;
}