#include <iostream>
#include <time.h>

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
        printf("Аккумулятор утилизирован.\n");
    }
    virtual void showParameters() {
        printf("Неопознанный аккумулятор.\n");
    }
    virtual void addCapacity() {
        printf("Неопознанный аккумулятор.\n");
    }
};

class Li_Ion : public Battery { //класс-наследник "Литий-ионный"
public:
    Li_Ion() { //конструктор по умолчанию
        type = "Li-Ion";
        capacity = rand() % 6300;
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
        printf("Литий-ионный аккумулятор утилизирован.\n");
    }
    virtual void addCapacity() {
        capacity += 100;
        printf("Ёмкость литий-ионного аккумулятора увеличена на 100. Текущая ёмкость - %i.\n", capacity);
    }
    virtual void showParameters() {
        printf("Это литий-ионный аккумулятор. Ёмкость = %i mAh.\n", capacity);
    }
};

class Ni_Cd : public Battery { //класс-наследник "Никель-кадмиевый"
public:
    Ni_Cd() { //конструктор по умолчанию
        type = "Ni-Cd";
        capacity = rand() % 4000;
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
        printf("Никель-кадмиевый аккумулятор утилизирован.\n");
    }
    virtual void addCapacity() {
        capacity += 200;
        printf("Ёмкость никель-кадмиевого аккумулятора увеличена на 200. Текущая ёмкость - %i.\n", capacity);
    }
    virtual void showParameters() {
        printf("Это никель-кадмиевый аккумулятор. Ёмкость = %i mAh.\n", capacity);
    }
};

class Ni_MH : public Battery { //класс-наследник "Никель-металлогидридный"
public:
    Ni_MH() { //конструктор по умолчанию
        type = "Ni-MH";
        capacity = rand() % 5100;
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
        printf("Никель-металлогидридный аккумулятор утилизирован.\n");
    }
    virtual void addCapacity() {
        capacity += 300;
        printf("Ёмкость никель-металлогидридного аккумулятора увеличена на 300. Текущая ёмкость - %i.\n", capacity);
    }
    virtual void showParameters() {
        printf("Это никель-металлогидридный аккумулятор. Ёмкость = %i mAh.\n", capacity);
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

    void addBattery(int index, Battery *battery) { //добавление аккумулятора в хранилище
        accumulator[index] = battery;
    }

    void deleteBattery(int index) { //удаление аккумулятора из хранилища
        delete accumulator[index];
        accumulator[index] = NULL;
    }

    bool Empty(int index) { //проверка наличия аккумулятора в хранилище
        if (accumulator[index] == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    void Parameters(int index) { //вывод атрибутов аккумулятора
        accumulator[index]->showParameters();
    }

    void addCapacity(int index) { //добавление ёмкости
        accumulator[index]->addCapacity();
    }

    int lengthStorage() { //подсчёт длины хранилища
        int length = 0;
        for (int i = 0; i < size; i++) {
            if (!Empty(i)) {
                length++;
            }
        }
        return length;
    }

    void searchBattery() { //метод вывода хранилища на экран
        for (int i = 0; i < size; i++) {
            printf("%i) ", i);
            if (Empty(i)) {
                printf("Пустая ячейка.\n");
            }
            else {
                Parameters(i);
            }
        }
    }
};

Battery *randomBattery(int choose) {
    switch (choose) {
    case 1:
        return new Li_Ion;
        break;
    case 2:
        return new Ni_Cd;
        break;
    case 3:
        return new Ni_MH;
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int n = 100; //количество действий
    while (n != 100000) {
        int size = n / 3; //при каждом изменении параметра "действий" размер массива остаётся прежним
        Storage storage(size); //создаётся объект класса-хранилища Storage
        unsigned int start_time = clock(); //запуск отсчёта времени
        for (int i = 0; i < n; i++) {
            int choose = 1 + rand() % 3; //случайный выбор типа аккумулятора
            int number = rand() % size; //случайный выбор элемента массива-хранилища
            printf("%i) ", i); //номер действия
            switch (choose) {
            case 1:
                printf("Создание и добавление в [%i] ячейку хранилища нового аккумулятора...\n", number);
                if (storage.Empty(number)) {
                    storage.addBattery(number, randomBattery(1 + rand() % 3));
                }
                else {
                    printf("Коллизия. Ячейка %i занята.\n", number);
                }
                break;
            case 2:
                printf("Удаление из [%i] ячейки хранилища старого аккумулятора...\n", number);
                if (!storage.Empty(number)) {
                    storage.deleteBattery(number);
                }
                else {
                    printf("Ячейка %i уже была пуста.\n", number);
                }
                break;
            case 3:
                int variant = 1 + rand() % 2;
                switch (variant) { //раздвоение на методы классов-наследников
                case 1:
                    printf("Проверка параметров у аккумулятора на %i ячейке хранилища.\n", number);
                    if (!storage.Empty(number)) {
                        storage.Parameters(number);
                    }
                    else {
                        printf("Ячейка %i оказалась пуста.\n", number);
                    }
                    break;
                case 2:
                    printf("Увеличение ёмкости аккумулятора на %i ячейке хранилища.\n", number);
                    if (!storage.Empty(number)) {
                        storage.addCapacity(number);
                    }
                    else {
                        printf("Ячейка %i оказалась пуста.\n", number);
                    }
                    break;
                }
                break;
            }
        }
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time; // искомое время
        cout << "\n\nВремя затраченное на данный проход цикла: " << (double)search_time / 1000 << " сек." << endl << endl;
        n *= 10;
        system("pause");
        int question;
    menu:
        printf("\n\nКол-во элементов хранилища: %i.\n", storage.lengthStorage());
        storage.searchBattery();
        system("pause");
        system("cls");
    }
}