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
};

class Li_Ion : public Battery { //класс-наследник "Литий-ионный"
public:
    Li_Ion() { //конструктор по умолчанию
        type = "Li-Ion";
        capacity = 0;
    }
    Li_Ion(int capacity) { //конструктор с параметрами 
        type = "Li-Ion";
        this->capacity = capacity;
    }
    Li_Ion(Li_Ion& i) { //конструктор копирования
        type = i.type;
        capacity = i.capacity;
    }
    ~Li_Ion() { //деструктор
        printf("Литий-ионный аккумулятор утилизирован.\n\n");
    }
};

class Ni_Cd : public Battery { //класс-наследник "Никель-кадмиевый"
public:
    Ni_Cd() { //конструктор по умолчанию
        type = "Ni-Cd";
        capacity = 0;
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
};

class Ni_MH : public Battery { //класс-наследник "Никель-металлогидридный"
public:
    Ni_MH() { //конструктор по умолчанию
        type = "Ni-MH";
        capacity = 0;
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
};

Battery *randomBattery(int choose) { //случайный выбор аккумулятора
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

}