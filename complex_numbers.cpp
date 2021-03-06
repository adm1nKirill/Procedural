
#include "complex_numbers.h"

namespace variant9123 {
    // Считывание и вывод комплексных чисел
    numbers *InComplex(std::ifstream &ifstr) {
        bool bad_flag = false;
        complex_numbers *temp = new complex_numbers; // Создаем экземпляр структуры
        if(ifstr.eof()) return nullptr;
        if(ifstr.fail()) bad_flag = true;
        ifstr >> temp->real;
        if(ifstr.eof() || bad_flag) return nullptr;
        ifstr >> temp->imaginary; // Считываем мнимую и действительную часть
        if(ifstr.fail()) bad_flag = true;
        if (!ifstr.eof() && !bad_flag) ifstr.get(); // Переход на новую строку
        else return nullptr;
        return (numbers *) temp; // Перевод указателя под numbers*
    }

    void OutComplex(complex_numbers *complex, std::ofstream &ofstr) {
        ofstr << "[COMPLEX NUMBER = ";
        ofstr << "(" << ToDouble(complex) << ") "; // Вывод числителя
        // Вывод комплексного числа в виде xi + y
        ofstr << complex->imaginary << "i"; // xi
        // Вывод действительного числа со знаком "+"
        if (complex->real >= 0) ofstr << "+" << complex->real << " " << complex->measure << "]" << std::endl;
        else ofstr << complex->real << " " << complex->measure << "]" << std::endl; // Со знаком "-"
    }

    // Приведение каждого значения к действительному числу, эквивалентному записанному.
    // для комплексного числа - по формуле: sqrt(d^2+i^2)).

    double ToDouble(complex_numbers *complex) {
        return sqrt(complex->real*complex->real + complex->imaginary*complex->imaginary);
    }

}