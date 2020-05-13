#include <iostream>

using namespace std;

long long int factor2(long long int n) {

    if (n == 1)
        return 1;
    return n * factor2(n - 1);

}

int main()
{
    long long int n,factorial = 1;

    cout << "Enter n" << endl;

    cin >> n;

    if (n <= 0) {

        cout << "ERROR" << endl;
        return -1;

    }
     
    for (int i = 1; i <= n; ++i) {

        factorial *= i;

    }

    cout << "Answer : " << factorial << endl;; // T(l) = n     S(l) = 3

    cout << "Answer2 : " << factor2(n) << endl;// T(l) = n     S(l) = n + 1 
}
