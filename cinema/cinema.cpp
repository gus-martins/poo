#include <iostream>
#include <vector>
#include <memory>
#include <optional>


using namespace std;

class Cliente{
    private:
        string nome;
        string fone;
    public:
        Cliente(string nome = "", string fone = "") : nome{nome}, fone{fone} {}
        friend ostream& operator<<(ostream& os, const Cliente& c) {
            os << c.nome << ":" << c.fone;
            return os;
        }
    
        string getNome() {
            return this -> nome;
        }
};

class Sala{
    private:
        vector<shared_ptr<Cliente>> cliente;
    public:
        Sala(int quantidade = 0) : cliente(quantidade, nullptr) {
        }

        bool reservar(shared_ptr<Cliente> pessoa, int position) {
            if(position < 0 or position >= (int) cliente.size()) {
                cout << "cadeira nao existe" << endl;
                return true;
            }
            for(int i = 0;  i < (int) cliente.size(); i++) {
                if(cliente[i] == nullptr)
                    continue;
                if(cliente[i] -> getNome() == pessoa -> getNome()) {
                    cout<<"cliente ja cadastrado com este nome"<<endl;
                    return true;
                }
            }
            if(cliente[position] != nullptr) 
                return false;

            cliente[position] = pessoa;
            return true;
        }

    void cancelar(string nome) {
       
        for(int i = 0;  i < (int) cliente.size(); i++) {
            if(cliente[i] == nullptr)
                continue;
            if(cliente[i] -> getNome() == nome) {
                cliente[i] = nullptr;
                return;
            }
        }
            cout << "nao existe cliente com esse nome" << endl;
    }

    friend ostream& operator<<(std::ostream& os, const Sala& s) {
        os<<"[";
        for (auto perspeson : s.cliente) {
            if(person==nullptr)
                os<<" -";
            else
                os << " " << *person;
        }
            os<<" ]";
            return os;
        }
};

int main () {

    string cmd{};
    Sala cinema;

    while (cmd! = "end") {
        cout << "$";
        cin >> cmd;

        if (cmd == "init") {
            int valor;
            
            cin >> valor;
            
            Sala temp(valor);
            
            cinema = temp;
        }

        else if (cmd == "show") {
            cout << cinema << endl;
        }

        else if (cmd == "reservar") {
            string name;
            string fone;
            int position;
            
            cin >> name >> fone >> position;
            
            bool verificarReserva = cinema.reservar(make_shared<Cliente>(name, fone), position);
            if(!verificarReserva) {
                cout << "lugar ja esta reservado" << endl;
            }
        }

        else if (cmd == "cancelar") {
            string name;
            
            cin >> name;
            cinema.cancelar(name);
        }
    }
}