#include <iostream>
#include <vector>
#include <algorithm>
#include "testador.hpp"
using namespace std;

int how_many_teams(vector<int> vet) {
    int teams { 0 };
    int count { 0 };

    for (size_t i = 0; i < vet.size(); i++)
    {
        if (vet[i] > 0 && vet[i + 1] > 0 || vet[i] < 0 && vet[i + 1] < 0)
        {
            count++;
        } else if (count > 0)
        {
            teams++;
            count = 0;   
        }
        
        if (i == vet.size() - 2 && count > 0)
            teams++;

        
    }
    
    return teams;

}

int biggest_team(vector<int> vet) {
    int countMan{0};
    int countWomen{0};

    int bigMan{2};
    int bigWomen{2};

    for (int i = 0; i < (int)vet.size(); i++ ) 
    {
        if (vet[i] > 0) 
        {
            countMan++;
            if (countMan > bigMan)
                bigMan = countMan;
            countWomen = 0;
        }
        else 
        {
            countWomen++;
            if ( countWomen > bigWomen )
            {            
                bigWomen = countWomen;
            }
            countMan = 0;
        }
    }

    if (bigMan > bigWomen )
        return bigMan;
    else 
        return bigWomen;    
}

int without_team(vector<int> vet) {
    int without_team { 0 };

    for (size_t i = 0; i < vet.size(); i++) 
    {
        if (i == 0)
        {
            if (vet[i] > 0 && vet[i + 1] < 0 || vet[i] < 0 && vet[i + 1] > 0)
                without_team++;
        } else if (i == vet.size() - 1)
        {
            if (vet[i] > 0 && vet[i - 1] < 0 || vet[i] < 0 && vet[i - 1] > 0)
                without_team++;
        } else if (vet[i] > 0 && vet[i + 1] < 0 && vet[i] > 0 && vet[i - 1] < 0 || vet[i] < 0 && vet[i + 1] > 0 && vet[i] < 0 && vet[i - 1] > 0)
            without_team++;
    }

    return without_team;
}


void how_many_teams_test() {
    cout << "how_many_teams_test" << endl;
    testar(how_many_teams({5, 3, 1, -11, 1, 99, -11, -1, -2, 44}), 3);
    testar(how_many_teams({1, 1, 1, -1, 1, -1, -1}), 2);
    
}

void without_team_test() {
    cout << "without_team_test" << endl;
    testar(without_team({-5, 3, 1, -15, -1, 99, -11, -1, -7}), 2);
    testar(without_team({-5, -3, -1, -15, -1, -99, -11, -1, -7}), 0);
    testar(without_team({-5, 3, 1, 15, -1, -99, -11, -1, -7}), 1);
}

int main() {

how_many_teams_test();
without_team_test();

}