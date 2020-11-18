#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    int min = answer[0];
    int min_n = 0;
    if (answer.size() == 1) return { -1 };

    for (int i = 1; i < answer.size(); i++) {
        if (answer[i] < min) {
            min = answer[i];
            min_n = i;
        }
    }
    answer.erase(answer.begin() + min_n);
    return answer;
}

// *min_element(arr.begin(), arr.end()) »ç¿ë