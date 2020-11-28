/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b) {
    return a > b;
}
string solution(string s) {
    string answer = "";
    vector <char> str;

    for (int i = 0; i < s.size(); i++)
        str.push_back(s[i]);

    sort(str.begin(), str.end(), compare);

    for (int i = 0; i < s.size(); i++)
        answer += str[i];
    return answer;
}
*/

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), greater<char>());
    return s;
}