#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    map<string, string> name;
    vector<pair<string, string>> result;
    vector<string> answer;

    for (int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string s;
        vector<string> tmp;

        while (getline(ss, s, ' ')) tmp.push_back(s);

        if (tmp[0] == "Enter") {
            if (!name.count(tmp[1])) // 첫 입장일 경우
                name.insert(make_pair(tmp[1], tmp[2]));
            else
                name.find(tmp[1])->second = tmp[2];
            result.push_back(make_pair(tmp[1], "님이 들어왔습니다."));
        }
        else if (tmp[0] == "Leave") {
            result.push_back(make_pair(tmp[1], "님이 나갔습니다."));
        }
        else
            name.find(tmp[1])->second = tmp[2];
    }

    for (int i = 0; i < result.size(); i++)
        answer.push_back(name.find(result[i].first)->second + result[i].second);
    return answer;
}