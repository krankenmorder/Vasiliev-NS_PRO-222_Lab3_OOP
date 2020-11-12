#include <iostream>

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
        printf("Объект удалён\n\n");
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
        printf("Литий-ионный аккумулятор утилизирован.");
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
        printf("Никель-кадмиевый аккумулятор утилизирован.");
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
        printf("Никель-металлогидридный аккумулятор утилизирован.");
    }
};



int main()
{
    std::cout << "Hello World!\n";
}