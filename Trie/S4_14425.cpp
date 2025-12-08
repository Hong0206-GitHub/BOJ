#include <bits/stdc++.h>

using namespace std;

// 새로운 타입 선언
struct TrieNode {
    // 마지막 노드인지 여부를 판단하는 변수
    bool isEnd;

    // 소문자만 취급하므로 26개의 
    TrieNode *next[26];

    TrieNode() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
};

class Trie {
    // 클래스 변수
    private: TrieNode *root;
    
    public:
        // 생성자
        Trie() {
            root = new TrieNode();
        }

        // 문자열 삽입
        void insert(const string &s) {
            // 루트부터 시작해서
            TrieNode *cur = root;

            // 입력 받은 문자열의 문자들에 대해
            for (char c : s) {
                // 인덱스 얻어서
                int index = c - 'a';
                
                // 가지가 뻗어야하는 상황이면 가지 뻗어서 추가해줌
                if (cur -> next[index] == nullptr) cur -> next[index] = new TrieNode();
                
                // 그렇지 않으면 그냥 자식을 따라감
                cur = cur -> next[index];
            }
            // 마지막에 문자열 마지막이라는 표시를 남겨줌
            cur -> isEnd = true;
        }

        // 문자열 검색
        bool search(const string &s) {

            // 루트노드부터 시작해서
            TrieNode *cur = root;

            // 입력받은 문자열의 모든 문자에 대해
            for (char c : s) {
                // 인덱스 얻어주고
                int index = c - 'a';
                // 탐색 도중 끊기면 해당 문자열은 존재하지 않으므로 false 리턴
                if (cur -> next[index] == nullptr) return false;
                cur = cur -> next[index];
            }

            // 끝까지 도달해서 isEnd를 만난 경우 그 값 자체를 리턴
            return cur -> isEnd;
        }
};

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 집합에 넣을 문자열 개수 및 탐색할 문자열 개수 입력 받기
    int N, M;
    cin >> N >> M;

    // 트라이 생성
    Trie trie;
    
    // 문자열 트라이에 삽입하기
    while (N--) {
        string s;
        cin >> s;

        trie.insert(s);
    }

    // 답안 저장용 변수
    int answer = 0;

    // 탐색 진행하기
    while (M--) {
        string s;
        cin >> s;

        // 탐색 성공한 경우 1증가
        if (trie.search(s)) answer++;
    }

    // 답안 출력
    cout << answer << '\n';

    return 0;
}