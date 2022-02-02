#include <iostream>
#include <vector>
#include <algorithm>
#include "testador.hpp"

using namespace std;

int couples(vector<int> vet) {
    int count_couples { 0 };

    for (size_t i = 0; i < vet.size(); i++)
    {
        for (size_t j = i + 1; j < vet.size(); j++)
        {
            if (abs(vet[i]) == abs(vet[j]) && vet[i] != vet[j])
                count_couples++;
        }
        
    }
    
    return count_couples;

}

int three_people(vector<int> vet) {
    int count { 0 };
    int trio { 0 };

    for (size_t i = 0; i < vet.size(); i++)
    {
        for (size_t j = i + 1; j < vet.size(); j++)
        {
            if (abs(vet[i]) == abs(vet[j]))
                count++;
        }
        
        if (count == 3)
            trio++;
    }
    
    return trio;

}


void couples_test() {
    cout << "couples_test" << endl;
    testar(couples({1, 2, 3, -2, -1, 4, -5, -7, -4}), 3);

}

void three_people_test() {
    cout << "three_people_test" << endl;
    testar(three_people({1, 2, 3, -2, -1, 4, -5, -7, -4, 2, 70, -30, -3, 3}), 2);

}


int main() {

couples_test();
three_people_test();

}