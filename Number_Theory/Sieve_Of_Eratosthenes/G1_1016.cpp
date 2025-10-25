#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력값 저장
    ll min, max;
    cin >> min >> max;

    // max - min + 1 사이즈 벡터 선언
    vector<bool> v(max - min + 1);

    // 에라토스테네스의 체 알고리즘 변형
    for (ll i = 2; i * i <= max; i++) {
        ll pow = i * i; // 제곱수 저장
        ll start_index = min / pow; // 시작 인덱스는 제곱 전 수로
        if (min % pow != 0) start_index++;  // 제곱 ㄴㄴ 수면 넘김

        // start_index 부터 제곱수를 증가시켜가며 확인
        for (ll j = start_index; pow * j <= max; j++) v[(int)((j *pow) - min)] = true;
    }

    // 답안 저장용 변수
    int count = 0;
    // 개수 세기
    for (int i = 0; i <= max - min; i++)
        if (!v[i]) count++;

    // 답안 출력
    cout << count << '\n';

    return 0;
}