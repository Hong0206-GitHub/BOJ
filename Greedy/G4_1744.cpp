#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 수 개수 입력 받기
    int N;
    cin >> N;

    // 최대힙, 최소힙, 1만 관리하는 벡터 선언
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    vector<int> one;

    // 일단 입력 받아서
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        // 1이면 따로 관리해야 함(1은 단순히 더해주면 최댓값이 됨)
        if (temp == 1)
            one.push_back(temp);
        // 양수는 최대힙에 넣어서 곱해서 더해주어야 최댓값이 됨
        else if (temp > 0)
            max_heap.push(temp);
        // 음수는 최소힙에 넣어서 제일 작은 두 수를 곱해서 최대의 양수가 되게 만들어야 함
        else if (temp <= 0)
            min_heap.push(temp);
    }

    // 답안 저장 변수
    int answer = 0;
    
    // 최대힙이 원소가 1개 이하로 남을 때 까진
    // 원소 두 개 꺼내서 곱해서 답에 더해줌
    while (max_heap.size() > 1) {
        int a = max_heap.top();
        max_heap.pop();
        int b = max_heap.top();
        max_heap.pop();

        answer += a * b;
    }

    // 최소힙이 원소가 1개 이하로 남을 때 까지
    // 원소 두 개 꺼내서 곱해서 답에 더해줌
    while (min_heap.size() > 1) {
        int a = min_heap.top();
        min_heap.pop();
        int b = min_heap.top();
        min_heap.pop();

        answer += a * b;
    }

    // 1은 그냥 더해줌
    for (size_t i = 0; i < one.size(); i++) answer += one[i];   

    // 원소가 남아있다면 그냥 더해줌
    if (!max_heap.empty()) answer += max_heap.top();
    if (!min_heap.empty()) answer += min_heap.top();

    // 답안 출력
    cout << answer << '\n';

    return 0;
}