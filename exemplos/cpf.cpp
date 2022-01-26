#include <iostream>
#include <vector>

using namespace std;



class CPF {
private:
    string number;

    vector<int> filter(string cpf){
         vector<int> numbers;
         for (char c : cpf) {
             if (c != '.' && c != '-')
                numbers.push_back(c - '0'); //convertendo de char para int
         }
         return numbers;
    }

public:
    CPF(string number) {
        this -> number = number;
    }

    void setCPF(string number){
        this -> number = number;
    }

    string getCPF() const {
        return this -> number;
    }

    bool isValid() {
        return CPF::validate(this-> number); 
    }

    //sobrecarga de metodos
    bool validate (string cpf){
        return CPF::validate(CPF::filter(cpf));
    }

    static bool validate(vector<int> vet) {
        int sum = 0;
        
        for(int i = 0; i < 9; i++) 
            sum += vet[i] * (10 - 1);
    
        if (sum % 11 == 0 || sum % 11 == 1) 
        {
            if (vet[9] == 0) 
                return true;
            else    
                return false;
        } 
        else 
        {
            if (vet[9] == (11 - (sum % 11)))
                return true;
            else
                return false;
        }

    }   

};



int main() {

    CPF meucpf("123.456.789-09");
    

}
