#include <iostream>
#include <vector>
#include <algorithm>
#include "testador.hpp"
#include "testador.hpp"

using namespace std;

vector<int> exclusive(const vector<int> vet) {
    vector<int> vet_exclusive;
    int count { 0 };

    for (int i = 0; i < vet.size(); i++) {
        for (int j = i + 1; j < vet.size(); j++) {
            if (vet[i] == vet[j]) 
                count++;
        }
        
        if (count == 0)
            vet_exclusive.push_back(vet[i]);
        else   
            count = 0;
    }
    
    return vet_exclusive;
}

vector<int> different(const vector<int> vet) {
    vector<int> vet_different;
    int count { 0 };

    for (int i = 0; i < vet.size(); i++) {
        for (int j = i + 1; j < vet.size(); j++) {
            if (abs(vet[i]) == abs(vet[j]))
                count++;
        }
        
        if (count == 0)
            vet_different.push_back(abs(vet[i]));
        else   
            count = 0;
    }
    
    return vet_different;
}

vector<int> abandoned(vector<int> vet) {
    vector<int> vet_abandoned;
    

    for (int i = 0; i < vet.size(); i++) {
        for (int j = i + 1; j < vet.size(); j++) {
            if (vet[i] == vet[j])
                vet_abandoned.push_back(vet[i]);
        }
        
    }
    
    return vet_abandoned;

}



void exclusive_test() {
    cout << "exclusive_test" << endl;
    testar(exclusive({1, 1, 2, 2, 3, -5, -6, -6}), {1, 2, 3, -5, -6});
}

void different_test() {
    cout << "different_test" << endl;
    testar(different({1, 1, 2, 2, 3, -5, -6, -6}), {1, 2, 3, 5, 6});
}

void abandoned_test() {
    cout << "abandoned_test" << endl;
    testar(abandoned({1, 1, 2, 2, 3, -5, -6, -6}), {1, 2, -6});
}

int main() {

exclusive_test();
different_test();
abandoned_test();

}