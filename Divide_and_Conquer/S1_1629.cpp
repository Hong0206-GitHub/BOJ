#include <iostream>

using namespace std;
using ll = long long;

// 분할 정복 알고리즘 사용
ll power(ll a, ll b, ll c) {
    
    // 지수가 0이면 1 리턴
    if (b == 0) return 1;
    
    // 절반 먼저 구하기
    ll half = power(a, b / 2, c);
    
    // 곱해서 a^b 만들어 주고 모듈러 연산
    ll result = half * half % c;

    // 지수가 홀수인 경우 a한번 더 곱해주고 모듈러 연산
    if (b % 2 == 1) result = result * a % c;

    // 결과리턴
    return result;
}

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 받기
    ll A, B, C;
    cin >> A >> B >> C;

    // 함수 호출
    ll answer = power(A, B, C);
    
    // 답안 출력
    cout << answer << '\n';

    return 0;
}