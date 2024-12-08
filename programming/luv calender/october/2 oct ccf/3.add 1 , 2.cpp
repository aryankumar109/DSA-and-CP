#include <iostream>
#include <vector>
using namespace std;

string solve_game(int N) {
    if(N > 1) return "BOB" ;
    else return "ALICE"  ;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        cout << solve_game(N) << endl;
    }
    return 0;
}
