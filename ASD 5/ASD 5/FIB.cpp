#include "FIB.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
vector <int> enter(vector <int> mas) {
    ifstream inf("input.txt");
    if (!inf) {
        cerr << "File couldn't be opened for reading" << endl;
        exit(1);
    }
    while (inf) {
        int buf;
        inf >> buf;
        mas.push_back(buf);
    }
    mas.pop_back();
    return mas;
};
void out(vector <int> mas) {
    ofstream outf("output.txt");
    if (!outf) {
        cerr << "File couldn't be opened for reading" << endl;
        exit(1);
    }
    for (int i = 0; i < mas.size(); ++i) {
        outf << mas[i] << ' '; 
    }
}; 
// Вывод 
int findserii(vector <int> p, int i) {
    for (; i < p.size() - 1; ++i) {
        if (p[i] < p[i + 1]) {
            continue;
        }
        else {
            return i;
        }
    }
    return p.size() - 1;
};
//Поиск серий в файле
void Fibonachchi(vector <int> file1, vector <int> file2, int i, int j, vector <int>& output) {
    
    output.clear();
    int sizevecFirst = file1.size();
    int sizevecSecond = file2.size();

    while (i < sizevecFirst && j < sizevecSecond) {

        int sizeseriifirst = findserii(file1, i);
        int sizeseriisecond = findserii(file2, j);

        while (i <= sizeseriifirst && j <= sizeseriisecond) {
            if (file1[i] <= file2[j]) {
                output.push_back(file1[i]);
                ++i;
            }
            else {
                output.push_back(file2[j]);
                ++j;
            }
        }
        for (; i <= sizeseriifirst; i++) {
            output.push_back(file1[i]);
        }
        for (; j <= sizeseriisecond; j++) {
            output.push_back(file2[j]);
        }
    }
    if (i == sizevecFirst && j == sizevecSecond) {
        serii(output);
    }
    else {
        if (i == sizevecFirst) {
            vector <int> fileNEW1;
            for (; j < sizevecSecond; ++j) {
                fileNEW1.push_back(file2[j]);
            }
            Fibonachchi(output, fileNEW1, 0, 0, output);
        }
        else {
            if (j == sizevecSecond) {
                vector <int> fileNEW2;
                for (; i < sizevecFirst; ++i) {
                    fileNEW2.push_back(file1[i]);
                }
                Fibonachchi(output, fileNEW2, 0, 0, output);
            }
        }
    }
    
};
// Алгоритм
void serii(vector <int> inputfile) {
    vector <int> file1;
    vector <int> file2;
    int counter = 0;

    while (counter < size(inputfile)) {
        while (counter < size(inputfile) - 1 && inputfile[counter] <= inputfile[counter + 1]) {
            file1.push_back(inputfile[counter]);
            counter++;
        }
        if (counter <= size(inputfile) - 1) {
            file1.push_back(inputfile[counter]);
            counter++;
        }


        while (counter < size(inputfile) - 1 && inputfile[counter] <= inputfile[counter + 1]) {
            file2.push_back(inputfile[counter]);
            counter++;
        }
        if (counter <= size(inputfile) - 1) {
            file2.push_back(inputfile[counter]);
            counter++;
        }
    }

    vector <int> output;

    if (file1.size() == 0) {
        out(file2);

    }
    else
        if (file2.size() == 0) {
            out(file1);
        }
        else
            Fibonachchi(file1, file2, 0, 0, output);

}; 
// Поиск серий в алгоритме