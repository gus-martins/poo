#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Fone {
    string id;
    string numero;

public:
    Fone(string id, string numero) : id{id}, numero{numero} {}

    bool validar(string numero) {
        for (int i = 0; i < (int) numero.size(); i++) {
            if (numero[i] >= '0' || numero[i] <= '9' || numero[i] == '.' || numero[i] == '(' || numero[i] == ')') {
                return true;
            }
        }
        return false;
    }
    
    string getId() {
        return this -> id;
    }

    string getNumero() {
        return this -> numero;
    }

    void setId(string id) {
        this -> id = id;
    }

    void setNumero(string numero) {
        this->numero = numero;
    }

    friend ostream &operator<<(ostream& os, const Fone& f) {
        os << f.id << ":" << f.numero;
        return os;
    } 
};

class Contato {
    string nome;
    vector<Fone> fone;

public:
    Contato(string nome, vector<Fone> fones) : nome{nome}, fone{fone} {}

    void addFone(Fone fone) {
        if (fone.validar(fone.getNumero())) 
            this -> fone.push_back(fone);
         
         else 
            cout << "Numero invalido" << '\n';
        
    }

    void removeFone(int indice){
        if (indice >= 0 && indice < (int) this -> fone.size())
            this -> fone.erase(this -> fone.begin() + indice);
        else 
            cout << "erro ao tentar remover numero" << '\n';
        
    }

    string getNome() {
        return nome;
    }

    vector<Fone> getFone() {
        return fone;
    }

    void setNome(string nome) {
        this -> nome = nome;
    }

    friend ostream &operator<<(ostream& os, const Contato& c) {
        os << c.nome;

        for (int i = 0; i < (int) c.fone.size(); i++) {
            os << " [" << i << ":" << c.fone[i] << "]";
        }

        os << '\n';
        return os;
    }
};

int main() {
    Contato contato("", {});

    while (true) {
        string line;
        string cmd;
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;

        if (cmd == "init") {
            string nome {};
            ss >> nome;
            contato.setNome(nome);
        }
        else if (cmd == "show") {
            cout << contato;
        }
        else if (cmd == "add") {
            string id {};
            string numero {};
            ss >> id >> numero;
            contato.addFone(Fone(id, numero));
        }
        else if (cmd == "remove") {
            int indice {};
            ss >> indice;
            contato.removeFone(indice);
        }
        else if (cmd == "end") {
            break;
        }
        else {
            cout << "Comando invalido" << '\n';
        }
    }
}