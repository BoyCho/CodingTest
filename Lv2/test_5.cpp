#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    while (true) {
        if (priorities[0] == *max_element(priorities.begin(), priorities.end())) {
            priorities.erase(priorities.begin());
            answer++;
            if (!location)
                return answer;
        }
        else {
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
            if (!location)
                location = priorities.size();
        }
        location--;
    }
    return answer;
}

// max_element는 주소를 반환한다