#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Cliente {
    std::string nome;
    std::string fone;

public:
    Cliente(std::string nome = "", std::string fone = "") : nome{nome}, fone{fone} {}
     
    friend std::ostream& operator<<(std::ostream& os, const Cliente& c) {
        os << c.nome << ":" << c.fone;
        return os;
    }

    void setNome(std::string nome) {
        this -> nome = nome;
    }

    void setFone(std::string fone) {
        this -> fone = fone;
    } 

    std::string getNome() {
        return nome;
    }

    std::string getFone() {
        return fone;
    }
 
};

class Cinema {
    private:
        std::vector<std::shared_ptr<Cliente>> assentos;

    public:
        Cinema(int capacidade ) : assentos(capacidade, nullptr) {}

        friend std::ostream& operator<<(std::ostream& os, const Cinema& c) {
        os << "[ ";

        for (auto assento : c.assentos) {
            if (assento == nullptr) {
                os << "- ";
            } else {
                os << *assento << " ";
            }
        }

        os << "]\n";

        return os;
    }

    int procurarCliente(std::string nome) {
        for (int i = 0; i < (int) assentos.size(); i++)
            if (assentos[i] != nullptr && assentos[i] -> getNome() == nome) 
                return i;
        return -1;
    }

    bool reservar(std::string nome, std::string fone, int indice) {
        if (indice < 0 || indice >= this -> assentos.size()) {
            std::cout << "Assento inexistente" << '\n';
            return false;
        }
        if (assentos[indice] != nullptr) {
            std::cout << "Assento ocupado" << '\n';
            return false;
        }
        if (procurarCliente(nome) != -1) {
            std::cout << "Cliente ja esta no cinema" << '\n';
            return false;
        }   
        if (this -> assentos[indice] == nullptr) {
            this -> assentos[indice] = std::make_shared<Cliente>(nome, fone);
            return true;
        }
    }

    void cancelar(std::string nome){
        int indice = procurarCliente(nome);
        if (indice == -1) {
            std::cout << "Cliente nao encontrado" << '\n';
        }
        else {
            this -> assentos[indice] = nullptr;
        }
    }
};

int main() {
    Cinema cinema(0);

    while (true) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "init") {
            int capacidade;
            std::cin >> capacidade;
            cinema = Cinema(capacidade);
        }
        else if (cmd == "show") {
            std::cout << cinema << '\n';
        }
        else if (cmd == "reservar") {
            std::string nome {};
            std::string fone {};
            int indice;
            std::cin >> nome >> fone >> indice;
            cinema.reservar(nome, fone, indice);
        }
        else if (cmd == "cancelar") {
            std::string nome {};
            std::cin >> nome;
            cinema.cancelar(nome);
        }
        else if (cmd == "end") {
            break;
        } 
        else {
            std::cout << "Comando invalido\n";
        }
    }
    return 0;
}