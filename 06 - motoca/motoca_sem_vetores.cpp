#include <iostream>
#include <sstream>

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
    int potencia;
    Motoca(int pot):
        pessoa {nullptr}, tempo { 0 }, potencia {pot} {
    }

    bool inserir_pessoa(Pessoa * p) {
        if (this -> pessoa != nullptr) 
        {
            cout << "motoca ocupada" << endl;
            return false;
        }
        this -> pessoa = p;
        return true;
    }

    Pessoa * remover_pessoa() {
        Pessoa * p = this -> pessoa;
        this -> pessoa = nullptr;
        return p;
    }

    string buzinar() {
        return "p" + string(this -> potencia, 'e') + "m";
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
        os << "T: " << m.tempo << " P: " << m.potencia;
        os << "[" << (m .pessoa == nullptr ? "null" : m.pessoa->nome) << "]";
        return os;
    }
};

int main() {

    Motoca motoca(1);
    while (true)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        
        if (cmd == "end")
        {
            break;
        }else if (cmd == "init")
        {
            int pot = 0;
            ss >> pot;
            motoca = Motoca(pot);
        } else if (cmd == "show") 
        {
            cout << motoca << endl;
        } else if (cmd == "inserir")
        {
            string nome {};
            int idade {};
            ss << nome << idade;
            Pessoa * pessoa = new Pessoa(nome, idade);
            if (!motoca.inserir_pessoa(pessoa))
                delete pessoa;
        }else if (cmd == "retirar") 
        {
            Pessoa * pessoa = motoca.remover_pessoa();
            if (pessoa != nullptr) {
                delete pessoa;
            }
        }else 
            cout << "comando nao existe" << endl;
        
    }
    
}