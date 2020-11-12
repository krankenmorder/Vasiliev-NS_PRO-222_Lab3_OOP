#include <iostream>

using namespace std;

class Battery {
public:
    string name;
    int capacity;
    Battery() {
        name = " ";
        capacity = 0;
    }
    ~Battery() {
        printf("Объект удалён\n\n");
    }
};

class Li_Ion : public Battery {
public:
    Li_Ion() { 
        name = "Li-Ion";
        capacity = 0;
    }
    Li_Ion(int capacity) {
        this->capacity = capacity;
    }
    Li_Ion(Li_Ion& i) {
        capacity = i.capacity;
    }
    ~Li_Ion() {

    }
};

class Ni_Cd : public Battery {
public:
    Ni_Cd() {
        name = "Ni-Cd";
        capacity = 0;
    }
    Ni_Cd(int capacity) {
        this->capacity = capacity;
    }
    Ni_Cd(Ni_Cd &i) {
        capacity = i.capacity;
    }
    ~Ni_Cd() {

    }
};

class Ni_MH : public Battery {
public:
    Ni_MH() {
        name = "Ni-MH";
        capacity = 0;
    }
    Ni_MH(int capacity) {
        this->capacity = capacity;
    }
    Ni_MH(Ni_MH &i) {
        capacity = i.capacity;
    }
    ~Ni_MH() {

    }
};



int main()
{
    std::cout << "Hello World!\n";
}