/*
정올 숫자근
문제 각 자리수를 계속 더하여 한 자리 숫자를 만드는 것을 숫자근(Digit Root)이라고 한다. 
예를 들어 정수 65,536 의 숫자근은 7이다, 그것은 6+5+5+3+6=25 이고 이를 다시 2+5=7 이기 때문이다.
n 개의 정수가 입력되면 숫자근이 가장 큰 값을 찾는 프로그램을 작성하시오.
*/

#include <iostream>
#include <string> 
#include <deque>
#include <algorithm>

using namespace std;
#define MAXN ((int)1e3)

int N;//정수개수
int A[MAXN + 10];//입력 정수
deque<pair<int,int>> queue;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
}

int makeNum(int num){
    while(1){

        string start_str = to_string(num);
        int sum=0;

        for(const auto data : start_str){
            sum += data - '0';
        }

        num = sum;

        if (to_string(num).size() == 1){
            break;
        }

    }
    return num;
}


bool comp(pair<int, int> left, pair<int, int> right)
{
    if (left.first > right.first)
    {
        return true;
    }    
    else
    {
        if (left.first == right.first && left.second < right.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
        
}

void solve(){
    for(int i=0; i<N; i++){
        int result = makeNum(A[i]);
        queue.push_back({result, A[i]});
    }
}


int main(){
    int ans = -1;
    InputData();//입력 받는 부분

    solve();

    sort(queue.begin(), queue.end(), comp);

    cout << queue[0].second << endl;//출력하는 부분
    return 0;
}