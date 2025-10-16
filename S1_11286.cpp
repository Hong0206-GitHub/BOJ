#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare {
    // o1과 o2를 비교해서 o1이 우선순위가 낮은지를 선언 하는 함수
    bool operator() (int o1, int o2) {
        int first_abs = abs(o1); // 절댓값
        int second_abs = abs(o2); // 절댓값

        // 두 값이 같은 경우
        // o1이 더 큰 경우에 우선순위가 낮아짐
        if (first_abs == second_abs) return o1 > o2;
        
        // 두 값이 다른 경우
        // 첫번째의 절댓값이 더 커야 우선순위가 낮아짐
        else return first_abs > second_abs;
    }
};


int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 개수
    int N;
    cin >> N;
    
    // 우선순위 큐 선언
    priority_queue<int, vector<int>, compare> q; 

    // 입력 받을 때마다
    for (int i = 0; i < N; i++) {

        // 입력 받은 값 저장
        int temp;
        cin >> temp;

        // 입력 값이 0이 아니면
        if (temp != 0) {
            // 우선순위 큐에 삽입
            q.push(temp);           
        }
        
        // 입력값이 0이면
        else {
            // 큐가 비어있으면 0 출력
            if (q.empty()) cout << "0\n";
            // 비어있지 않으면 큐의 최상단 출력
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }

    return 0;
}