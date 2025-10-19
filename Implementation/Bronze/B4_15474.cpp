#include <iostream>
using namespace std;

int main(void) {

    // 入出力の高速化
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 入力の受け取り
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    // 必要なセット数の計算
    int a, c;
    a = N / A;
    if (N % A != 0) a++;
    c = N / C;
    if (N % C != 0) c++;

    // 結果の出力
    if (a * B <= c * D) cout << a * B << '\n';
    else cout << c * D << '\n';

    return 0;
}