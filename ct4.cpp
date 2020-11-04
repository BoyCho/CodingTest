#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> m1 = { 1,2,3,4,5 };
    vector<int> m2 = { 2,1,2,3,2,4,2,5 };
    vector<int> m3 = { 3,3,1,1,2,2,4,4,5,5 };

    vector<int> math(3);
    int max;

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == m1[i % 5])
            math[0]++;
        if (answers[i] == m2[i % 8])
            math[1]++;
        if (answers[i] == m3[i % 10])
            math[2]++;
    }

    max = *max_element(math.begin(), math.end());

    for (int i = 0; i < 3; i++) {
        if (math[i] == max)
            answer.push_back(i+1);
    }
    return answer;
}