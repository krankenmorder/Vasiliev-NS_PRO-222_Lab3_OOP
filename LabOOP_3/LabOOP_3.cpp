#include <iostream>
#include <list>

using namespace std;

class Battery { //класс-предок "Аккумулятор"
public:
    string type; //атрибут "тип"
    int capacity; //атрибут "ёмкость"
    Battery() { //конструктор по умолчанию (обнуление значений)
        type = "";
        capacity = 0;
    }
    ~Battery() { //деструктор
        printf("Аккумулятор утилизирован.\n\n");
    }
    void randomCapacity() {
        capacity = rand() % 6300;
    }
};

class Li_Ion : public Battery { //класс-наследник "Литий-ионный"
public:
    Li_Ion() { //конструктор по умолчанию
        type = "Li-Ion";
        randomCapacity;
    }
    Li_Ion(int capacity) { //конструктор с параметрами 
        type = "Li-Ion";
        this->capacity = capacity;
    }
    Li_Ion(Li_Ion &i) { //конструктор копирования
        type = i.type;
        capacity = i.capacity;
    }
    ~Li_Ion() { //деструктор
        printf("Литий-ионный аккумулятор утилизирован.\n\n");
    }
    void addCapacityI() {
        capacity += 100;
        printf("Ёмкость литий-ионного аккумулятора увеличена на 100.\n");
    }
    virtual void showParameters() {
        printf("Это %s аккумулятор. Ёмкость = %i.", type,capacity);
    }
};

class Ni_Cd : public Battery { //класс-наследник "Никель-кадмиевый"
public:
    Ni_Cd() { //конструктор по умолчанию
        type = "Ni-Cd";
        randomCapacity;
    }
    Ni_Cd(int capacity) { //конструктор с параметрами
        type = "Ni-Cd";
        this->capacity = capacity;
    }
    Ni_Cd(Ni_Cd &c) { //конструктор копирования
        type = c.type;
        capacity = c.capacity;
    }
    ~Ni_Cd() { //деструктор
        printf("Никель-кадмиевый аккумулятор утилизирован.\n\n");
    }
    void addCapacityC() {
        capacity += 100;
        printf("Ёмкость никель-кадмиевого аккумулятора увеличена на 200.\n");
    }
    virtual void showParameters() {
        printf("Это %s аккумулятор. Ёмкость = %i.", type, capacity);
    }
};

class Ni_MH : public Battery { //класс-наследник "Никель-металлогидридный"
public:
    Ni_MH() { //конструктор по умолчанию
        type = "Ni-MH";
        randomCapacity;
    }
    Ni_MH(int capacity) { //конструктор с параметрами
        type = "Ni-MH";
        this->capacity = capacity;
    }
    Ni_MH(Ni_MH &m) { //конструктор копирования
        type = m.type;
        capacity = m.capacity;
    }
    ~Ni_MH() { //деструктор
        printf("Никель-металлогидридный аккумулятор утилизирован.\n\n");
    }
    void addCapacityM() {
        capacity += 100;
        printf("Ёмкость никель-металлогидридного аккумулятора увеличена на 300.\n");
    }
    virtual void showParameters() {
        printf("Это %s аккумулятор. Ёмкость = %i.", type, capacity);
    }
};

class Storage { //класс-хранилище
public:
    int size; //размер хранилища
    Battery **accumulator;
    Storage() { //конструктор по умолчанию
        
    };
    Storage(int size) { //конструктор с параметрами
        this->size = size;
        accumulator = new Battery *[size];
        for (int i = 0; i < size; i++) { //заполнение массива-хранилища объектов "Аккумулятор" нулевыми показателями
            accumulator[i] = NULL;
        }
    }
    ~Storage() { //деструктор

    }

    void addBattery() { //добавление аккумулятора в хранилище

    }

    void deleteBattery() { //удаление аккумулятора из хранилища

    }

    bool empty(int index) {
        if (accumulator[index] == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 100; //количество действий
    while (n != 100000) {
        int size = n / 3; //при каждом изменении параметра "действий" размер массива остаётся прежним
        Storage storage(size); //создаётся объект класса-хранилища Storage
        for (int i = 0; i < n; i++) {
            int choose = 1 + rand() % 3; //случайный выбор типа аккумулятора
            int number = rand() % size; //случайный выбор элемента массива-хранилища
            printf("%i) ", i); //номер действия
            switch (choose) {
            case 1:
                printf("Создание и добавление в [%i] ячейку хранилища нового аккумулятора...\n", number);

                break;
            case 2:

                break;
            case 3:

                break;
            }
        }

    }
}