/*폭탄을 가진 사람을 퀴즈를 풀게 되고, 
맞출 경우엔 다음 사람에게, 틀리거나 패스하는 경우에는 
다음 문제 또한 풀어야 합니다. 

210초~211초 사이에 폭탄이 터지고, 처음 폭탄을 가진 사람, 
퀴즈의 수, 각 퀴즈에서 의사결정을 하는데 걸린 시간이 주어질 때, 

폭탄이 터질 때 폭탄을 가지고 있던 사람의 번호를 출력해야 합니다.
*/

#include <iostream>
using namespace std;
#define MAXN (100)
int K;//처음 폭탄을 가진 사람 번호
int N;//퀴즈 개수
int T[MAXN+10];//걸린 시간
char Z[MAXN+10];//정답 여부

void InputData(){
    cin >> K;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T[i] >> Z[i];
    }
}

int solve(){

    int time = 0;
    int count = 0;

    count = K;
    for(int i = 0; i<N; i++){

        time += T[i];

        if (time > 210){
            break;
        }

        if (Z[i] == 'T'){
            count += 1;
        }

        if (count>8){
            count%=8;
        }

        cout << "Time : " << time << " Count : " << count << endl; 
    }

    return count;
}



int main(){
    int ans = -1;
    InputData();//입력받는 부분

    ans = solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}