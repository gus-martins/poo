#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Fone {
    std::string id;
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

    void setId(string id) {
        this->id = id;
    }

    void setNumero(string numero) {
        this->numero = numero;
    }

    string getId() {
        return this->id;
    }

    string getNumero() {
        return this->numero;
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
    Contato(vector<Fone> fone, string nome) : fone{fone}, nome{nome} {}

    void addFone(Fone fone) {
        if (fone.validar(fone.getNumero())) 
            this -> fone.push_back(fone);
        else 
            cout << "Numero invalido" << endl;
        
    }

    void removeFone(int value){
        if (value >= 0 && value < (int) this->fone.size()) 
            this -> fone.erase(this->fone.begin() + value);
        else 
            cout << "erro, indice invalido" << endl;
        
    }

    string getNome() {
        return this -> nome;
    }

    vector<Fone> getFone() {
        return this -> fone;
    }

    void setNome(string nome) {
        this -> nome = nome;
    }

    friend ostream& operator<<(ostream& os, const Contato& c) {
        os << c.nome;

        for (int i = 0; i < (int) c.fone.size(); i++) {
            os << " [" << i << ":" << c.fone[i] << "]";
        }

        os << endl;
        return os;
    }
};

class Agenda {
    vector<Contato> contatos; 

    int encontrarPorNome(std::string nome) {
        for (int i = 0; i < (int) this->contatos.size(); i++) 
            if (this->contatos[i].getNome() == nome)
                return i;
            
        
        return -1;
    }

public:
    Agenda() {}

    void addContato(Contato contato) {
        this -> contatos.push_back(contato);
        sort(this->contatos.begin(), this->contatos.end(), [](Contato c1, Contato c2) {
            if (c1.getNome() != c2.getNome()) 
                return c1.getNome() < c2.getNome();
             });
    }

    Contato* getContato(string nome) {
        int value = encontrarPorNome(nome);
        if (value != -1) {
            return &this->contatos[value];
        }
        return nullptr;
    }


    void removeContato(string nome) {
        int value = encontrarPorNome(nome);
        if (value != -1) 
            this->contatos.erase(this->contatos.begin() + value);
        else 
            cout << "Nao foi possivel remover o contato" << endl;
        
    }

    vector<Contato> procurarContato(string ctt){
        vector<Contato> contato;
        for (auto& c : this -> contatos) {
            stringstream ss;
            ss << c;
            string string = ss.str();
            if (string.find(ctt) != string::npos) {
                contato.push_back(c);
            }
        }
        return contato;
    }

    vector<Contato> getContatos() {
        return this -> contatos;
    }

    friend ostream& operator<<(ostream& os, const Agenda& agenda) {
        for (int i = 0; i < (int) agenda.contatos.size(); i++) {
            os << agenda.contatos[i] << endl;
        }
        return os;
    }
};

int main() {
    Agenda agenda = Agenda();

    Contato cell1 = Contato(vector<Fone>(), "maria");
    cell1.addFone(Fone("celular", "(45) 99874-4876"));
    agenda.addContato(cell1);
     
    vector<Contato> teste = agenda.procurarContato("maria");
    for (auto& c : teste) {
        cout << c;
    }

    cout << endl;

    Contato cell2 = Contato(vector<Fone>(), "joão");
        cell2.addFone(Fone("fixo", "(88) 99347-8754"));
        agenda.addContato(cell2);
        agenda.removeContato("joão");
    cout << agenda << endl;

    return 0;
}