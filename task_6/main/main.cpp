/*
 * Создать класс для хранения двумерной матрицы. Класс должен содержать методы
 * для создания матрицы заданных размерностей, для заполнения матрицы
 * случайными числами из заданного диапазона, для вывода матрицы на экран.
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Matrix {
public:
	Matrix(int height, int width) : height(height), width(width) {
		if (height <= 0 || width <= 0) {
			throw -1; // лучше кинуть ошибку информативнее
		}
		_m.reserve(height);
		for (int i = 0; i < height; ++i) {
			_m.push_back(std::vector<int>(width));
		}
	}

	fill_random(int a, int b) {
		if (a >= b || b > RAND_MAX) {
			throw -2;
		}
		srand(time(0));
		for (int i = 0; i != height; ++i) {
			for (int j = 0; j != width; ++j) {
				_m[i][j] = a + rand() % (b - a + 1);
			}
		}
	}

	void print() {
		for (int i = 0; i != height; ++i) {
			for (int j = 0; j != width; ++j) {
				printf("%6d", _m[i][j]);
			}
			printf("\n");
		}
	}

	int height;
	int width;


private:
	std::vector<std::vector<int>> _m;
};

int main() {
	Matrix matrix(4, 5);
	matrix.fill_random(-10, 10);
	matrix.print();
}
