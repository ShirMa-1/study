#include "stdafx.h"
#include <ctime>
#include <iostream>
using namespace std;

int Correct(int N, int* a) //функция, проверяющая отсортированность массива
{
    while (N-- > 0)
        if (a[N-1] > a[N])
			return 0;
    return 1;
}

void Shuffle(int N, int* a) //процедура перетасовки элементов массива
{
    for (int i=0; i<N; ++i) 
		swap(a[i], a[(rand()%N)]);
}

void BogoSort(int N, int* a)
{
    while (!Correct(N, a))
        Shuffle(N, a);
}

void Heap(int N, int* a, int i)
{
	int max=i, left=2*i+1, right=2*i+2;
	if (left<N && a[left]>a[max])// левый дочерний больше корня
		max=left;
	if (right<N && a[right]>a[max])  // правый дочерний больше максимального на данный момент
		max = right;
	if (max!=i) // если элемент вершины меньше максимального потомка
	{
		swap(a[i],a[max]);
		Heap(N, a, max);
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL , "Russian");
	
	cout.width(5);	// Общее количество символов
	cout.precision(3); // Количество символов после запятой
	cout.setf(ios::fixed); // Фиксированная точка

	int N; // размер массива
	int *a;
	int x, j;


								// Богосорт
	cout << endl << "\t\t\t Богосорт:" << endl;
	cout << "Введите размер массива N = ";
	cin >> N; 
	a = new int[N];

	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	for (int i=0; i<N; i++) // Заполнение массива и вывод значений его элементов
	{
		a[i] = int(double(rand())/double(RAND_MAX)*200-100); // всего 200, от -100 до 100
//		cout << "Элемент под номером " << i << "  равен " << a[i] << endl;
	}			

	clock_t time1 = clock();
	BogoSort(N, a);
	time1 = clock()-time1;

//	for (int i=0; i<N; i++) cout << a[i] << " ";
	cout << "Время = " << (double)time1/CLOCKS_PER_SEC << " c" << endl;
	delete [] a;


								// Сортировка вставками
	cout << endl << "\t\t\t Сортировка вставками:" << endl;
	cout << "Введите размер массива N = ";
	cin >> N; 
	a = new int[N];
	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	for (int i=0; i<N; i++) // Заполнение массива и вывод значений его элементов
	{
		a[i] = int(double(rand())/double(RAND_MAX)*200-100); // всего 200, от -100 до 100
//		cout << "Элемент под номером " << i << "  равен " << a[i] << endl;
	}							
	
	clock_t time2 = clock();
	for (int i=1; i<N; i++)
	{
		x=a[i];
		j=i;
		while(j>0 && a[j-1]>x)
		{
			swap(a[j],a[j-1]);
			j--;
		}
	}
	time2=clock()-time2;

//	for (int i=0; i<N; i++) cout << a[i] << " ";
	cout << "Время = " << (double)time2/CLOCKS_PER_SEC << " c" << endl;
	delete [] a;

	
								// Сортировка кучей
	cout << endl << "\t\t\t Сортировка кучей:" << endl;
	cout << "Введите размер массива N = ";
	cin >> N; 
	a = new int[N];
	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	for (int i=0; i<N; i++) // Заполнение массива и вывод значений его элементов
	{
		a[i] = int(double(rand())/double(RAND_MAX)*200-100); // всего 200, от -100 до 100
//		cout << "Элемент под номером " << i << "  равен " << a[i] << endl;
	}	

	clock_t time3 = clock();
	for (int i=N/2-1; i>=0; i--) Heap(N, a, i); // строим max-кучу (просеивание вниз)
	for (int i=N-1; i>=0; i--) // перестраиваем в правильный порядок
	{
		swap(a[0], a[i]); // текущий корень поместить в конец массива
		Heap(i, a, 0); // строим max-кучу из оставшихся элементов
	}
	time3=clock()-time3;

//	for (int i=0; i<N; i++) cout << a[i] << " ";
	cout << "Время = " << (double)time3/CLOCKS_PER_SEC << " c" << endl;			
	delete [] a;

	system("pause");
	return 0;
}
