#include <iostream>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//#define POINTERS_BASICS
//#define POINTERS_AND_ARRAYS
#define HOMEWORK

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a; // ѕоказывает, что обь€вл€ема€ переменна€ - указатель
	cout << a << endl;
	//ѕолучаем адрес прямо при выводе
	cout << &a << endl; // ќператор вз€ти€ адреса _ address-of operator возвращает адрес своего операнда, имеет только префиксную форму записи.
	//¬ыводим адрес переменной "а", хран€щийс€ в указателе ра
	cout << pa << endl;
	//–азыменовываем указател и получаем значение по адресу
	cout << *pa << endl; //ќператора разыменовани€ (dereference) унарный оператор, который возвращает значение по адресу, имеет только префиксную форму записи. 
						 //“олько при обь€вление указател€, указывает что обь€вл€ема€ переменна€ - указатель. ¬о всех остальных случа€х звездочка разыменовыввет указатель
	int* pb;
	int b = 3;
	pb = &b;
	cout << pb << endl;
	cout << *pb << endl;





	return 0;
#endif // POINTERS_BASICS

#ifdef POINTERS_AND_ARRAYS
	const int n = 5;
	short arr[n] = { 3, 5, 8, 13, 21 };
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << tab;
	}
#endif // POINTERS_AND_ARRAYS
#ifdef HOMEWORK/
	int n = 10; //–азмер массива
	cout << "введите размер массива:  "; cin >> n;
	int* arr = new int[n]; // ќператор new выдел€ет пам€ть под н элементов указанного типа, в данном случае int
						   // » возвращает адрес выделенной пам€ти.
						   // Ётот адрес мы присваиваем указателю arr	
						   // ”казатель нужен, чтобы сохранить адрес массива


	FillRand(arr, n);
	Print(arr, n);
	cout << endl;

	int SizeODD = 0;
	int SizeEVEN = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) SizeEVEN++;
		else SizeODD++;
	}

	int* even = new int[SizeEVEN];
	int* odd = new int[SizeODD];

	for (int i = 0,j=0,k=0; i < n; i++)
	{
		if (arr[i] % 2)
			odd[j++] = arr[i];
		else
			even[k++] = arr[i];
	}
	Print(even, SizeEVEN);
	cout << endl;
	Print(odd, SizeODD);

	delete[] arr;
	delete[] even;
	delete[] odd;
#endif // HOMEWORK


}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100 - 10;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}
