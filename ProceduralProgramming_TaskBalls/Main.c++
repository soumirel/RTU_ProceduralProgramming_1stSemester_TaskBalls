#include <iostream>

using namespace std;


int inputPositiveNumberCorrect() {
	int input_number;
	while (!(cin >> input_number) || (input_number <= 0)) {
		cout << "Некорректный ввод данных. Пожалуйста, введите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input_number;
}


void swapItems(int* arr, int firstInd, int secondInd) { // Перестановка двух элементов массива
	int tempItem = arr[firstInd];
	arr[firstInd] = arr[secondInd];
	arr[secondInd] = tempItem;
}


int* perestanovka(int* arr, int n) { //Ужасное название функции, но так сказала Лизочек
	int i = n - 2;
	while (i != -1 && arr[i] >= arr[i + 1]) i--;
	if (i == -1) return 0; // Отсутсвие перестановок

	int j = n - 1;
	while (arr[i] >= arr[j]) j--;
	swapItems(arr, i, j);

	int left = i + 1;
	int right = n - 1;
	while (left < right) {
		swapItems(arr, left++, right--);
	}
	return arr;
}

void main(){
	setlocale(LC_ALL, "Russian");
	int arraySize;
	int* arr;
	cout << "Введите кол-во шариков в урне: ";
	arraySize = inputPositiveNumberCorrect();
	arr = new int[arraySize];
	for (int i = 0; i < arraySize; i++){  
		arr[i] = i + 1;    //Заполнение "урны" "шариками" с номерами от 1 до N
	}
	long int answer = 1;
	while (perestanovka(arr, arraySize)) {
		for (int i = 1; i <= arraySize; i++) {
			if (i == arr[i - 1]) {
				answer++;
				break;
			}
		}
	}
	cout << "\nКол-во ситуаций, когда номер хотя бы одного вынутого шарика\nсовпадает с порядковым номером действия \"вынимания\" равен: " << answer << endl;
}