#include <bits/stdc++.h>

using namespace std;

// 최소힙과 최대힙을 사용하여 정렬 상태를 유지하면서 각 top값이 중간값임을 이용함
// 최소힙의 top은 오른쪽 절반의 최소값으로, 최대힙의 top은 왼쪽 절반의 최대값으로 사용할 것임
// 따라서 각 top을 비교하여 스왑해주면 정렬상태가 깨지지 않음

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력 받기
    int N;
    cin >> N;

    // 입력 값 저장할 임시 변수
    int temp;

    // 기본 우선순위큐는 최대힙
    priority_queue<int> max_heap;

    // 구조체에 greater<>를 넣어 최소힙 선언
    priority_queue<int, vector<int>, greater<int>> min_heap;

    while (N--) {
        cin >> temp;

        // 최대힙의 탑이 항상 중앙값으로 고정할 것임
        // 따라서 최대힙이 최소힙 크기보다 크거나 같은 상황이어야함
        (max_heap.size() <= min_heap.size()) ? max_heap.push(temp) : min_heap.push(temp);

        // 두 힙의 순서가 어긋난 경우(왼쪽의 최대값 > 오른쪽의 최소값),
        // 두 힙의 top을 교환하여 정렬 관계 유지
        if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        // 답안 출력
        cout << max_heap.top() << '\n';

    }

    return 0;
}