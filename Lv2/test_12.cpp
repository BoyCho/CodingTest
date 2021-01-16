#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool change(int a, int b) {
    return (to_string(b) + to_string(a)) < (to_string(a) + to_string(b));
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), change);

    if (!(numbers[0])) return "0";

    for (int i = 0; i < numbers.size(); i++)
        answer += to_string(numbers[i]);

    return answer;
}