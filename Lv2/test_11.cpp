#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool prime_num(int n, vector<int> &overlap) {
    if (n <= 1) return false;
    for (int i = 0; i < overlap.size(); i++)
        if (n == overlap[i]) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    overlap.push_back(n);
    return true;
}

int solution(string numbers) {
    int answer = 0;
    string tmp = "\0";
    vector<int> select(7, 0);
    vector<int> overlap;

    for (int i = 0; i < numbers.size(); i++) {
        select[i] = 1;
        do {
            for (int j = 0; j < numbers.size(); j++)
                if (select[j]) tmp += numbers[j];
            sort(tmp.begin(), tmp.end());
            do {
                if (prime_num(stoi(tmp), overlap)) answer++;
            } while (next_permutation(tmp.begin(), tmp.end()));
            tmp.clear();
        } while (prev_permutation(select.begin(), select.begin() + numbers.size()));
    }
    return answer;
}

// next_permutation() 을 사용할 때는 오름차순 배열
// prev_permutation() 을 사용할 때는 내림차순 배열