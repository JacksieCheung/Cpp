#include <iostream>

using namespace std;

int N = 10;

int div(int N) {
    if (N == 0) {
        return 0;
    }
    if (N == 1) {
        return 1;
    }

    return div(N-1) + div(N-2);
}

int main() {
    cout << N << ": " << div(N) << endl;

    return 0;
}
