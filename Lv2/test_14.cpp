#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> scov(scoville.begin(), scoville.end());
    int answer = 0, tmp;

    while (scov.top() < K) {
        if (scov.size() <= 1) return -1;

        tmp = scov.top();
        scov.pop();
        scov.push(tmp + scov.top() * 2);
        scov.pop();
        answer++;
    }
    return answer;
}