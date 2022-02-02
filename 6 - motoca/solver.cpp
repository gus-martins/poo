#include <iostream>

using namespace std;

struct Gato {
    string nome {""};
    int vidas { 0 };

    Gato(string nome = "", int vidas = 7) {
        this -> nome = nome;
        this -> vidas = vidas;

        cout << this -> nome << " esta nascendo usando construtor que recebe uma string" << endl; 
    }
};

int main() {
    Gato ariel;
    ariel.nome = "Ariel";
    ariel.vidas = 7;

    cout << ariel.nome << " tem " << ariel.vidas << " vidas" << endl;

    Gato maki {"Maki", 6};
    cout << maki.nome << " tem " << maki.vidas << " vidas" << endl;


    
}