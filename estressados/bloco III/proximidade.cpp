#include <iostream>
#include <vector>
#include <algorithm>
#include "testador.hpp"
#include "testador.hpp"

using namespace std;

int fight(vector<int> vet) {
    int count { 0 };

    for (size_t i = 1; i < vet.size() - 1; i++)
    {
        if (abs(vet[i]) > 50) 
        {
           if (abs(vet[i - 1]) > 30 && abs(vet[i + 1]) > 30)
           {
               count++;
           }     
        }
    }
    return count; 
}

vector<int> apaziguados(vector<int> vet) {
    vector<int> apaziguados {};
    for (size_t i = 0; i < vet.size(); i++)
    {
        if (abs(vet[i]) > 80) 
        {
           if (abs(vet[i - 1]) < 10 || abs(vet[i + 1]) < 10)
           {
               apaziguados.push_back(i);
           }     
        }
    }
    return apaziguados; 
}



void fight_test() {
    cout << "fight_test" << endl;
    testar(fight({50, 98, 31, -51, 31, -99}), 2);
    testar(fight({50, 98, 31, -51, 31, -99, -40}), 3);
}

void apaziguados_test() {
    cout << "apaziguados_test" << endl;
    testar(apaziguados({83, -4, 65, 8, -99, 12 }), {0, 4});
    testar(apaziguados({50, 98, 9, -87, 31, -99, -4}), {1, 3, 5});
}

int main() {
    fight_test();
    apaziguados_test();

}