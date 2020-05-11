#include "stdafx.h"
#include <ctime>
#include <iostream>
using namespace std;

int Correct(int N, int* a) //�������, ����������� ����������������� �������
{
    while (N-- > 0)
        if (a[N-1] > a[N])
			return 0;
    return 1;
}

void Shuffle(int N, int* a) //��������� ����������� ��������� �������
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
	if (left<N && a[left]>a[max])// ����� �������� ������ �����
		max=left;
	if (right<N && a[right]>a[max])  // ������ �������� ������ ������������� �� ������ ������
		max = right;
	if (max!=i) // ���� ������� ������� ������ ������������� �������
	{
		swap(a[i],a[max]);
		Heap(N, a, max);
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL , "Russian");
	
	cout.width(5);	// ����� ���������� ��������
	cout.precision(3); // ���������� �������� ����� �������
	cout.setf(ios::fixed); // ������������� �����

	int N; // ������ �������
	int *a;
	int x, j;


								// ��������
	cout << endl << "\t\t\t ��������:" << endl;
	cout << "������� ������ ������� N = ";
	cin >> N; 
	a = new int[N];

	srand(static_cast<unsigned int>(time(0))); // ������������� �������� ��������� ����� � �������� ���������� �����
	for (int i=0; i<N; i++) // ���������� ������� � ����� �������� ��� ���������
	{
		a[i] = int(double(rand())/double(RAND_MAX)*200-100); // ����� 200, �� -100 �� 100
//		cout << "������� ��� ������� " << i << "  ����� " << a[i] << endl;
	}			

	clock_t time1 = clock();
	BogoSort(N, a);
	time1 = clock()-time1;

//	for (int i=0; i<N; i++) cout << a[i] << " ";
	cout << "����� = " << (double)time1/CLOCKS_PER_SEC << " c" << endl;
	delete [] a;


								// ���������� ���������
	cout << endl << "\t\t\t ���������� ���������:" << endl;
	cout << "������� ������ ������� N = ";
	cin >> N; 
	a = new int[N];
	srand(static_cast<unsigned int>(time(0))); // ������������� �������� ��������� ����� � �������� ���������� �����
	for (int i=0; i<N; i++) // ���������� ������� � ����� �������� ��� ���������
	{
		a[i] = int(double(rand())/double(RAND_MAX)*200-100); // ����� 200, �� -100 �� 100
//		cout << "������� ��� ������� " << i << "  ����� " << a[i] << endl;
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
	cout << "����� = " << (double)time2/CLOCKS_PER_SEC << " c" << endl;
	delete [] a;

	
								// ���������� �����
	cout << endl << "\t\t\t ���������� �����:" << endl;
	cout << "������� ������ ������� N = ";
	cin >> N; 
	a = new int[N];
	srand(static_cast<unsigned int>(time(0))); // ������������� �������� ��������� ����� � �������� ���������� �����
	for (int i=0; i<N; i++) // ���������� ������� � ����� �������� ��� ���������
	{
		a[i] = int(double(rand())/double(RAND_MAX)*200-100); // ����� 200, �� -100 �� 100
//		cout << "������� ��� ������� " << i << "  ����� " << a[i] << endl;
	}	

	clock_t time3 = clock();
	for (int i=N/2-1; i>=0; i--) Heap(N, a, i); // ������ max-���� (����������� ����)
	for (int i=N-1; i>=0; i--) // ������������� � ���������� �������
	{
		swap(a[0], a[i]); // ������� ������ ��������� � ����� �������
		Heap(i, a, 0); // ������ max-���� �� ���������� ���������
	}
	time3=clock()-time3;

//	for (int i=0; i<N; i++) cout << a[i] << " ";
	cout << "����� = " << (double)time3/CLOCKS_PER_SEC << " c" << endl;			
	delete [] a;

	system("pause");
	return 0;
}
