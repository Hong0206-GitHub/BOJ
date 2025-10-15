#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

    // 入出力を高速化
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // vectorを宣言
    vector<int> v(3);

    // 入力値をvectorに格納
    for (int i = 0; i < 3; i++) cin >> v[i];
    
    // vectorを昇順にソート
    sort(v.begin(), v.end());

    // 2番目に大きい値を出力
    cout << v[1] << '\n';

    return 0;
}
