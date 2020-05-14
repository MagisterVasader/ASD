#include <iostream>

using namespace std;

class Heap {
    int* mas;
    int d;
    int size;
    void swap(int i, int j) {// меняет местами ключи вершин
        int buf = mas[i];
        mas[i] = mas[j];
        mas[j] = buf;
    }
    void shiftUp(int i) {//используется для восстановления инварианта при уменьшении ключа
        while (i > 0) {
            if (mas[i] < mas[(int)floor((i - 1) / d)]) {
                swap(i, (int)floor((i - 1) / d));
            }
            i--;
        }
    }
    void shiftDown(int i) {//используется для восстановления инварианта при увеличении ключа
        while (i * d + 1 < size - 1) {
            /////////////////////////////
            //Минимальный сын
            int min = mas[i * d + 1];
            int j = i * d + 1;
            for (int r = 2; r <= d; r++) {
                if (mas[i * d + r] < min) {//если элемент кучи меньше заданного минамального
                    min = mas[i * d + r];//то делаем его минимальным
                    j = i * d + r;//
                }
            }
            /////////////////////////////
            //ShiftDown
            if (mas[i] > mas[j] && j < size) {//если элемент заданного массива больше, чем элемент массива
                swap(i, j);//то меняем их местами
            }
            i = j;
            /////////////////////////////
        }
    }
    void setHeap(int* m) {//строим кучу
        for (int i = 0; i < size; i++) {
            mas[i] = m[i];
            shiftUp(i);
        }
    }
public:
    Heap(int* mas,int d,int s) {
        this->d = d;
        size = s;
        this->mas = new int[size];
        setHeap(mas);
    }
    ~Heap() {
    };
    void printA() {
        int m = Pow(d, size);
        int j = 1;
        if (d == 3) {
            for (int i = 0; i <= m; i++)
                cout << "          ";
            cout << "                        ";
            cout << mas[0] << endl;
        }
        else {
            for (int i = 0; i <= m; i++)
                cout << "       ";

            cout << "  " << mas[0] << endl;
        }
        for (int i = 1; i <= m; i++) {
            int count = 0;
            for (; count != pow(d, i); j++) {
                if (j < size) {
                    if (count == 0)
                        for (int z = 0; z <= m * (m - i); z++)
                            cout << "   ";
                    if (d == 3 && (mas[j] == mas[1] || mas[j] == mas[2] || mas[j] == mas[3])) {
                        cout << "    " << mas[j] << "              ";
                    }
                    else
                        cout << mas[j];

                }
                for (int z = 0; z <= m * (m - i); z++)
                    cout << "   ";
                count++;
            }
            cout << endl;
        }
    }
    int Pow(int d, int m) {
        int l = 0;
        for (int i = 0; i < m; i++) {
            if (pow(d, i) <= m)
                l++;
        }
        return l;
    }
    void insert(int x) {    //вставка произвольного элемента
        mas[size] = x;
        shiftUp(size);
        size++;
    }
    void delete_min() {
        swap(0, size - 1);
        size--;
        shiftDown(0);
    }

};

int main() {
        setlocale(LC_CTYPE, "RUSSIAN");
        cout << "Введите размер кучи:" << endl;
        int size;
        cin >> size;

        cout << "Введите кучу:" << endl;

        int *m = new int[size];
        for (int i = 0; i < size; i++) {
            cin >> m[i];
        }

        Heap heap (m,3,size);

        heap.printA();
        heap.delete_min();
        cout << endl;
        heap.printA();

        cout << endl;
        cout << "Введите элемент, который хотите вставить:" << endl;
        
        int k;
        cin >> k;

        heap.insert(k);

        cout << endl;
        heap.printA();
        return 0;
}
