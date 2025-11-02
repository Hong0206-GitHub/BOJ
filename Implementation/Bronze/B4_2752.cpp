#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 세 수 정렬이므로, 벡터크기 3으로 지정
    vector<int> v(3);

    // 정렬할 수 입력 받아 벡터에 저장
    for (int i = 0; i < 3; i++) cin >> v[i];

    // 정렬
    sort(v.begin(), v.end());

    // 답안 출력
    for(int k : v) cout << k << ' ';
    cout << '\n';

    return 0;
}