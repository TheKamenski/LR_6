#include <iostream>
#include <cmath>
#include <exception>

using namespace std;

// Класс исключения для квадратного уравнения без действительных корней
class NoRealRootsException : public invalid_argument {
private:
    double a, b, c; // Коэффициенты уравнения, вызвавшего исключение

public:
    // Конструктор исключения
    NoRealRootsException(double a, double b, double c) :
        invalid_argument("Уравнение не имеет действительных корней"), a(a), b(b), c(c) {}

    // Метод для печати данных об исключении
    void printError() const {
        cout << "Ошибка: " << what() << endl;
        cout << "Коэффициенты уравнения: a = " << a << ", b = " << b << ", c = " << c << endl;
    }
};

// Класс "Квадратное уравнение"
class QuadraticEquation {
private:
    double a, b, c; // Коэффициенты уравнения

public:
    // Конструктор с инициализацией коэффициентов
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    // Метод для вычисления дискриминанта
    double discriminant() const {
        return b * b - 4 * a * c;
    }

    // Метод для решения квадратного уравнения
    void solve() const {
        double d = discriminant();
        if (d < 0) {
            // Бросаем исключение, если нет действительных корней
            throw NoRealRootsException(a, b, c);
        } else {
            // Вычисляем и выводим корни уравнения
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);
            cout << "Корни уравнения: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
    }
};

int main() {
    double a, b, c;

    // Запрашиваем коэффициенты уравнения у пользователя
    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
    cin >> a >> b >> c;

    try {
        // Создаем объект "Квадратное уравнение"
        QuadraticEquation eq(a, b, c);
        // Решаем уравнение (может бросить исключение)
        eq.solve();
    } catch (const NoRealRootsException& ex) {
        // Обрабатываем исключение, если оно возникло
        ex.printError();
    }

    return 0;
}

