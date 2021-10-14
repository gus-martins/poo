#include <iostream>
#include <vector>
#include <algorithm>
#include "testador.hpp"
#include "testador.hpp"

using namespace std;
vector<int> reverse_with_copy(vector<int> vet) {

    vector<int> vet_reversed(vet.begin(), vet.end());
    reverse(vet_reversed.begin(), vet_reversed.end());
    
    return vet_reversed;

}

vector<int> reverse_inplace(vector<int> vet) {

    reverse(vet.begin(), vet.end());
    
    return vet;

}

int random_value(vector<int> vet) {
    int random = rand() % vet.size() + 1;

    return vet[random];
}

void shuffle_vet(vector<int> vet) {
    random_shuffle(vet.begin(), vet.end());

}

void sort_vet(vector<int> vet){

    sort(vet.begin(), vet.end(), greater <>());

    for(int i =0; i<vet.size(); i++){
        cout << vet[i] << '\n';
    }

}

void reverse_with_copy_test() {
    cout << "reverse_with_copy_test" << endl;
    testar(reverse_with_copy({1, 2, 3}), {3, 2, 1});
    testar(reverse_with_copy({5, 19, -35}), {-35, 19, 5});
}

void reverse_inplace_test() {
    cout << "reverse_inplace_test" << endl;
    testar(reverse_inplace({1, 2, 3}), {3, 2, 1});
    testar(reverse_inplace({5, 19, -35}), {-35, 19, 5});
}

int main() {
vector<int> vet = {1, 4, -74, 67};

reverse_with_copy_test();
reverse_inplace_test();
cout << random_value(vet) << '\n';
shuffle_vet(vet);
cout << vet << '\n';
sort_vet(vet);
cout << vet << '\n';


}