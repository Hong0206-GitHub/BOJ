#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 오버플로우 방지용 문제에서 제시한 계산할 값
const ll MOD = 1e9 + 7;

// 문제 해결 함수
void solve() {

    // 원소 개수 선언
    int N;
    cin >> N;    

    // 최소힙 선언
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    
    // 원소 개수번 반복해서 최소힙에 넣기
    while (N--) {
        ll temp;
        cin >> temp;
        pq.push(temp);
    }

    // 초기값
    ll answer = 1;

    // 2개의 원소를 뽑아야하므로 사이즈가 1보다 큰 경우만 수행
    while (pq.size() > 1) {
        ll x = pq.top(); pq.pop(); // 원소 하나 뽑기
        ll y = pq.top(); pq.pop(); // 원소 하나 뽑기
        ll xy = (x * y) % MOD;    //  답안에 저장하기 위한 계산 완료된 변수
        answer = (answer * xy) % MOD; // 답안 갱신
        pq.push(x * y);  // 최소힙에 원값 그대로 삽입 -> 모듈러연산을 하면, 우선순위가 낮아질 수 있음
    }
    // 답안 출력
    cout << answer << '\n';
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 테스트 케이스 입력받기
    int T;
    cin >> T;

    // 테스트케이스만큼 문제해결용 함수 호출
    while (T--) solve();

    return 0;
}