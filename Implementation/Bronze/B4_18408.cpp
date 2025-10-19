#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    // 入出力を高速化
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // vector 宣言
    vector<int> v(3);

    // 入力を vectorに保存
    for (int i = 0; i < 3; i++) {
        int temp;
        cin >> temp;
        v[i] = temp;
    }

    // 数を数えるための変数を宣言
    int cnt1 = 0, cnt2 = 0;

    // 各ケースに応じてカウントを増加
    for (int i = 0; i < 3; i++) {
        if (v[i] == 1) cnt1++;
        else cnt2++;
    }

    // 結果を出力
    if (cnt1 > cnt2) cout << 1 << '\n';
    else cout << 2 << '\n';

    return 0;
}