#include <iostream>

using namespace std;

struct Pessoa 
{
    string nome; // atributos
    int idade;

    Pessoa(string nome = "", int idade = 0) // construtor default
    {
        this -> nome = nome;
        this -> idade = idade;
    }
 

    friend ostream& operator<<(ostream& os, const Pessoa& p)
    {
        os << "Nome: " << p.nome << " Idade: " << p.idade;
        return os;
    }
};


struct Motoca 
{
    Pessoa * pessoa; //agregação
    int tempo;
    Motoca():
        pessoa {nullptr}, tempo { 0 } {
    }

    void inserir_pessoa(Pessoa * p) {
        if (this -> pessoa != nullptr) 
        {
            cout << "motoca ocupada" << endl;
            return;
        }
        this -> pessoa = p;
    }

    Pessoa * remover_pessoa() {
        Pessoa * p = this -> pessoa;
        this -> pessoa = nullptr;
        return p;
    }

    void comprar_tempo(int tempo) {
        this -> tempo += tempo;
    }

    bool dirigir(int tempo) {
        if (this -> pessoa == nullptr) 
        {
            cout << "nao tem gente para dirigir" << endl;
            return false; 
        }
        if (tempo > this -> tempo)
        {
            cout << "so conseguiu dirigir " << this -> tempo << " minutos" << endl;
            this -> tempo = 0;
            return false;
        }
        
        cout << "conseguiu dirigir " << this -> tempo << " minutos" << endl;
        this -> tempo -= tempo;
    }

    friend ostream& operator<<(ostream& os, Motoca& m) 
    {
        os << "[" << *m .pessoa << "]"; // * atras do m significa referenciar o objeto e não o endereço
        return os;
    }
};

int main() {

    Pessoa pessoa("Joao", 20);
    Motoca moto;

    moto.inserir_pessoa(&pessoa);

    cout << pessoa << endl;
    cout << moto << endl;

    
    return 0;
}