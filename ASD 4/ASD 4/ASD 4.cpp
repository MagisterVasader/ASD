#include <iostream>

using namespace std;

void out(int* mas, int n) {
    for (int i = 0; i < n; ++i)
        cout << mas[i] << ' ';
    cout << endl;
}

void out2(int** mas, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; ++j)
            cout << mas[i][j] << ' ';
        cout << endl;
    }
}
void sortingByChoice(int* mas, int n) {
    int k;
    for (int i = 0; i < n-1; i++) {
        k = i;
        for (int j = i; j < n; ++j) {
            if (mas[j] < mas[k]) {
                k = j;
            }
        }
        swap(mas[k], mas[i]);
    }
}
void sortingByInsert(int* mas, int n) {
    for (int i = 1; i < n; i++)
    {
        int x = mas[i]; 
        int j = i; 
        while ((j > 0) && (mas[j - 1] > x))
        {   
            mas[j] = mas[j - 1];
            j--;
        }
        mas[j] = x;
    }
}
void sortingBySwap(int* mas, int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 1; j < n; ++j) {
            if (mas[j] < mas[j - 1]) {
                swap(mas[j], mas[j - 1]);
            }
        }
    }
}
void quicksort(int* mas, int size) {
    int i = 0;
    int j = size - 1;
    int mid = mas[size / 2];

    do {
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        quicksort(mas, j + 1);
    }
    if (i < size) {
        quicksort(&mas[i], size - i);
    }
}
int POW(int l) {
    int ans = 1;
    for (int i = 0; i < l; ++i) {
        ans *= 10;
    }
    return ans;
}
void Radixsort(int* mas, int n) {
    int max = abs(mas[0]);

    for (int i = 1; i < n; ++i) { // Ищем количество разрядов
        if (mas[i] > max)
            max = mas[i];
    }
    int k = 0;
    while (max != 0) {
        max = max / 10;
        ++k;
    }

    int **dopmas = new int *[10]; //Создаем двумерный массив для хранения разрядов
    for (int i = 0; i < n+1; ++i)
        dopmas[i] = new int[10];


    int kol = 1; //Количество итераций
    int num;
    int buf;
    while (kol <= k) {
        num = 0;
        while (num < n) { // Заполнение дополнитеьного массива
            if (mas[num] < POW(kol-1)) {
                buf = 0;
            }
            else {
                buf = (mas[num] % POW(kol)) / POW(kol - 1);
            }
                dopmas[dopmas[n][buf]][buf] = mas[num];
                dopmas[n][buf]++;
                num++;
        }
        //out2(dopmas, n);
        num = 0;
        int j = 0;

        while  (num < n) { // Перезапись массива
            int i = 0;
            if (dopmas[n][j] == 0) {
                ++j;
            }
            else {
                while (dopmas[n][j] > 0) {
                    mas[num] = dopmas[i][j];
                    ++i;
                    --dopmas[n][j];
                    ++num;
                }
            }
        }
        ++kol;
    }
    
}
// Задание со звездочкой (Сортировка слиянием списков)
void Merge(int* mas, int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = 0;

    int* res = new int [h-l+1];

    while (i <= mid && j <= h) {
        if (mas[i] < mas[j]) {
            res[k] = mas[i];
            ++k;
            ++i;
        }
        else {
            res[k] = mas[j];
            ++k;
            ++j;
        }
    }
    for (; i <= mid; i++) {
        res[k] = mas[i];
        k++;
    }
    for (; j <= h; j++) {
        res[k] = mas[j];
        ++k;
    }

    int cou = l;
    for (int k = 0; k <= h-l ; ++k) {
        mas[cou] = res[k];
        ++cou;
    }

    delete[] res;
}
void MergeSort(int* mas, int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        MergeSort(mas, l, mid);
        MergeSort(mas, mid + 1, h);
        Merge(mas,l, mid, h);
    }
}


int main()
{
    int n;
    cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    /*
    sortingByChoice(array, n);
    out(array, n);
    cout << endl;
    //*/

    /*
    sortingByInsert(array, n);
    out(array, n);
    cout << endl;
    //*/

    /*
    sortingBySwap(array, n);
    out(array, n);
    cout << endl;
    //*/

    /*
    quicksort(array,n);
    out(array, n);
    cout << endl;
    //*/

    /*
    Radixsort(array, n);
    out (array,n);
    cout << endl;
    //*/

    ///*
    MergeSort(array, 0, n - 1);
    out(array, n);

    //*/
    return 0;
}