#include <iostream>
#include <queue>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N입력 받기
    unsigned int N;
    cin >> N;

    // queue 선언
    queue<unsigned int> q;

    // queue에 1~N 집어넣기
    for (int i = 1; i <= N; ++i) q.push(i);

    // queue에 원소가 하나가 남을 때 까지 반복
    while(q.size() > 1) {
        // 가장 앞 카드 버리기
        q.pop();
        // 그 다음 카드 뒤에 삽입
        unsigned int temp = q.front();
        q.pop();
        q.push(temp);
    }

    // 결과 출력
    cout << q.front() << '\n';

    return 0;
}