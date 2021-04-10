#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;
int mini = 1e9, maxi = -1;
void rec(string N, int c) {
    int i;
    for (i = 0; i < N.length(); i++)
        c += (N[i] - '0') % 2;
    if (N.length() == 1) {
        mini = min(mini, c);
        maxi = max(maxi, c);
        return;
    }
    else if (N.length() == 2)
        rec(to_string(N[0] - '0' + N[1] - '0'), c);
    else {
        int j, k, A = 0, B, C;
        for (i = 0; i < N.length()-2; i++) {
            A = A * 10 + N[i] - '0';
            B = 0;
            for (j = i + 1; j < N.length()-1; j++) {
                B = B * 10 + N[j] - '0';
                C = 0;
                for (k = j + 1; k < N.length(); k++)
                    C = C * 10 + N[k] - '0';
                rec(to_string(A + B + C), c);
            }
        }
    }    
}
int main() {
    string N;
    cin >> N;
    rec(N, 0);
    printf("%d %d", mini, maxi);
    return 0;
}