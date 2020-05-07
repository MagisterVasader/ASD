#include <iostream>

using namespace std;


void findmax(int* mas, int n) {
    int ans = mas[0], //Ответ
        l = 0, //Левая граница
        r = 0, //Правая граница
        sum = 0, // Сумма подмассива
        min_sum = 0, // Минимальная сумма
        L_min = -1; //Левая граница минимальной суммы

    for (int i = 0; i < n; ++i) {
        sum += mas[i]; // Создание суммы подмассива

        int current = sum - min_sum;// Текущая сумма

        if (current > ans) { // Если текучаща сумма больше ответа, то ответом становится текущая сумма с левой границей минимальной суммы и текущим элементом
            ans = current;
            l = L_min + 1;
            r = i;
        }

        if (sum < min_sum) { // Если сумма подмассива меньше минимальной суммы, то минимальная сумма становится суммой подмассива и левая граница исходного массива становится текущим элементом
            min_sum = sum;
            L_min = i;
        }
    }

    cout << "Answer " << ans <<" First day: "<< l <<" Second day: " << r+1; // Выводим левую границу и правую увеличенную на 1, так как исходный массыв состоит из n+1 элементов
}

int main()
{
    cout << "How much days do you need to enter?" << endl;

    int n;
    cin >> n;
    int* array = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    int* array2 = new int[n - 1];
    for (int i = 0; i < n - 1; ++i) {
        array2[i] = array[i+1] - array[i];
    }
    findmax(array2,n-1);
    return 0;
}
//    100 113 110 85 105 102 86 63 81 101 94 106 101 79 94 90 97