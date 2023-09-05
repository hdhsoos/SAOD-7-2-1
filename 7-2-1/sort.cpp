#include "sort.h"
using namespace std;

bool comp(int a, int b) {
	return a ? (a > b) : b;
}

void fill_array(vector<int>& arr) {
	cout << "Введите количество элементов в массиве (не больше 10 000)" << endl;
	int n;
	cin >> n;
	for (int i{ 0 }; i < n; i++) {
		arr.push_back(rand() % 100);
	}
}

void bubble_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };

	for (int i{ 0 }; i < arr.size() - 1; i++) {
		for (int j{ 0 }; j < arr.size() - i - 1; j++) {
			n_comps++;
			if (comp(arr[j], arr[j + 1])) {
				n_reeqs += 3;
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	// проверяет соседние элементы и меняет местами
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void insertion_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };
	int i, key, j;

	for (i = 1; i < arr.size(); i++)
	{
		n_reeqs++;
		key = arr[i];
		j = i - 1;
		n_comps++;
		while (j >= 0 && comp(arr[j], key))
		{
			n_comps++;
			arr[j + 1] = arr[j];
			n_reeqs++;
			j--;
		}

		if (arr[j + 1] != key) {
			n_comps++;
			arr[j + 1] = key;
		}
	}
	// один элемент сравнивает со всеми, пока тот не встанет на место
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void selection_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };

	for (int i{ 0 }; i < arr.size() - 1; i++) {
		int min_ind = i;
		for (int j{ i + 1 }; j < arr.size(); j++) {
			n_comps++;
			if (arr[min_ind] > arr[j]) {
				min_ind = j;
			}
		}
		if (min_ind != i) {
			n_reeqs += 3;
			swap(arr[i], arr[min_ind]);
		}
	}
	// поиск наименьшего элемента и перемещение его в отсортированную часть списка
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void output_array(vector<int>& arr) {
	for (int i{ 0 }; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}