#include <iostream>
#include <string>
using namespace std;

int main(void) {

    // 入出力を高速化
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 入力を読み込む
    string N;
    cin >> N;
    
    // 10 <= N <= 99　なので
    // 十の位と一の位を比較して出力する
    if (N[0] == N[1]) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}