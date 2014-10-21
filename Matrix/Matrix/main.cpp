/*
9.	Автор: Данилов Артём. 13501/4
Матрица m x n состоит из прозрачных и непрозрачных маленьких квадратов. 
Имеется ли хотя бы один просвет по каждому из двух измерений? Вывести координаты каждого просвета. 
Входную матрицу следует читать из файла in.txt (первые два числа в файле – размерности матрицы, 
далее – элементы матрицы, 0 – непрозрачный, 1 - прозрачный), результат следует записывать в файл out.txt 
(просветов нет, или найдено N просветов с перечислением их координат).
*/


// 0 1 0 1 --> N
// 1 1 1 1 --> Y
// 0 1 0 1 --> N
// v v v v
// N Y N Y



#include <iostream>
#include <fstream>
using namespace std;
int m, n;
int b= 0;
int main(void){
	setlocale(LC_ALL, "");
	ifstream in("in.txt");
	ofstream out("out.txt");
	if (!in.is_open()){
		cout << "Ошибка файл in.txt не существует";
		return -1;
	}
	int c=0;
	in >> m >> n;
	int** arr = new int*[m];
	for (int i = 0; i < m; i++)
		arr[i] = new int[n];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			in >> arr[i][j];
			if (arr[i][j] == 1){
				b = b + 1;
				if (b == n){
					out << "Строка " << i + 1 << endl;
					c++;
				}

			}
		}
		b = 0;	
	}
	b = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (arr[j][i] == 1){
				b = b + 1;
				if (b == m){
					out << "Столбец " << i + 1 << endl;
					c++;
				}

			}
		}
		b = 0;

	}
	if (c>0){
		out << "Количество просветов: " << c;
	}
	else 
		out << "Просветов нет";
	return 0;
}

