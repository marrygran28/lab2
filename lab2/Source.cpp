//Вариант 10

#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>        

using namespace std;

void task_2_1_1();
void task_2_1_2();
void task_2_2();
void task_2_3();
void task_2_4();
void task_2_5();
void task_2_6();
void task_2_7();
long double fact(int N);
double valid_input(double temp);
double valid_input_2_4(double temp);
int valid_input_int(int n);

void main()
{
	setlocale(LC_ALL, "Russian");
	int option;
	while (true)
	{
		system("CLS");
		cout << "ЛИНЕЙНЫЕ АЛГОРИТМЫ И ВЕТВЛЕНИЯ:\n"
			<< "0. ВЫХОД\n"
			<< "1. 2.1.1\n"
			<< "2. 2.1.2\n"
			<< "3. 2.2\n"
			<< "4. 2.3\n"
			<< "5. 2.4\n"
			<< "6. 2.5\n"
			<< "7. 2.6\n"
			<< "8. 2.7\n"
			<< "\nВВЕДИТЕ НОМЕР ЗАДАНИЯ:\t";

		while (true)
		{
			cin >> option;
			if (cin) break;
			cin.clear();
			rewind(stdin);
			cout << "Неверное значение. Повторите ввод\t" << endl;
		}

		switch (option)
		{
		case 0: return;
		case 1: task_2_1_1(); break;
		case 2: task_2_1_2(); break;
		case 3: task_2_2(); break;
		case 4: task_2_3(); break;
		case 5: task_2_4(); break;
		case 6: task_2_5(); break;
		case 7: task_2_6(); break;
		case 8: task_2_7(); break;
		default: break;
		}
		system("PAUSE");
	}
}


void task_2_1_1()
{
	//10.	Дано натуральное  n. Верно ли, что это число содержит более k одинаковых цифр ?

	int num, k, num_copy, i,
		amount,  //считает сколько одинаковых цифр
		max_amount = 0; //считает максимальное количество одинаковых цифр

	cout << "Введите целое число\t";
	num = valid_input(num = 0);
	k = valid_input_int(k = 0);

	num = abs(num);
	for (max_amount = 0, i = 0; i < 10; i++)
	{
		amount = 0;
		num_copy = num;
		for (; num_copy >= 1; num_copy /= 10)
		{
			if (num_copy % 10 == i)
				amount++;
		}
		if (max_amount < amount)
			max_amount = amount;
	}

	if (max_amount > k) cout << "\nЧисло " << num << " содержит более " << k << " одинаковых цифр" << endl;
	else cout << "\nЧисло " << num << " содержит не более " << k << " одинаковых цифр" << endl;
	cout << endl << max_amount << endl;
}

void task_2_1_2()
{
	//Верно ли, что первые n цифр дробной части заданного положительного вещественного числа одинаковы ?

	double num;
	int n;

	cout << "Введите положительное число\t";
	num = valid_input(num = 0);

	cout << "Введте количество чисел\t";
	n = valid_input_int(n = 0);

	int pow_num;
	pow_num = num * (int)pow(10, n);

	/*n--;
	while (pow_num % 10 == (pow_num / 10) % 10 && n)
	{
		n--;
		pow_num /= 10;
	}*/

	for (n--; pow_num % 10 == (pow_num / 10) % 10 && n; n--, pow_num /= 10);

	if (!n) cout << "\nTRUE\n";
	else cout << "\nFALSE\n";

}

double valid_input(double temp)
{
	while (true)
	{
		cin >> temp;
		if (cin) return temp;
		cin.clear();
		rewind(stdin);
		cout << "Неверное значение. Повторите ввод\t" << endl;
	}
}

int valid_input_int(int n)
{
	while (true)
	{
		cin >> n;
		if (cin && n >= 0) return n;
		cin.clear();
		rewind(stdin);
		cout << "Неверное значение. Повторите ввод\t" << endl;
	}
}

void task_2_2() 
{
	//Составить  программу  вычисления  значений  функции   в точках хi c [х0; хn], хi = х0 + i*delta_х, i = 0, 1, …,
	//воспользовавшись формулами разложения элементарных функций в ряд Тейлора с точностью eps = 10^–6.
	//Вывести на экран необходимое количество слагаемых в каждом случае.Сравнить результаты со значениями функции в этих точках, 
	//вычисленных с помощью встроенных функций системы программирования

	static double eps = 1e-6;
	double y = 0, y_i = -1, y_k = 1,
		dx = 0.2, x_0, x_n,
		x_i = 0;
		
	int k, i;
	for (i = 0, x_0 = -0.1, x_n = 0.9; x_i < x_n; i++)
	{
		x_i = x_0 + i * dx;
		for (k = 0, y_i = -1, y_k = 1; abs(y_k) > eps; k++)
		{
			if (k)
				y_k *= -x_i * x_i;
		
			//y_k = pow(-1, k) * pow(x_i, 2 * k);
			//cout << y_k << " + ";
			y_i += y_k;
		}

		cout << "y1 = " << y_i << "     k_ITER= " << k << endl;
		y = 1 / (1 + pow(x_i, 2)) - 1;
		cout << '\t' << y << endl;
	}

	
}

