#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set < string, greater<string> > s;

    while (n--){
        string name, enterOrLeave;
        cin >> name >> enterOrLeave;

        if (enterOrLeave == "enter"){
            s.insert(name);
        } else if (enterOrLeave == "leave"){
            s.erase(name);
        }
    }

    for (auto it = s.begin() ; it != s.end(); it++){
        cout << *it << '\n';
    }
}