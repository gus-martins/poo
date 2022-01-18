#include <iostream>

class Tempo {
private:
    int hora;
    int minuto;
    int segundo;

    static void setIntervalo(int& atributo, int value, int limiteInferior, int limiteSuperior) {
        if(value >= 0 && value <= 23)
            atributo = value;
        else
            atributo = 0;
    }

public:
    Tempo(int h, int m, int s){
        this -> setHora(h);
        this -> setMinuto(m);
        this -> setSegundo(s);
    }

    void setHora(int value){
        this -> setIntervalo(this->hora, value, 0, 23);
    }

    void setMinuto(int value){
        this -> setIntervalo(this->hora, value, 0, 59);
    }

    void setSegundo(int value){
        this -> setIntervalo(this->hora, value, 0, 59);
    }

    int getHora() {
        return this -> hora;
    }

    int getMinuto() {
        return this -> minuto;
    }



        friend std::ostream& operator<<(std::ostream& os, Tempo tempo) {
            os << tempo.hora << ":" << tempo.minuto << ":" << tempo.segundo;
            return os;
        }


};

int main() {

    Tempo tempo(11, 25, 3);
    




    std::cout << tempo << std::endl;



}