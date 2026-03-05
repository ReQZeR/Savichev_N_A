#include <iostream>//библиотека ввода вывода
#include <string> //для работы со строками
#include <sstream>//для преобразования строк в числа 
#include <iomanip>//для форматирования вывода 
int a = 0;
int b = 0;
int result = 0;
// функция для ввода 16-ричного числа, принимает строку под сказку возвращает число в 10-тичном виде 
int inputHex(std::string promt) {
    std::string input;
    int number;
    std::cout << promt;
    getline(std::cin, input);
    std::stringstream ss;//создаем поток для преобразования строки в число 
    ss << std::hex << input;//записывам строку в поток hex означает что число в 16-ричной системе
    ss >> number;//преобразуем поток в число 
    return number;
}
//ф-я сложения на ассемблере: принимает 2 числа и возращает их сумму 

int addAsm(int x, int y) {
    int result_asm = 0;
    __asm {
        mov eax, x//загружаем 1 число
        add eax, y//загружаем 2 число 
        add eax,ebx//скидываем в еах
        mov result, eax//сохраняем результат из еах в переменную
        //описываем какие регистры мы используем
    }
    return result_asm;
}
int main()
{
    setlocale(LC_ALL, "Ru");
    std::cout << "============================"<<std::endl;
    std::cout << "Введите числа в HEX (например: 1F,A3,100)" << std::endl;
    a = inputHex("Введите первое число в HEX:");
    b = inputHex("Введите второе число в HEX:");
    result = addAsm(a, b);

    std::cout << "Результат: " << result;
    return 0;
}
