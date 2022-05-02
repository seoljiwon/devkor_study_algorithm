#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string n;
    cin >> n;

    int len = n.length();

    vector <double> v (10);

    for (int i = 0; i < len ; i++){
        // 9는 6으로 만들 수 있으므로 6 자리에 개수 추가
        if ((n[i] - '0') == 9){
            v[6] += 1;
        } else {
            // 각자 숫자 자리에 개수 추가
            v[n[i] - '0'] += 1;
        }
    }

    // 6번째 자리는 개수의 절반을 반올림 한 만큼 필요함
    v[6] = ceil(v[6] / 2);


    // 개수 중 최댓값 찾음
    double max = *max_element(v.begin(), v.end());
     
    cout << max;
}