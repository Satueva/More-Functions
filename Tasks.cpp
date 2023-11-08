#include <iostream>

// Все локальные переменные ограничиваются строго тем блоком и теми фигурными скобочками, в рамках которых они были созданы.

//Области применения статических элементов:
// 1. Сохранение данных из вызова в вызов функций;
// 2. Экономия памяти и времени выполнения;
// 3. Создание общих элементов, относящихся к конкретным группам объектов. (пока не изучено)

// Функцию невозможно встроить, если место, в котором она вызывается, не может содержать в себе код, опсанный в теле функции. 
// Например:
// 1. Слишком большой размер функции; 
// 2. Функция повторяется в одном и том же выражении; 
// 3. Функция содержит управляющие конструкции (цикл, ветвление и т. д.); 
// 4. Функция является рекурсивной.
                                                                                         
int NUM; // глобальна переменная

const double PI = 3.14; // глобальная константа
const int SIZE = 5; // глобальная константа
int ARR[SIZE]; // глобальный массив

void num_inc() {
	NUM++;
}
void func() {
	static int a = 0; // или int a = 0; (консоль выдаст 1, 1, 1)
	                  // статическа переменная, ко торая не удаляется при завершение работы программы. 
					  // Создаётся один единственный раз 
	a++;
	std::cout << a << std::endl;
	if (a % 5 == 0);
	std::cout << "---\n";
}
int power(int num1, int num2 = 2) {
		int result = 1;
		for (int i = 1; i <= num2; i++)
			result *= num1;
		return result;
	}

// Встраиваемая функция inline (нихрена не меняет)
inline double absolute(double num) {
	return (num < 0.0 ? -num : num);
}
int max(int num1, int num2) {
	std::cout << "TWO INTS\n";
	return num1 > num2 ? num1 : num2;
}
double max(double num1, double num2) {
	std::cout << "TWO DOUBLES\n";
	return num1 > num2 ? num1 : num2;
}
char max(char sym1, char sym2) {
	std::cout << "TWO CHARS\n";
	return sym1 > sym2 ? sym1 : sym2;
}
int max(int num1, int num2, int num3) {
	std::cout << "THREE INTS\n";
	return num1 > max(num2, num3) ? num1 : max(num2, num3);
}

template <typename T>
void print_arr(T arr[], const int lenght) {
	for (int i = 0; i < lenght; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Области видимости данных 
	std::cout << NUM << std::endl;
	num_inc();
	std::cout << NUM << std::endl;
	std::cout << "PI = " << PI << std::endl;

	func();
	func();
	func();

	for (int i = 0; i < 15; i++)
		func();

	// Параметры по умолчанию 
	std::cout << "5^3 = " << power(5, 3) << std::endl;
	std::cout << "9^1 = " << power(9, 1) << std::endl;
	std::cout << "7^2 = " << power(7) << std::endl;
	std::cout << "11^2 = " << power(11) << std::endl; 

	// Встраеваемая функция
	std::cout << "Введите число: ";
	std::cin >> n;
	std::cout << '|' << n << "| = " << absolute(n) << std::endl;

	// Перегруженная функция
	std::cout << max(5, 7) << std::endl << std::endl;
	std::cout << max(1.3, 1.6) << std::endl << std::endl;
	std::cout << max('k', 'K') << std::endl << std::endl;
	std::cout << max(5, 6, 9) << std::endl << std::endl;

	// Шаблонная функция
	const int size = 5;
	int arr[size]{ 50, 60, 10, 30, 70 };
	std::cout << "Массив:\n";
	print_arr(arr, size);




	return 0;
}