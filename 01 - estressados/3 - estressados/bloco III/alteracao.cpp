#include <iostream>
#include <vector>
#include <algorithm>
#include "testador.hpp"

using namespace std;

vector<int> remove(vector<int>& vet, int position) {

    vet.erase(vet.begin() + position);

    return vet;

}

vector<int> insert(vector<int>& vet, int position, int value) {
    
    vet.insert(vet.begin() + position, value);

    return vet;
}

vector<int> dance(vector<int> vet) {

    for (size_t i = 0; i < vet.size() - 1; i++)
    {
        if (abs(vet[i]) == abs(vet[i + 1]))
        {
            vet.erase(vet.begin() + i);
            vet.erase(vet.begin() + (i+1));
        }
        
    }
     for (size_t i = 0; i < vet.size(); i++)
     {
        if (abs(vet[i]) == abs(vet[i + 1])) 
        {
                dance(vet);
        }
     }
        

    return vet;
}




int main () {

    vector<int> vet = {0, 1, 2, 3, 4, 5, 6, 7};

    remove(vet, 2);
    cout << "vetor apos remover\n" << vet << endl;

    insert(vet, 2, 10);
    cout << "vetor apos inserir\n" << vet << endl;

}