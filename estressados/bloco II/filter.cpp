#include <iostream>
#include <vector>
#include <algorithm>
#include "testador.hpp"
#include "testador.hpp"

using namespace std;

vector<int> clone(const vector<int>& vet) {
    
    vector<int> vet_clone {};
    copy(vet.begin(), vet.end(), back_inserter(vet_clone));
    
    return vet_clone;
}

vector<int> catch_men(vector<int> vet)
{
    vector<int> vet_men {};
    for (int i = 0; i < vet.size(); i++)
    {
        if (vet[i] > 0)
            vet_men.push_back(vet[i]);
    }

    return vet_men;
}

vector<int> catch_calm(vector<int> vet) {
    vector<int> vet_calm {};

    for (int i = 0; i < vet.size(); i++)
    {
        if (abs(vet[i]) < 10)
            vet_calm.push_back(vet[i]);
    }
    
    return vet_calm;
}

vector<int> catch_women_calm(vector<int> vet) {
    vector<int> vet_women_calm {};

    for (int i = 0; i < vet.size(); i++) {
        if (vet[i] < 0) {
          if (abs(vet[i]) < 10)
            vet_women_calm.push_back(vet[i]);  
        }
    }
    
    return vet_women_calm;
}

void clone_test() {
    cout << "clone_test" << endl;
    testar(clone({1, 2, 3}), {1, 2, 3});
    testar(clone({1, 5, -3}), {1, 5, -3});
}

void catch_men_test() {
     cout << "catch_men_test" << endl;
     testar(catch_men({1, 2, -3}), {1, 2});
     testar(catch_men({1, -2, 10, -3}), {1, 10});
 }

void catch_calm_test() {
     cout << "catch_calm_test" << endl;
     testar(catch_calm({1, -2, -13, 11}), {1, -2});
     testar(catch_calm({1, -7, -9, -10, 80}), {1, -7, -9});
}

void catch_women_calm_test() {
     cout << "catch_women_calm_test" << endl;
     testar(catch_women_calm({1, -2, -4, -13, 11}), {-2, -4});
     testar(catch_women_calm({1, -7, -9, -10, 80}), {-7, -9});
}

int main() {

clone_test();
catch_men_test();
catch_calm_test();
catch_women_calm_test();

}