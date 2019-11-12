/* Егорова Анна Владимировна М8о-207Б-18
Разработать шаблоны классов согласно варианту задания.
Параметром шаблона должен являться скалярный тип данных задающий тип данных для оси координат.
Классы должны иметь публичные поля. Фигуры являются фигурами вращения.
Для хранения координат фигур необходимо использовать шаблон  std::pair.
Создать набор шаблонов, создающих функции, реализующие:
1.       Вычисление геометрического центра фигуры;
2.       Вывод в стандартный поток вывода std::cout координат вершин фигуры;
3.       Вычисление площади фигуры;
Вариант 6:
пятиугольник, шестиугольник, восьмиугольник.
*/

#include "Figures.hpp"


void help() {
    std::cout << "Press pe to show information about pentagon" << std::endl;
    std::cout << "Press h to show information about hexagon" << std::endl;
    std::cout << "Press o to show information about octagon" << std::endl;
    std::cout << "Then enter tuple to use std::tuple<> or class to use class" << std::endl;
}


int main() {
    help();
    using point = std::pair<double, double>;
	using std::make_pair;
    std::cout << std::fixed;
    std::cout.precision(3);
    std::string data, s;
    while(std::cin >> data) {
        if (data == "o") {
            double x1, y1, R;
            std::cout << "Coordinates of center point :" << std::endl;
            std::cin >> x1 >> y1;
            std::cout << "Radius :" << std::endl;
            std::cin >> R;
            if (check(R) == true) {
                std::cout << "tuple or class" << std::endl;
                std::cin >> s;
                if (s == "tuple") {
                    std::tuple<point>  octagon(make_pair(x1, y1));
                    information2(octagon, R);
                } else if (s == "class") {
                    Octagon <double> octagon(x1, y1, R);
                    information2(octagon);
                }
            }
        } else if(data == "h") {
            double x1, y1, R;
            std::cout << "Coordinates of center point :" << std::endl;
            std::cin >> x1 >> y1;
            std::cout << "Radius :" << std::endl;
            std::cin >> R;
            if (check(R) == true) {
                std::cout << "tuple or class" << std::endl;
                std::cin >> s;
                if (s == "tuple") {
                    std::tuple<point>  hexagon(make_pair(x1, y1));
                    information(hexagon, R);
                } else if (s == "class") {
                    Hexagon <double> hexagon(x1, y1, R);
                    information(hexagon);
                }
            }
        } else if (data == "pe") {
            double x1, y1, R;
            std::cout << "Coordinates of center point :" << std::endl;
            std::cin >> x1 >> y1;
            std::cout << "Radius :" << std::endl;
            std::cin >> R;
            if (check(R) == true) {
                std::cout << "tuple or class" << std::endl;
                std::cin >> s;
                if (s == "tuple") {
                    std::tuple<point>  pentagon(make_pair(x1, y1));
                    information3(pentagon, R);
                } else if (s == "class") {
                    Pentagon <double> pentagon(x1, y1, R);
                    information3(pentagon);
                }
            }
        } else if(data == "exit") {
            return 0;
        }
    }
    return 0;
}
