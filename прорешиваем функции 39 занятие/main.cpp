#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

//Task1 вывод типа данных числа
void typeof(int num)
{
	std::cout << "int\n";
}
void typeof(double num)
{
	std::cout << "double\n";
}
void typeof(char num)
{
	std::cout << "char\n";
}

//Task2 рекурсивная сумма диапазонa
int sum_AB(int A, int B); //протатип функции sum_AB

//Task3 сортировка от первого и последнего отрицательных чисел в массиве, т.е. середины
template <typename T>
void fill_arr(T arr[], const int length, int left, int right)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}
//3. Выввод массива в кон7соль
template <typename T>
void print_arr(T arr[], const int length)
{
	std::cout << "{ ";
	for(int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
// 3. Вывод сортировки
template <typename T>
void middle_sort(T arr[], const int length);

//Task4 циклический сдвиг массива вперед (то есть по кругу)
template <typename T>
void move_arr(T arr[], const int length, int steps);


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//Task1 вывод типа данных числа
	
	std::cout << "7 - "; typeof(7);
	std::cout << "0,15 - "; typeof(0.15);
	std::cout << "'E' - "; typeof('E');
	std::cout << "\n\n";
	

	//Task2
	
	std::cout << "Введите начало диапазона -> ";
	std::cin >> n;
	std::cout << "Введите конец диапазона -> ";
	std::cin >> m;
	std::cout << "Сумма чисел от " << n << " до " << m << " = " << sum_AB(n, m) << "\n\n";
	

	//Task3
	
	std::cout << "изначальный массив:\n";
	const int size3 = 10;
	int arr3[size3]{};
	fill_arr(arr3, size3, -20, 21); 
	print_arr(arr3, size3);

	middle_sort(arr3, size3);
	std::cout << "итоговый массив:\n";
	print_arr(arr3, size3);
	

	//Task4
	std::cout << "Изначальный массив:\n";
	const int size4 = 5;
	int arr4[size4]{ 1, 2, 3, 4, 5 };
	print_arr(arr4, size4);

	std::cout << "Введите количество сдвигов -> ";
	std::cin >> n;
	move_arr(arr4, size4, n);
	std::cout << "Итоговый массив:\n";
	print_arr(arr4, size4);

	return 0;
}

//Task4 циклический сдвиг массива вперед (то есть по кругу), и обратно если n отрицательная
template <typename T>
void move_arr(T arr[], const int length, int steps)
{
	if (steps < 0)
		for (int j = 0; j < steps; j++)
			for (int i = 0; i < length - 1; i++)
				std::swap(arr[i], arr[i + 1]);
		else
		for (int j = 0; j < steps; j++)
			for (int i = length - 2; i >= 0; i--)
				std::swap(arr[i], arr[i - 1]);
}

//Task2
//реализация функции sum_AB
int sum_AB(int A, int B)
{
	if (A > B)
		std::swap(A, B);
	if (A == B) //смотреть пример в телефоне где начало и конец равны друг другу
		return A;
	return sum_AB(A, B - 1) + B; 
}

//Task3
template <typename T>
void middle_sort(T arr[], const int length)
{
	int first_negative = -1, last_negative = -1; //-1 означает что при выводе плюсового массива программа будет работать
	for (int i = 0; i < length; i++)
		if (arr[i] < 0)
		{
			first_negative = i;
			break;
		}
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] < 0)
		{
			last_negative = i;
			break;
		}
	// Пузырькова сортировка
	/*
	for (int i = last_negative - 1; i > first_negative + 1; i--)
		for (int j = first_negative + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
				*/

	// Быстрая сортировка
	if (first_negative != -1 && first_negative != last_negative)
		std::sort(arr + first_negative, arr + last_negative); 
}