#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

    // 入出力を高速化
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 入力を格納する vector を宣言
    vector<int> v(3);
    for (int i = 0; i < 3; i++) {
        int temp;
        cin >> temp;
        v[i] = temp;
    }

    // 答えを入れる変数を宣言
    int sum = 0;

    // ３つの点数の中から大きい２つを求めて、合計を計算
    for (int i = 0; i < 2; i++) {
        sum += *max_element(v.begin(), v.end());
        v[max_element(v.begin(), v.end()) - v.begin()] = -1;
    }

    // 結果を出力
    cout << sum << '\n';

    return 0;
}
