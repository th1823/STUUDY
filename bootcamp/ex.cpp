/* https://jungol.co.kr/problem/2663
폭탄을 가진 사람을 퀴즈를 풀게 되고, 맞출 경우엔 다음 사람에게, 
틀리거나 패스하는 경우에는 다음 문제 또한 풀어야 합니다. 
210초~211초 사이에 폭탄이 터지고, 처음 폭탄을 가진 사람, 
퀴즈의 수, 각 퀴즈에서 의사결정을 하는데 걸린 시간이 주어질 때, 
폭탄이 터질 때 폭탄을 가지고 있던 사람의 번호를 출력해야 합니다.


첫 번째 줄에는 처음 폭탄을 가진 사람의 번호 K가 주어진다. (1 ≤ K ≤ 8) 
두 번째 줄에는 게임이 진행되는 동안 공개된 퀴즈의 수 N이 주어진다. (1 ≤ N ≤ 100) 
세 번째 줄부터 N개의 줄에는 퀴즈를 풀거나 통과를 결정할 때까지 걸린 시간 T (1 ≤ T ≤ 100)와 정답 여부 Z가 주어진다. 
Z가 'T'이면 퀴즈를 맞았다는 것을 의미하고, 'F'이면 틀렸다는 것을, 'P'이면 통과했다는 것을 의미한다.
*/

/*
#include <iostream>
using namespace std;

#define MAXN 100
int N; //퀴즈의 수
int K; //폭탄받은사람번호
int T[MAXN+10];
char C[MAXN+10];

void InputData(){
    cin >> K; 
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T[i] >> C[i];
    }
}

int Solve(){
    int sol = K;
    int time = 0;
    for(int i=0; i<N; i++){

        time+=T[i];

        if(time>210){
            break;
        }

        if(C[i]=='T'){
            sol+=1;
        }

        if (sol>8){
            sol%=8;
        }
    }

    return sol;
}

int main(){
    int ans=-1;
    InputData();

    ans = Solve();

    cout << ans << endl;//출력하는 부분

    return ans;
}
*/

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

#define MAXN 100
int N; //숫자 개수
int T[MAXN+10];
deque<pair<int,int>> dq;

void InputData(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T[i] ;
    }
}

int Makenum(int num){
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

int Solve(){
    for(int i=0; i<N; i++){
        int result = Makenum(T[i]);
        dq.push_back({result, T[i]});
    }
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

int main(){
    int ans=-1;
    InputData();

    Solve();

    sort(dq.begin(), dq.end(), comp);

    cout << dq[0].second << endl;//출력하는 부분
    return 0;
}
