#include "sort.h"
#include "sort.cpp"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	menu();
}

void menu() {
	vector<int> arr;
	int choice;
	fill_array(arr);
	while (true) {
		cout << "Выберите пункт меню:" << endl;
		cout << "0 - выйти из программы" << endl;
		cout << "1 - пузырьковая сортировка" << endl;
		cout << "2 - сортировка вставками" << endl;
		cout << "3 - сортировка выбором" << endl;
		cout << "4 - заполнить массив новыми значениями" << endl;
		vector<int> arr1 = arr;
		cin >> choice;
		switch (choice) {
		case 0:
			return;
			break;
		case 1:
			bubble_sort(arr1);
			arr1.clear();
			break;
		case 2:
			insertion_sort(arr1);
			arr1.clear();
			break;
		case 3:
			selection_sort(arr1);
			arr1.clear();
			break;
		case 4:
			arr.clear();
			fill_array(arr);
			break;

		}
	}
}
