#include <iostream>
#include <vector>
#include <algorithm>
#include "testador.hpp"
#include "testador.hpp"


bool existe(std::vector<int> vet, int x) {

    for (int i = 0; i < vet.size(); i++) 
        if(vet[i] == x)
            return true;
    return false;
    

}

int contar(std::vector<int> vet, int x) {
    int cont { 0 };

    for (int i = 0; i < vet.size(); i++) 
        if (vet[i] == x)
            cont++;
    
    return cont;


}

int procurar_valor(const std::vector<int> vet, int x) {
    int atual = { -1 };
    for (int i = 0; i < (int) vet.size(); i++) 
        if(vet[i] == x) 
                return i;
    
    return atual;
    
}

int procurar_valor_apartir(std::vector<int> vet, int value, int inicial_position) {
    for (int i = inicial_position; i < (int) vet.size(); i++) 
        if(vet[i] == value) 
            return i;        
    return -1;
}

int procurar_menor(std::vector<int> vet) {
    int value = vet[0];
    for (int i = 0; i < (int) vet.size(); i++) 
        if (vet[i] < value) 
            value = vet[i];
        
    return value;
}

int procurar_menor_pos(std::vector<int> vet) {
    int value = vet[0];
    int position { 0 };
    for (int i = 0; i < (int) vet.size(); i++) 
        if (vet[i] < value) {
            value = vet[i];
            position = i;
        }
    return position;
}

int procurar_menor_pos_apartir(std::vector<int> vet, int inicial_position) {
    int value = vet[0];
    int position { 0 };
    for (int i = inicial_position; i < (int) vet.size(); i++) 
        if (vet[i] < value) {
            value = vet[i];
            position = i;
        }
    return position;
}

int procurar_melhor_pos_se(std::vector<int> vet) {
    int value = vet[0];
    int position { 0 };
    for (int i = 0; i < (int) vet.size(); i++) 
        if (vet[i] > 0) {
            if (vet[i] < value) {
            value = vet[i];
            position = i;
            return position;
            } 
        } if (vet[vet.size() - 1] < 0)
            return -1;
    
}

float calcular_stress_medio(std::vector<int> vet) {
    float result { 0 }, soma { 0 };
    for (int i = 0; i < vet.size(); i++) 
            soma += std::abs(vet[i]);
    
    result = soma / vet.size();
    return result;

}

std::string mais_homens_ou_mulheres(std::vector<int> vet) {
    int homens { 0 }, mulheres { 0 };

    for (int i = 0; i < vet.size(); i++) {
        if (vet[i] > 0)
            homens++;
        else
            mulheres++;
    }   
    if (homens == mulheres)
        return "empate";
    return mulheres > homens ? "mulheres" : "homens";

}

std::string qual_metade_eh_mais_stressada(const std::vector<int>& vet) {
    int soma_primeira { 0 }, soma_segunda { 0 };
    
    for (int i = 0; i < (int) vet.size() / 2; i++)
        soma_primeira += std::abs(vet[i]);
    
    int inicio = (int) vet.size() / 2;
        
        if(vet.size() % 2 == 1)
            inicio += 1;
    for (int i = inicio; i < (int) vet.size(); i++)
        soma_segunda += std::abs(vet[i]);
    if(soma_primeira == soma_segunda)
            return "empate";
    return soma_primeira > soma_segunda ? "primeira" : "segunda";
}

std::string homens_sao_mais_estressados_que_mulheres(std::vector<int> vet) {
    int quantidade_homens { 0 }, quantidade_mulheres { 0 };
    float soma_homens { 0 }, soma_mulheres { 0 };
    float media_homens { 0 }, media_mulheres { 0 };

    for (int i = 0; i < vet.size(); i++) {
        if (vet[i] > 0){
            quantidade_homens++;
            soma_homens += vet[i];
        }
        else {
            quantidade_mulheres++;
            soma_mulheres += std::abs(vet[i]);
        }    
    }

    media_homens = soma_homens / quantidade_homens;
    media_mulheres = soma_mulheres / quantidade_mulheres;

    if (media_homens == media_mulheres)
        return "empate";
    return media_mulheres > media_homens ? "mulheres" : "homens";

}




void existe_teste() {
    std::cout << "existe_teste\n";
    testar(existe({-1, -50, -99}, -1), true);
    testar(existe({-1, -50, -99}, 10), false);

}

void contar_teste() {
    std::cout << "contar_teste\n";
    testar(contar({-1, -50, -1, -99}, -1), 2);
    testar(contar({-1, -50, -1, -99}, 10), 0);
}
void procurar_valor_teste() {
    std::cout << "procurar_valor_teste\n";
    testar(procurar_valor({1, 2, 3}, 1), 0);
    testar(procurar_valor({1, 2, 3}, 4), -1);

}

void procurar_valor_apartir_teste() {
    std::cout << "procurar_valor_apartir_teste\n";
    testar(procurar_valor_apartir({5, 3, -1, -50, -1, -99}, -1, 0), 2);
    testar(procurar_valor_apartir({5, 3, -1, -50, -1, -99}, -1, 3), 4);
    testar(procurar_valor_apartir({5, 3, -1, -50, -1, -99}, -1, 4), 4);
}

void procurar_menor_teste() {
    std::cout << "procura_menor_teste\n";
    testar(procurar_menor({5, 3, 1, 50, 1, 99}), 1);

}

void procurar_menor_pos_teste() {
    std::cout << "procura_menor_pos_teste\n";
    testar(procurar_menor_pos({5, 3, -1, -50, -1, -99}), 5);

}

void procurar_menor_pos_apartir_teste() {
    std::cout << "procura_menor_pos_apartir_teste\n";
    testar(procurar_menor_pos_apartir({5, 3, -1, -50, -1, 10}, 3), 3);

}

void procurar_melhor_pos_se_teste() {
    std::cout << "procurar_melhor_pos_se_teste\n";
    testar(procurar_melhor_pos_se({5, -1, -1, -50, 1, -99}), 4);
    testar(procurar_melhor_pos_se({-1, -50, -1, -99}), -1);

}

void mais_homens_ou_mulheres_teste() {
    std::cout << "mais_homens_ou_mulheres_teste\n";
    testar(mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99}), std::string("mulheres"));
    testar(mais_homens_ou_mulheres({5, 3, 1, -50, -1, -99}), std::string("empate"));
    testar(mais_homens_ou_mulheres({5, 3, 1, -50, -1, 99}), std::string("homens"));


}

void qual_metade_eh_mais_stressada_teste() {
    std::cout << "qual_metade_eh_mais_stressada_teste\n";
    testar(qual_metade_eh_mais_stressada({5, 3, -1, -50, -1, -99}), std::string("segunda"));
    testar(qual_metade_eh_mais_stressada({50, 98, 2, -50, -1, -99}), std::string("empate"));
    testar(qual_metade_eh_mais_stressada({-51, 99, 1, -50, -1, -99}), std::string("primeira"));

}

int main () {
    
existe_teste();    
contar_teste();
procurar_valor_teste();
procurar_valor_apartir_teste();

procurar_menor_teste();
procurar_menor_pos_teste();
procurar_menor_pos_apartir_teste();
procurar_melhor_pos_se_teste();

std::vector<int> vet = {-2, 2, 4, -8}; 

std::cout << calcular_stress_medio(vet) << "\n";
mais_homens_ou_mulheres_teste();
qual_metade_eh_mais_stressada_teste();
std::cout << homens_sao_mais_estressados_que_mulheres(vet);





}
