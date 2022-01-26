#include <iostream>
#include <memory>
#include <vector>
#include <list>

using namespace std;

class Person {
public:
    string name;
    Person(string name) : name(name) {}
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << p.name;
        return os;
    }



};

class Bank {
    vector<shared_ptr<Person>> caixas;   
    list<shared_ptr<Person>> fila_espera;
public:
    Bank (int qtdCaixas) : caixas(qtdCaixas, nullptr) {

    }

    void entrar_fila(const shared_ptr<Person>& person){
        this -> fila_espera.push_back(person);
    }

    bool chamarCaixa(int indice){
        if (indice < 0 || indice >= this -> caixas.size()) {
            cout << "caixa inexistente" << endl;
            return false;
        }
        if (this -> caixas[indice] != nullptr){
            cout << "caixa ocupado" << endl;
            return false;
        }
        if (this -> fila_espera.empty()){
            cout << "sem clientes" << endl;
            return false;
        }
        this ->caixas[indice] = this -> fila_espera.front();
        this -> fila_espera.pop_front();
        return true;
    }

    bool finalizarAtendimento(int indice) {
        if (indice < 0 || indice >= this -> caixas.size()) {
            cout << "caixa inexistente" << endl;
        }
        if (this -> caixas[indice] == nullptr) {
            cout << "caixa vazio" << endl;
        }
        this -> caixas[indice] = nullptr;
        return true;
    }

    friend ostream& operator<<(ostream& os, const Bank& b) {
        os << "Caixas: | ";
        for(int i = 0; i < (int) b.caixas.size(); i++) {
            auto caixa = b.caixas[i];
            os << i << ":";
            if (caixa != nullptr)
                os << *caixa;
            else
                os << "-----";
            os << " | ";
        }

        os<< "\nEspera: ";
        for(auto cliente : b.fila_espera) {
            os << *cliente << " ";
        }
        return os;
    }


};


int main(){
    Bank bank(3);
    bank.entrar_fila(make_shared<Person>("Joao"));
    bank.entrar_fila(make_shared<Person>("Maria"));
    bank.entrar_fila(make_shared<Person>("Pedro"));
    bank.entrar_fila(make_shared<Person>("Jose"));
    bank.entrar_fila(make_shared<Person>("Paulo"));

    bank.chamarCaixa(0);
    bank.chamarCaixa(1);
    bank.chamarCaixa(2);
    bank.chamarCaixa(0);

    bank.finalizarAtendimento(0);
    bank.finalizarAtendimento(1);

    cout << bank << endl;  

}