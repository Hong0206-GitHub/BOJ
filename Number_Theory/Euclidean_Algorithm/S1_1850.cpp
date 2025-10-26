#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 유클리드 호제법 알고리즘 사용
int gcd(ll a, ll b) {
    while (a % b != 0) {
        ll temp = a % b;
        a = b;
        b = temp;
    }

    return b;
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 두 수 입력 받기
    ll a, b;
    cin >> a >> b;

    // 최대공약수 구하기
    ll g = gcd(a, b);

    // 최대공약수 만큼 1 출력
    for (ll i = 0; i < g; i++) cout << 1;
    cout << '\n';

    return 0;
}