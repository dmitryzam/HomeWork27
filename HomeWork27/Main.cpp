#include<iostream>
#include<string>

// Структура Movie:
struct Movie {
	std::string title;		// название фильма
	int year;
	std::string genre;		// жанр фильма
	unsigned int duration;	// продолжительность фильма, мин.
	unsigned int price;		// стоимость фильма, руб.
};
// Прототип функции Задачи 1:
void print_movie(const Movie& A);
// Прототип функции Задачи 2:
Movie expensive(const Movie arr[], const int length);
// Прототип функции Задачи 3:
void update_info(Movie& A);

int main() {
	setlocale(LC_ALL, "RU");
	int n;	

	// Задача 1. Создайте функцию print_movie, которая принимает объект структуры и
	// выводит всю информацию о нём (т.е. выводятся значения полей объекта).
	std::cout << "Задача 1. Вывод информации о фильме.\n";
	Movie film1{		// создадим объект и инициализируем его
		"Mortal Combat",
		1995,
		"Action",
		101,
		500
	};
	print_movie(film1);	// вызов функции для вывода объекта в консоль
	std::cout << "===============================\n\n";
	
	// Задача 2. Создайте функцию expensive, которая принимает массив объектов структуры
	// и его длину, после чего возвращает ОБЪЕКТ из массива с самой высокой ценой за диск.
	// Чтобы вернуть объект, необходимо при создании функции использовать структуру Movie
	// как тип возвращаемого значения.
	std::cout << "Задача 2. Вывод информации о фильмах:\n";
	// массив из 5-ти струтктур и его инициализация:
	Movie films[5]{
		{ "The Silence of the Lambs", 1991, "Thriller", 118, 505 },
		{ "Home Alone", 1990, "Comedy", 103, 515 },
		{ "The Green Mile", 1999, "Drama", 189, 525 },
		{ "The Hobbit: An Unexpected Journey", 2012, "Adventures", 182, 520 },
		{ "A Nightmare on Elm Street", 1984, "Horrors", 91, 510}
	};
	// вывод на экран каждого фильма:
	for (int i = 0; i < 5; i++) {
		std::cout << "Фильм " << i + 1 << ":\n";
		print_movie(films[i]);
		std::cout << "---------------------" << std::endl;
	};
	std::cout << "Фильм с самой высокой стоимостью:\n";
	// создадим объект max_price структуры Movie и присвоим ему значения полей с помощью функции expensive:
	Movie max_price = expensive(films, 5);
	print_movie(max_price);		// вывод в консоль
	std::cout << "===============================\n\n";

	// Задач 3. Создайте функцию update_info, которая принимает объект структуры 
	// и позволяет поменять какую-нибудь информацию об этом объекте. Для решения данной задачи
	// необходимо в качестве параметра функции использовать указатель или ссылку на объект.
	std::cout << "Задача 3. Внесение изменения в информацию о фильме.\n";

	Movie film3 = film1;	// создадим объект film3 и присвоим ему значения полей объекта film1
	std::cout << "Исходная информации о фильме:\n";
	print_movie(film3);		// вывод в консоль
	std::cout << "---------------------" << std::endl;
	update_info(film3);
	std::cout << "---------------------" << std::endl;
	std::cout << "Измененная информации о фильме:\n";
	print_movie(film3);

	return 0;
}
// Функция Задачи 1:
void print_movie(const Movie& A) {
	std::cout << "Название фильма: " << A.title << std::endl;
	std::cout << "Год: " << A.year << std::endl;
	std::cout << "Жанр: " << A.genre << std::endl;
	std::cout << "Длительность: " << A.duration << " мин." << std::endl;
	std::cout << "Стоимость: " << A.price << " руб." << std::endl;
};
// Функция Задачи 2:
Movie expensive(const Movie arr[], const int length) {
	int max = 0, index = 0;		// создадим переменные max и index 
	max = arr[0].price;
	for (int i = 1; i < length; i++) {
		if (max < arr[i].price) {
			max = arr[i].price;
			index = i;		// фиксируем индекс максимального значения
		};
	};
	return arr[index];		// возвращаем объект (фильм) с самой высокой стоимостью в блок main
};
// Функция Задачи 3:
void update_info(Movie& A) {
	int index;
	std::cout << "\nВыберите, какую информацию о фильме необходимо обновить:\n";
	std::cout << "1. Название;\n";
	std::cout << "2. Год выхода;\n";
	std::cout << "3. Жанр;\n";
	std::cout << "4. Продолжительность;\n";
	std::cout << "5. Цена за диск.\n";
	std::cout << "Ввод -> ";
	std::cin >> index;
	// конструкция swith-case:
	switch (index) {
	case 1: std::cout << "Введите новое название фильма:\nВвод -> ";
		std::cin.ignore();
		std::getline(std::cin, A.title);
		break;
	case 2: std::cout << "Введите новый год выпуска фильма:\nВвод -> ";
		std::cin >> A.year;
		break;
	case 3: std::cout << "Введите новый жанр фильма:\nВвод -> ";
		std::cin.ignore();
		std::getline(std::cin, A.genre);
		break;
	case 4: std::cout << "Введите новую продолжительность фильма:\nВвод -> ";
		std::cin >> A.duration;
		break;
	case 5: std::cout << "Введите новую стоимость фильма:\nВвод -> ";
		std::cin >> A.price;
		break;
	default: std::cout << "Неправильной ввод!\n"; break;
	};
};