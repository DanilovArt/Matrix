/*
9.	�����: ������� ����. 13501/4
������� m x n ������� �� ���������� � ������������ ��������� ���������. 
������� �� ���� �� ���� ������� �� ������� �� ���� ���������? ������� ���������� ������� ��������. 
������� ������� ������� ������ �� ����� in.txt (������ ��� ����� � ����� � ����������� �������, 
����� � �������� �������, 0 � ������������, 1 - ����������), ��������� ������� ���������� � ���� out.txt 
(��������� ���, ��� ������� N ��������� � ������������� �� ���������).
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
		cout << "������ ���� in.txt �� ����������";
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
					out << "������ " << i + 1 << endl;
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
					out << "������� " << i + 1 << endl;
					c++;
				}

			}
		}
		b = 0;

	}
	if (c>0){
		out << "���������� ���������: " << c;
	}
	else 
		out << "��������� ���";
	return 0;
}

