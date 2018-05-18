 /*
 * Создать тип данных для хранения информации о книге: название, автор,
 * издательство, год издания, количество страниц. Написать функции для поиска
 * в массиве «книг» и вывода на экран названий книг по заданному автору,
 * по заданному издательству, по заданному году
 */

#include <iostream>
#include <string>
#include <vector>

struct Book {
	std::string title;
	std::string author;
	std::string publisher;
	int year;
	int pages;
};

void find_books_by_author(std::vector<Book>& books, std::string author) {
	for (int i = 0; i != books.size(); ++i) {
		if (books[i].author == author) {
			std::cout << "Название: " << books[i].title
			          << ", автор: " << books[i].author
			          << ", издательство: " << books[i].publisher
			          << ", год: " << books[i].year
			          << ", кол-во страниц: " << books[i].pages << std::endl;
		}
	}
}

// and so on

int main() {
	std::vector<Book> books = {
		{"Капитанская дочка", "Пушкин", "Современник", 1836, 320},
		{"Пиковая дама", "Пушкин", "Библиотека для чтения", 1834, 40},
		{"Руслан и Людмила", "Пушкин", "Сын отечества", 1820, 140},
		{"Герой нашего времени", "Лермонтов", "Отечественные записки", 1839, 260},
	};

	find_books_by_author(books, "Пушкин");
}
