#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 가속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 원소 저장할 벡터 선언
    vector<int> v(3);
    
    // 입력 원소가 3개이므로, 벡터에 저장
    for (int i = 0; i < 3; i++) cin >> v[i];

    // 정렬
    sort(v.begin(), v.end());

    // 두 번째 값 출력해야하므로, 인덱스 1번 원소 출력
    cout << v[1] << '\n';

    return 0;
}