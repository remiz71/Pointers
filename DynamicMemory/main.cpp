#include <iostream>

using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int& n, const int value);
int* push_front (int arr[], int& n, const int value);
int* insert (int arr[], int& n, const int value);
int* erase (int arr[], int& n);
int* pop_front(int arr[], int& n);
int* pop_back(int arr[], int& n);


void main()
{

	setlocale(LC_ALL, "");
	int n;
	int Choise;
	int value;
	cout << "Введите размер массива : "; cin >> n;
	int* arr = new int[n];
	
	FillRand(arr, n);
	Print(arr, n);
	cout << "----------------MENU--------------" << endl;
	cout << "Enter № of action" << endl;
	cout << tab <<"1.Add value in the front of arr" <<tab << endl;
	cout << tab << "2.Add value in the end of arr " << tab << endl;
	cout << tab <<"3. Insert value in arr ( you choose index )" <<tab << endl;
	cout << tab <<"4. Delete value in the front of arr" << tab << endl;
	cout << tab <<"5. Delete value in the end of array"<<tab << endl;
	cout << tab <<"6. Erase cell from array (you choose index)"<< tab  << endl;
	cout << tab <<"0. EXIT" << tab  << endl;
	cout << tab << " Your Choise : "; cin >> Choise;
	
		switch (Choise)
		{
		case 1:
			cout << "Введите добавляемое значение: "; cin >> value;
			arr = push_front(arr, n, value);
			Print(arr, n);
			delete[] arr;
			break;
		case 2:
			cout << "Введите добавляемое значение: "; cin >> value;
			arr = push_back(arr, n, value);
			Print(arr, n);
			delete[] arr;
			break;
		case 3:
			cout << "Введите добавляемое значение: "; cin >> value;
			arr = insert(arr, n, value);
			Print(arr, n);
			delete[] arr;
			break;
		case 4:
			cout << "Deleting the value of first cell in array" << endl;
			arr = pop_front(arr, n);
			Print(arr, n);
			delete[] arr;
			break;
		case 5:
			cout << "Deleting the value of last cell in array" << endl;
			arr = pop_back(arr, n);
			Print(arr, n);
			delete[] arr;
			break;
		case 6:
			cout << "Deleting the cell in array you choose" << endl;
			arr = erase(arr, n);
			Print(arr, n);
			delete[] arr;
			break;
		case 0:
			break;
		}
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab ;
	}
	cout << endl;
}
int* push_back(int arr[], int& n, const int value)
{
	int* brr = new int[n + 1]{}; //Зануляет выделяемую память
	for (int i = 0; i < n; i++)
	{
		brr[i] = arr[i];
	}
	delete[] arr;
	brr[n] = value;
	n++;
	arr = brr;
	return arr;
}
int* push_front(int arr[], int& n, const int value)
{
	int* brr = new int[n + 1]{}; //Зануляет выделяемую память
	for (int i = 0; i < n; i++)
	{
		brr[i+1] = arr[i];
	}
	delete[] arr;
	brr[0] = value;
	n++;
	arr = brr;
	return arr;
}
int* insert(int arr[], int& n, const int value)
{
	int ind = 0;
	cout << "Введите индекс ячейки массива : "; cin >> ind;
	int* brr = new int[n + 1]{}; //Зануляет выделяемую память
	for (int i = 0; i < n + 1; i++)
	{
		if (i >= ind)	brr[i + 1] = arr[i];
		else brr[i] = arr[i];
	}
	brr[ind] = value;
	n++;
	arr = brr;
	return arr;
}
int* erase(int arr[], int& n)
{
	int ind = 0;
	cout << "Введите индекс ячейки массива : "; cin >> ind;
	int* brr = new int[n + 1]{}; //Зануляет выделяемую память
	for (int i = 0; i < n + 1; i++)
	{
		if (i > ind)	brr[i - 1] = arr[i];
		else brr[i] = arr[i];
	}
	n--;
	arr = brr;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	int* brr = new int[n - 1]{}; //Зануляет выделяемую память
	for (int i = 0; i < n; i++)
	{
		brr[i] = arr[i + 1];
	}
	delete[] arr;
	n--;
	arr = brr;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* brr = new int[n - 1]{}; //Зануляет выделяемую память
	for (int i = 0; i < n; i++)
	{
		if (i != (n - 1)) brr[i] = arr[i];
		else break;
	}
	delete[] arr;
	n--;
	arr = brr;
	return arr;
}