#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long int n;
    string CONCEPTION;
    long long int count = 0;

flag:
    cout << "Enter n" << endl;
    cin >> n;

    if (n <= 0) {
        cout << "ERROR" << endl;
        system("cls");
        goto flag;
    }

    while (n > 0) {
        if (n % 3 == 0) {
            n /= 3;
            count++;
            CONCEPTION += "3*";
        }
        else
        {
            if (n % 2 == 0) {
                n /= 2;
                count++;
                CONCEPTION += "2*";
            }
            else
            {
                n -= 1;
                count++;
                CONCEPTION += "1+";
            }
        }

    }
    cout << count << endl;
    cout << "0 ";
    for (int i = CONCEPTION.length() - 1; i >= 0; --i) {
        cout << CONCEPTION[i] << " ";
    }

    return 0;
}
