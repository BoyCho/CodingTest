#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(string s1, string s2) {
    return s1 < s2;
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end(), comp);
    sort(completion.begin(), completion.end(), comp);

    for (int i = 0; i < participant.size(); i++) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }
    return answer;
}