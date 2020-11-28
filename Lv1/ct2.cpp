#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int tmp;

    answer.reserve(199);
    
    for (int i = 0; i < numbers.size()-1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            for (int k = 0; k <= answer.size(); k++) {
                if (answer.empty() || k == answer.size())
                    answer.push_back(numbers[i] + numbers[j]);
                if (numbers[i] + numbers[j] == answer[k])
                    break;
            }
        }
    }
    
    sort(answer.begin(), answer.end());

    return answer;
}