void task_2_3() 
{
	//Сверхпростым называется число, если оно простое, и число, 
	//полученное из исходного числа при записи цифр исходного числа в обратном порядке(«перевертыш»), 
	//тоже будет простым. Найти все четырехзначные сверхпростые числа.

	int num, _num, a, b, c, d;
	bool flag = 0;	//если 0 - число простое, 1 - составное

	for (int num = 1001; num <= 5000; num+=2)
	{
		d = num % 10;
		c = num / 10 % 10;
		b = num / 100 % 10;
		a = num / 1000;
		_num = a + 10 * b + 100 * c + 1000 * d; 

		flag = 0;
		for (int div = 2; div < sqrt(num) + 1; div++)
		{
			if (num % div == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag) continue;

		for (int div = 2; div < sqrt(_num) + 1; div++)	
		{
			if (_num % div == 0) 
			{
				flag = 1;
				break;
			}
		}
		if (flag) continue;

		cout << num << '\t' << _num << endl;
	}
}

void task_2_4()
{
	//Дано  действительное  число  х (0 < x <= 1).  Вычислить  заданную сумму  с  точ-ностью  = 10–6 и указать количество слагаемых. 
	//Считать, что требуемая точность достигнута, если очередное слагаемое по абсолютному значению меньше :
	static double eps = 10e-6;
	double y = 0, y_i=0, y1, x;
	int i = 1;

	cout << "Введите зачение аргумента (0 < x <= 1)\tx = ";
	x = valid_input_2_4(x = 0);

	y_i = x * x / 2;
	while(true)
	{
		y_i *= -x * i / (i + 2) / (i + 1);
		if (abs(y_i) < eps) break;
		y += y_i;
		i++;
	}
	cout << endl << "y = " << y << endl;
	cout << "Количество слагаемых \t" << i << endl;

	
	cout << "\nВычисления с помощью библиотечных функций: y = ";
	for (i = 1, y = 0;; i++)
	{
		y_i = pow(-x, i + 2) / fact(i + 2) / (i + 1);
		if (abs(y_i) < eps) break;
		y += y_i;
	}
	cout << y << "\nКоличество слагаемых\t" << i << endl;
}

double valid_input_2_4(double temp)
{
	while (true)
	{
		cin >> temp;
		if (cin && temp > 0 && temp <= 1) return temp;
		cin.clear();
		rewind(stdin);
		cout << "Неверное значение. Повторите ввод\t" << endl;
	}
}

long double fact(int N)
{
	if (N < 0) 
		return 0; 
	if (N == 0) 
		return 1; 
	else
		return N * fact(N - 1);
}

void task_2_5()
{
	//10. Вводится последовательность из n вещественных чисел. Определить
	//количество элементов в наиболее длинной подпоследовательности подряд
	//идущих чисел, представляющих собой степени тройки.
	float n;
	int amount = 0, max_amount = 0;
	bool flag = 0;

	cout << "\nВведите 0 чтобы закончить ввод\n";

	while (true)
	{
		if (flag) amount = 0;

		n = valid_input(n = INT_MAX);
		if (n == 0) break;
		while (n >= 3)
			n /= 3;
		
		if (n != 1 && n != -1)
		{
			flag = 1;	//сигнал перехада к следующей операции
			continue;
		}
		amount++;
		if (amount > max_amount)
			max_amount = amount;
		flag = 0;
	}

	cout << "\nКоличество элементов в наиболее длинной подпоследовательности:\t " << max_amount << endl;


}

void task_2_6()
{
	//Выполнить задания без хранения последовательности значений
	//Задано  натуральное  число k. 
	//Определить k-ю цифру  последовательности: 149162536..., в которой выписаны подряд квадраты натуральных чисел;

	int k, num;
	k = valid_input_int(k = 0);
	int counter = 0;
	int sqr, i = 1, amount = 0, digit;

	while (true)
	{
		sqr = i * i;
		counter = 0;

		while (sqr >= 1)
		{
			counter++;
			sqr /= 10;
		}

		amount += counter;
		sqr = i * i;

		if (k < amount)
		{
			int d = amount - k;
			do
			{
				digit = sqr % 10;
				sqr /= 10;
			} while (d--);
			cout << "Цифра\t" << digit << endl;
			return;
		}
		i++;
	}
}

void task_2_7()
{
	//Вычислить значение многочлена 2n*x^(2n-1) + ... + 4x^3 + 2^x + 5 для заданного n  в точках  хi  [х0; хm]
	//(хi = х0 + iх, i = 0,1,…,) двумя способами: 
	//суммируя элементы по возрастанию степени x и по схеме Горнера. 
	//Посчитать количество операций сложения и умножения в том и другом случае. 

	double y = 0, y_i = -1, y_k = 1,
		dx = 0.2, x_0 = 1, x_n = 5,
		x_i = 0;

	int k, i, n, sum = 0, mult = 0;

	cout << "Введите n:\t";
	n = valid_input_int(n = 0);
	for (i = 0; x_i < x_n; i++)
	{
		sum = 0;
		mult = 0;
		x_i = x_0 + i * dx;
		cout << "\nx_i = " << setw(3) << x_i;

		y_k = 2 * x_i; sum++;
		y_i = 5 + y_k; sum++;
		for (k = 1; k < n; k++)
		{
			y_k *= x_i * x_i * (2 * k + 2) / (2 * k); mult += 3;
			y_i += y_k;	sum++;

		}
		cout << "\ty_i = " << y_i;
	}
	cout <<"\n\tsum = " << sum << "\tmultiplication = " << mult;
/////////////////////////////////////////////////////////////////
	cout << "\nВычисление методом Горнера...\n";

	x_i = 0;
	int a_i;
	for (i = 0; x_i < x_n; i++)
	{
		sum = 0;
		mult = 0;
		y_i = 0;
		x_i = x_0 + i * dx;

		cout << "\nx_i = " << setw(5) << x_i;

		k = n;
		for (y_i = 0; k > 0; k--)
		{
			a_i = 2 * k; 
			y_i = y_i * x_i * x_i + a_i; mult ++; sum++;
		}
		y_i *= x_i; mult++;
		y_i += 5; sum++;

		cout << "\ty_i = " << y_i << "\t";
	}
	cout << "\n\tsum = " << sum << "\tmultiplication = " << mult << endl;
}
