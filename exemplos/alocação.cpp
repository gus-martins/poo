#include <iostream>

    
int main() {

    int * p {nullptr};
    {
        int * y = new int (5); //o endereço 500 recebe 5 via heap (new)
        p = y;
        std::cout << *p; //valor 5
    }
    std::cout << p; //endereço 500
    std::cout << *p; //indeterminado pois o valor de 5 é destroido no escoo acima

    *p = 8; //no endereço 500 coloque 8
    std::cout << p; //500
    std::cout << *p; //indeterminado

    delete p; //não preciso mais do bloco 500
    p = nullptr; //fazer a variavel esquecer o endereço q ela estava armaznando; 
}