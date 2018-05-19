/*
 * Создать тип данных для хранения числового массива. Перегрузить
 * операторы «>», «<», «==» и «!=» для сравнения сумм элементов массивов.
 */

#include <iostream>
#include <vector>

typedef std::vector<int> ArrayInt;

int sum(ArrayInt& a) {
	int res = 0;
	for (int i = 0; i != a.size(); ++i) {
		res += a[i];
	}
	return res;
}

bool operator==(ArrayInt& a, ArrayInt& b) {
	return sum(a) == sum(b);
}

bool operator!=(ArrayInt& a, ArrayInt& b) {
	return !(a == b);
}

bool operator<(ArrayInt& a, ArrayInt& b) {
	return sum(a) < sum(b);
}

bool operator>(ArrayInt& a, ArrayInt& b) {
	return sum(a) > sum(b);
}

int main() {
	ArrayInt a = {0};
	ArrayInt b = {-1, 1};
	ArrayInt c = {1, 2, 3};

	std::cout << (a == b) << ' ' << (a != b) << ' ' << (a < c) << ' ' << (a > c) << '\n';
}
