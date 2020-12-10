#include <string>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> time;
    int tmp = 0, size;

    for (int i = progresses.size() - 1; i >= 0; i--) 
        time.push(ceil((double)(100 - progresses[i]) / (double)(speeds[i])));
    
    for (int i = 0; i < progresses.size(); i++) {
        if (time.top() > tmp) {
            tmp = time.top();
            answer.push_back(1);
        }
        else answer.back()++;
        time.pop();
    }
    return answer;
}

// stack ±ª¿Ã ø÷ ΩË¡ˆ