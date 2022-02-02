#include <iostream>
#include <vector>
#include <algorithm>
#include "testador.hpp"
#include "testador.hpp"

using namespace std;

vector<int> alone(vector<int> vet) {
    vector<int> vet_alone {};
    int count { 0 };

    for (int i = 0; i < vet.size(); i++) 
    {
        for (int j = 0; j < vet.size(); j++) 
        {
            if (abs(vet[i]) == abs(vet[j]))
                count++;
        }
        if (count == 1)
        {
            vet_alone.push_back(vet[i]);
            count = 0;
        }        
        else 
            count = 0;

    }
    return vet_alone;
}

int more_events(vector<int> vet) {  
    int count { 0 };
    int higher_number_of_occurrences { 0 };

    for (int i = 0; i < vet.size(); i++)
    {
        for (int j = 0; j < vet.size(); j++)
        {
            if (abs(vet[i]) == abs(vet[j]))
                count++;
        }
    if (i == 0) {
        higher_number_of_occurrences = count; 
    } else if (count > higher_number_of_occurrences) {
        
        higher_number_of_occurrences = count;
    }

    count = 0;
    
    }
    return higher_number_of_occurrences;
}

std::vector<int> more_recurrent(const std::vector<int>& vet) {
    int maior_ocorrencia{more_events(vet)};
    std::vector<int> recorrentes;
    
    for (size_t i{0}; i < vet.size(); i++) 
    {
        int elem = (vet[i] < 0) ? -vet[i] : vet[i];
        int occur{1};
        
        for (size_t j{i+1}; j < vet.size(); j++) 
        {
            int elem2 = (vet[j] < 0) ? -vet[j] : vet[j];
            
            if (elem == elem2) 
            {
                occur += 1;
            }
        }
        if (occur == maior_ocorrencia) 
        {
            recorrentes.push_back(elem);
        }
    }
    return recorrentes;
}



void alone_test() {
    cout << "alone_test" << endl;
    testar(alone({1, 3, 4, 3, -1, -3, -3}), {4});
    testar(alone({1, 3, 4, 3, 5, -1, -3, -3}), {4, 5});

}

void more_events_test() {
    cout << "more_events_test" << endl;
    testar(more_events({1, 3, 4, 5, -1, -5, -5}), 3);
    testar(more_events({1, 3, 4, 3, 5, -1, -3, -3}), 4);
}

void more_recurrent_test() {
    cout << "more_recurrent_test" << endl;
    testar(more_recurrent({1, 3, 4, 5, -1, -5, -5, 3, -3}), {3, 5});
}

int main() {

    alone_test();
    more_events_test();
    more_recurrent_test();
}