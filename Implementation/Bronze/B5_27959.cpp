#include <bits/stdc++.h>

using namespace std;

int main(void)   {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 동전 개수 및 가격 입력 받기
    int N, M;
    cin >> N >> M;

    // 동전의 개수 만큼의 금액으로 수정
    N *= 100;

    // 조건 판단
    if (N >= M) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}