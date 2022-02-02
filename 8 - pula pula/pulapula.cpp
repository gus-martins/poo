#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <memory>
#include <sstream>

class Kid {
    std::string nome;
    int idade;

public:
    Kid(std::string nome = "", int age = 0) : nome{nome}, idade{idade} {}

    friend std::ostream& operator<<(std::ostream& os, const Kid& k) {
        os << k.nome << ":" << k.idade;
        return os;
    }

    std::string getNome() {
        return nome;
    }

    int getIdade() {
        return idade;
    }

    void setNome(std::string nome) {
        this -> nome = nome;
    }

    void setIdade(int idade) {
        this -> idade = idade;
    }
};

class PulaPula {
    std::list<std::shared_ptr<Kid>> brincando;
    std::list<std::shared_ptr<Kid>> esperando;

public:
    PulaPula(int lugarFila) : brincando(lugarFila, nullptr), esperando() {}  

    friend std::ostream& operator<<(std::ostream& os, const PulaPula& t) {
        os << "=> ";

        for (auto kid : t.esperando) 
        {
            if (kid != nullptr) 
            {
                os << *kid << " ";
            }
        }

        os << "=> [ ";

        for (auto kid : t.brincando) 
        {
            if (kid != nullptr) 
            {
                os << *kid << " ";
            }
        }

        os << "]\n";
        return os;
    }

    void arrive(std::shared_ptr<Kid> kid) {
        this -> esperando.push_back(kid);
    }

   void in() {
       if ( this -> esperando.empty()) 
       {
           std::cout << "Nao ha ninguem na fila\n";
       }
       else 
       {
           this -> esperando.push_back( this -> esperando.front());
           this -> esperando.pop_front();
       }
   }

   void out() {
       if ( this -> brincando.empty()) 
       {
           std::cout << "Nao ha ninguem no trampolim\n";
       }
       else 
       {
           this -> esperando.push_back( this -> brincando.front());
           this -> brincando.pop_front();
       }
    }

    std::shared_ptr<Kid> removerKid(std::string nome) {
        for (auto atual = brincando.begin(); atual != brincando.end(); atual++) 
        {
            if (atual -> get() -> getNome() == nome) 
            {
                return *brincando.erase(atual);
            }
        }

        for (auto atual = esperando.begin(); atual != esperando.end(); atual++) 
        {
            if (atual -> get() -> getNome() == nome) 
            {
                return *esperando.erase(atual);
            }
        }
        return nullptr;
    }
};

int main() {
    PulaPula trampolim(0);

    while (true) 
    {
    std::string cmd;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    ss >> cmd;
        
        if (cmd == "arrive") 
        {
            std::string nome {};
            int idade {};
            ss >> nome >> idade;
            trampolim.arrive(std::make_shared<Kid>(nome, idade));
        }
        else if (cmd == "show") 
        {
            std::cout << trampolim << '\n';
        }
        else if (cmd == "in") 
        {
            trampolim.in();
        }
        else if (cmd == "out") 
        {
            trampolim.out();
        }
        else if (cmd == "remove") 
        {
            std::string nome {};
            ss >> nome;
            trampolim.removerKid(nome);
            std::cout << nome << '\n';
        }
        else if (cmd == "end") 
        {
            break;
        }
        else {
            std::cout << "Comando não existe\n";
        }
    }
}