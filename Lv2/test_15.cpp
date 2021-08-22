#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers, int target) {
    vector<int> sel(numbers.size(), 1);
    int answer = 0, sum = 0;

    for (int i = 0; i < numbers.size(); i++) {
        sel[i] = -1;
        do {
            for (int j = 0; j < numbers.size(); j++)
                sum += numbers[j] * sel[j];
            if (sum == target) answer++;
            sum = 0;
        } while (next_permutation(sel.begin(), sel.end()));
    }
    return answer;
}


/* 비트로 푸는 풀이

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = 1 << numbers.size();

    for(int i = 1 ; i < size ; i++){
        int temp = 0;
        for(int j = 0 ; j < numbers.size() ; j++)
        {
            if(i &(1 << j)){
                temp -= numbers[j];
            }
            else temp += numbers[j];
        }
        if(temp == target) answer++;
    }
    return answer;
}
*/