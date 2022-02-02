#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>

using namespace std;

class Cliente {
    string nome;
    string fone;

public:
    Cliente(string nome = "", string fone = "") : nome{nome}, fone{fone} {}
     
    friend ostream& operator<<(ostream& os, const Cliente& c) {
        os << c.nome << ":" << c.fone;
        return os;
    }

    void setNome(string nome) {
        this -> nome = nome;
    }

    void setFone(string fone) {
        this -> fone = fone;
    } 

    string getNome() {
        return this -> nome;
    }

    string getFone() {
        return this -> fone;
    } 
};

class Cinema {
private:
    map<int, shared_ptr<Cliente>> assentos;
public:
    Cinema(int capacidade = 0) {
        for (int i = 0; i < capacidade; i++) {
            assentos[i] = nullptr;
        }
    }

    int procurarCliente(string nome) {
        for (int i = 0; i < assentos.size(); i++) {
            if (assentos[i] != nullptr && assentos[i]->getNome() == nome) {
                return i;
            }
        }
        return -1;
    }

    bool reservar(string nome, string fone, int indice) {
        if (indice < 0 || indice >= this->assentos.size()) {
            cout << "Assento inexistente" << endl;
            return false;
        }
        if (procurarCliente(nome) != -1) {
            cout << "Cliente ja esta no cinema" << endl;
            return false;
        }
        if (assentos[indice] != nullptr) {
            cout << "Assento ocupado" << endl;
            return false;
        }
        this -> assentos[indice] = make_shared<Cliente>(nome, fone);
        return true;
    }

    void cancelar(string nome) {
        int indice = procurarCliente(nome);
        if (indice == -1) 
            cout << "Cliente nao encontrado" << endl;
        else
            this->assentos[indice] = nullptr;
        
    }

    friend ostream& operator<<(ostream& os, const Cinema& c) {
        os << "[ ";

        for (auto assento : c.assentos){ 
            if (assento.second == nullptr) 
                os << "- ";
            else 
                os << *assento.second << " ";
            
        }

        os << endl;
        return os;
    }
};

int main() {
     Cinema cinema(0);

    while (true) {
        string cmd;
        cin >> cmd;

        if (cmd == "init") {
            int capacidade;
                cin >> capacidade;
                cinema = Cinema(capacidade);
        }

        else if (cmd == "reservar") {
            string nome {};
            string fone {};
            int indice;
                cin >> nome >> fone >> indice;
                cinema.reservar(nome, fone, indice);
        }

        else if (cmd == "cancelar") {
            string nome {};
                cin >> nome;
                cinema.cancelar(nome);
        }

        else if (cmd == "show") {
            cout << cinema << endl;
        }

        else if (cmd == "end") {
            break;
        } 
        else {
            cout << "Comando invalido" << endl;
        }
    }
    return 0;
}