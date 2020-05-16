#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <ctime>
using namespace std;


//initialiazation of global parameters
typedef long long  int T;  
typedef long long  int hashTableIndex;
long long int hashTableSize;
T* hashTable;
bool* used;
//Functions prototypes
hashTableIndex myhash(T data);
void insertData(T data);
void deleteData(T data);
int findData(T data);
//const and parameters
int c = 2;
int d = 3;
//time parameters
int startedFirstHundred;
int endedFirstHundred;

int main() {

    setlocale(LC_ALL, "rus");
    srand(time(0));
    
    long long int i, * a, maxnum;
    cout << "Введите количество элементов maxnum : ";
    cin >> maxnum;
    
    cout << "Введите размер хеш-таблицы hashTableSize (в 10 раз больше maxnum) : ";
    cin >> hashTableSize;
    
    a = new long long int[maxnum];

    hashTable = new T[hashTableSize];
    used = new bool[hashTableSize];
    
    //Zero array
    for (i = 0; i < hashTableSize; i++) {
        hashTable[i] = 0;
        used[i] = false;
    }
    //Random array
    for (i = 0; i < maxnum; i++) a[i] = rand() * rand();
    // заполнение хеш-таблицы элементами массива
    for (i = 0; i < maxnum; i++) {
        //Подсчет времени 1-ой и посоледней сотки элементов
        int start = clock();
        if (i == 100) {
            startedFirstHundred = clock();
            cout << "Первая сотка - время - " << ((float)startedFirstHundred - start) / CLOCKS_PER_SEC << endl;
        }
        if (maxnum - 100 == i) endedFirstHundred = clock();
        //Конец подсчета времени


        insertData(a[i]);
    }
    cout << "Последняя сотка - время - " << ((float)(clock() - endedFirstHundred)) / CLOCKS_PER_SEC << endl;



    // поиск элементов массива по хеш-таблице
     int max = -23;//Время поиска (максимальное)

     for (i = maxnum - 1; i >= 0; i--) {

         int startFind = clock();
         
         findData(a[i]);
         
         int timeOfFind = clock() - startFind;
         
         if (timeOfFind > max)   max = timeOfFind;
     }

     cout << "Поиск(max) - время - " << ((float)max) / CLOCKS_PER_SEC << endl;
     cout << "Общее время работы программы - " << ((float)clock()) / CLOCKS_PER_SEC << endl;

    // вывод элементов массива в файл inp.txt
    ofstream out("inp.txt");
    for (i = 0; i < maxnum; i++) {
        out << a[i];
        if (i < maxnum - 1) out << "\t";
    }
    out.close();


    // сохранение хеш-таблицы в файл outhash.txt
    out.open("outhash.txt");
    for (i = 0; i < hashTableSize; i++) {
        out << i << "  :  " << hashTable[i] << endl;
    }
    out.close();
    
    
    cout << "Введите элемент для поиска" << endl;
    long long int x;
    cin >> x;
    if (findData(x) != -5) {
        cout << "Элемент найден. Позиция в таблице: " << findData(x)  << endl;
    }
    else cout << "Элемент не найден" << endl;
    cout << endl;
    

    system("pause");
    return 0;
}

// хеш-функция размещения величины
hashTableIndex myhash(T data) {
    return (data % hashTableSize);
}
// функция поиска местоположения и вставки величины в таблицу
void insertData(T data) {
    hashTableIndex bucket;
    int j = 0;
metka:
    bucket = myhash(data) + c * j + d * j * j;
point:
    if (used[bucket] == 0) {
        hashTable[bucket] = data;
        used[bucket] = 1;
    }
    else {
        j++;
        if (myhash(data) + c * j + d * j * j > hashTableSize) {
            bucket = (myhash(data) + c * j + d * j * j) % hashTableSize;
            j = 0;
            goto point;
        }
        goto metka;
    }

}
// функция удаления величины из таблицы
void deleteData(T data) {
    hashTableIndex bucket;
    int j = 0;
metka:
    bucket = myhash(data) + c * j + d * j * j;
point:
    if (used[bucket] == 1) {
        hashTable[bucket] = 0;
        used[bucket] = 0;
    }
    else {
        j++;
        if (myhash(data) + c * j + d * j * j > hashTableSize) {
            bucket = (myhash(data) + c * j + d * j * j) % hashTableSize;
            j = 0;
            goto point;
        }
        goto metka;
    }

}
// функция поиска величины, равной data
int findData(T data) {
    hashTableIndex bucket;
    int k = 0;
metka:
    bucket = myhash(data) + c * k + d * k * k;
point:
    if (hashTable[bucket] == data) {
        return bucket;
    }
    else if (used[bucket] == false) {
        return -5;
    }
    else if (hashTable[bucket] != data) {
        k++;
        if (myhash(data) + c * k + d * k * k > hashTableSize) {
            bucket = (myhash(data) + c * k + d * k * k) % hashTableSize;
            k = 0;
            goto point;
        }
        goto metka;
    }
}
