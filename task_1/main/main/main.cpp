/*
Создать матрицу размерности (n, m) (n и m вводятся с клавиатуры).
Заполнить её случайными числами.
Поменять местами строки, содержащие наибольшее и наименьшее значения  (если наибольших или наименьших значений окажется несколько, брать любую из подходящих строк).
 */

#include <iostream>  // подключение стандартной библы С++
#include <cstdlib>   // подключение библы для функции rand()

#define buffer 100000 // константа для удержания stdout при возникновении зацикливания
#define ERR_MAX 1     // ошибка количества максимальных строк


using namespace std;    // подключения множества имён std::

int main(void)
{
    int num1 = 0, num2 = 0, cache = 0;
    cout << "input number of columns: " << endl; // ввод количества столбцов
    while (!(cin >> num2))                       // проверка на число
    {
        cout << "input error, please input integer: " << endl;  // используется потоковый ввод stdin
        cin.clear();                                            // если вводится не число, то происходит                                                                
        cin.ignore(buffer,'\n');                                // очистка
        fflush(stdin);
    }
    cout << "input number of lines: " << endl;  // ввод количества строк
    while (!(cin >> num1))                      // абсолютно такая же проверка на ввод числа
    {
        cout << "input error, please input integer: " << endl;
        cin.clear();
        cin.ignore(buffer,'\n');
        fflush(stdin);
    }
    
    int arr[num1][num2];  // инициализация матрицы размером num1 x num2
    
    for (int i = 0; i < num1; i++)  // заполнение матрицы случайными числами
    {
        for (int j = 0; j < num2; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
    
    cout << "mas1" << endl;     // объявление о том, что сейчас будет выведена исходная матрица
    
    for (int i = 0; i < num1; i++)
    {
        for (int j = 0; j < num2; j++)
        {
            cout << arr[i][j] << ' '; // вывод значений через пробел
        }
        cout << '\n';                 // переход на новую строку
    }
    
    int cache_2 = 0, cache_1 = 0, i1 = -1, i2 = -1;
    
    for (int i = 0; i < num1; i++)  // цикл нахождения строки с МАКСИМАЛЬНОЙ суммой элементов
    {
        cache = 0;
        for (int j = 0; j < num2; j++)
        {
            cache += arr[i][j];
        }
        if (cache_1 < cache)
            i1 = i;                 // номер первой максимальной
            cache_1 = cache;
    }
    for (int i = 0; i < num1; i++)  // цикл нахождения строки с МАКСИМАЛЬНОЙ суммой элементов
    {
        cache = 0;
        for (int j = 0; j < num2; j++)
        {
            cache += arr[i][j];
        }
        if ((cache_2 < cache) && (i != i1))  // с условием того, что эта строка не совпадает с первой
        {
            cache_2 = cache;
            i2 = i;                   // номер второй максимальной
        }
    }
    
    if (i2 != -1)                      // проверка на то, что вторую максимальную строку удалось найти
    {
        for (int j = 0; j < num2; j++)   // цикл замены строк с максимальной суммой элементов
        {
            cache = arr[i1][j];
            arr[i1][j] = arr[i2][j];
            arr[i2][j] = cache;
        }
    }
    else                // обработка ошибки
    {
        cout << "have one or zero max lines" << endl;
        return ERR_MAX;
    }
    
    cout << "mas2" << endl; // объявление о том, что сейчас будет выведена обработанная матрица
    
    for (int i = 0; i < num1; i++)
    {
        for (int j = 0; j < num2; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    
    cout << "i1: " << i1 << " i2: " << i2 << endl; // номера строк с максимальной суммой элементов
    
    return 0;
}
