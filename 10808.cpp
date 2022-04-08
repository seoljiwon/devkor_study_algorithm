#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 단어 입력받음
    string s;
    cin >> s;
    
    // 알파벳 길이만큼의 벡터 선언
    vector<int> v(26);

    // 벡터를 0으로 초기화
    fill(v.begin(), v.end(), 0);

    int len = s.length();

    for (int i = 0; i < len; i++) {
        v[s[i]-'a']+=1;
    }

    for (int i = 0; i < 26; i++){
        cout << v[i] << ' ';
    }
}