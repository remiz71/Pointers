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
	int* pa = &a; // ����������, ��� ����������� ���������� - ���������
	cout << a << endl;
	//�������� ����� ����� ��� ������
	cout << &a << endl; // �������� ������ ������ _ address-of operator ���������� ����� ������ ��������, ����� ������ ���������� ����� ������.
	//������� ����� ���������� "�", ���������� � ��������� ��
	cout << pa << endl;
	//�������������� �������� � �������� �������� �� ������
	cout << *pa << endl; //��������� ������������� (dereference) ������� ��������, ������� ���������� �������� �� ������, ����� ������ ���������� ����� ������. 
						 //������ ��� ���������� ���������, ��������� ��� ����������� ���������� - ���������. �� ���� ��������� ������� ��������� �������������� ���������
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
	int n = 10; //������ �������
	cout << "������� ������ �������:  "; cin >> n;
	int* arr = new int[n]; // �������� new �������� ������ ��� � ��������� ���������� ����, � ������ ������ int
						   // � ���������� ����� ���������� ������.
						   // ���� ����� �� ����������� ��������� arr	
						   // ��������� �����, ����� ��������� ����� �������


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
