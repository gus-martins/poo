#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>


using namespace std;

class Fone {
    string id;
    string numero;

public:
    Fone(string id, string numero) : id{id}, numero{numero} {}

    bool validar(string numero) {
        for (int i = 0; i < (int) numero.size(); i++) 
            if (numero[i] >= '0' || numero[i] <= '9' || numero[i] == '.' || numero[i] == '(' || numero[i] == ')') 
                return true;
            
        
        return false;
    }


    string getNumero() {
        return this -> numero;
    }

    string getId() {
        return this -> id;
    }

    void setNumero(string numero) {
        this -> numero = numero;
    }

    void setId(string id) {
        this -> id = id;
    }
    
    friend ostream& operator<<(ostream& os, const Fone& f) {
        os << f.id << ":" << f.numero;
        return os;
    }
};

class Contato {
    string nome;
    vector<Fone> fone;

public:
    Contato(){}
    
    Contato(vector<Fone> fone, string nome) : fone{fone}, nome{nome} {}

    void addFone(Fone fone) {
        if (fone.validar(fone.getNumero())) 
            this -> fone.push_back(fone);
        else
            cout << "Numero invalido" << '\n';
        
    }

    void rmFone(int indice){
        if (indice >= 0 && indice < (int) this->fone.size()) 
            this->fone.erase(this->fone.begin() + indice);
        else
            cout << "erro, indice invalido" << endl;
        
    }

    string getNome() {
        return this->nome;
    }

    vector<Fone> getFones() {
        return this->fone;
    }

    void setNome(string nome) {
        this->nome = nome;
    }

    friend ostream& operator<<(ostream& os, const Contato& contato) {
        os << contato.nome;

        for (int i = 0; i < (int) contato.fone.size(); i++) {
            os << " [" << i << ":" << contato.fone[i] << "]";
        }

        os << endl;
        return os;
    }
};

class Agenda {
    map<string, Contato> contatos;

public:
    Agenda() {}

    void addContato(Contato contato) {
        auto it = this -> contatos.find(contato.getNome());
        if (it == this -> contatos.end()) 
            this -> contatos[contato.getNome()] = contato;
        else 
            for (Fone fone : contato.getFones()) 
                it -> second.addFone(fone);
            
        
    }

    Contato* getContato(string nome) {
        auto it = this -> contatos.find(nome);
            if (it != this->contatos.end()) 
                return &it -> second;
        
            return nullptr;
    }

    void removeContato(string nome) {
        auto it = this -> contatos.find(nome);
        if (it != this -> contatos.end()) 
            this -> contatos.erase(it);
        else 
            cout << "Contato inexistente" << endl;
        
    }

    vector<Contato> procurarContato(string value) {
        vector<Contato> resultado;
        for (auto contato : this->contatos) {
            if (contato.first.find(value) != string::npos) {
                resultado.push_back(contato.second);
            }
        }
        return resultado;
    }

    map<string, Contato> getContatos() {
        return this->contatos;
    }

    friend ostream& operator<<(ostream& os,const Agenda& a) {
        for (auto contato : a.contatos) {
            os << contato.second << endl;
        }
        return os;
    }
};

int main() {
    Agenda agenda = Agenda();
    
    Contato ctt1 = Contato(vector<Fone>(), "Joao");
    Contato ctt2 = Contato(vector<Fone>(), "Maria");

    ctt1.addFone(Fone("cell", "(95) 98765-4321"));
    agenda.addContato(ctt1);

    
    ctt2.addFone(Fone("cell", "(11) 99254-5578"));
    agenda.addContato(ctt2);
    agenda.removeContato("Maria");

    cout << agenda << endl;
}