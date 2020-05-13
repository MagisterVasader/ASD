#include <queue>
#include <vector>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int n; //количество городов и магистралей 
int count;//Количество мостов
vector <vector<int>> Myspisok; //Двумерное представление связей городов между собой
vector<int> NewZone;// через какие города мы проходим
bool two;//флаг соответсвия условию задачи
bool connect;//Можно ли добраться до этого города с двух сторон
int MaxColDisnumber;

int bfs(int v) {
	
	int ZeroOne[] = { 1,0 }; //путь в одну и во вторую сторону (Чет,нечет)
	int count = 1;//Количество мостов
	two = true;//флаг соответсвия условию задачи
	NewZone[v] = 0;

	queue<int> Newqueue; // Хранение четности нечетности

	Newqueue.push(v);
	//Проверка путей на честность-нечетноть
	while (!Newqueue.empty()) {
		
		int temp = Newqueue.front();
		Newqueue.pop();
		
		for (int i = 0; i < Myspisok[temp].size(); i++) {
			if (NewZone[Myspisok[temp][i]] == -1) {
		
				count++;
				NewZone[Myspisok[temp][i]] = (NewZone[temp] + 1) % 2;
				ZeroOne[(NewZone[temp] + 1) % 2]++;
				Newqueue.push(Myspisok[temp][i]);
			
			}
			else 
			if (NewZone[Myspisok[temp][i]] == NewZone[temp]) {
				two = false;
			}
		}
	}
// Будет ли догора засчитана, как четно-нечетная
	if (two) {
		if (ZeroOne[0] > ZeroOne[1]) {
			MaxColDisnumber += ZeroOne[0];
		}
		else {
			MaxColDisnumber += ZeroOne[1];
		}
	}
	else {
		MaxColDisnumber++;
	}
	
	cout << "Какие города были использованы ";
	
	for (int i = 0; i < NewZone.size(); i++) {
		cout << NewZone[i] << ' ';
	}

	cout << endl;

	cout << "Максимальная магистраль = " <<MaxColDisnumber << endl << "Соотноение четного с нечетным " << ZeroOne[0] << "  " << ZeroOne[1] << endl;

	return count;
}

int main() {

	setlocale(LC_CTYPE, "RUS");

	ifstream fin("input.txt");
	MaxColDisnumber = 0;

	
	fin >> n;
	
	Myspisok.resize(n);
	NewZone.assign(n, -1);

	string string;
	getline(fin, string);

	// Ввод данных, путем считывания строк файла
	int j = 0;	
	while (getline(fin, string)) {
	
		stringstream NewString;
		NewString = stringstream(string);
		while (NewString)
		{
			int buf;
			NewString >> buf;
			if (NewString && buf != 0) {
				Myspisok[j].push_back(buf - 1);
			}
		}
		j++;
	}

	//Вызов алгоритма, для проверки всех дорог
	int count = bfs(0);
	//Номер подмножества
	int times = 1;


	ofstream fout("output.txt");

	//Проверка пар на совпадение с условием
	if (count == n && !two) {
		fout << "YES";
	}
	else if (count == n && two) {
		fout << "NO" << endl;
		fout <<MaxColDisnumber; //мощность одного из максимальных по мощности подмножеств
	}
	else if (count != n) {

		for (int i = 0; i < n; i++) {
			if (NewZone[i] == -1) {
				count += bfs(i);
				times++;
			}
		}

		fout << "NO" << endl;
		fout <<MaxColDisnumber; //мощность одного из максимальных по мощности подмножеств
	}

	system("pause");
}