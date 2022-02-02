#include <iostream>
#include <string>

using namespace std;

struct Grafite
{

    float calibre{0.0};
    string dureza{"HB"};
    int tamanho{0};

    Grafite(float calibre = 0, string dureza = "", int tamanho = 0) : calibre{calibre}, dureza{dureza}, tamanho{tamanho}
    {
    }

    string toString()
    {
        string object = "Calibre: " + to_string(calibre) + "\n" + "Dureza: " + dureza + "\n" + "Tamanho: " + to_string(tamanho) + "\n";
        cout << object << '\n';
        return object;
    }
};

struct Lapiseira
{
    float calibre{0.0};
    Grafite grafite{0.0, "", 0};

    Lapiseira(float calibre) : calibre{calibre}
    {
    }

    bool inserir_grafite(Grafite g)
    {
        if (grafite.calibre != 0.0)
        {
            cout << "Lapiseira ja tem grafite" << '\n';
            return false;
        }

        if (calibre != g.calibre)
        {
            cout << "Calibre incompativel" << '\n';
            return false;
        }
        grafite = g;
        return true;
    }

    void remover()
    {
        grafite = Grafite{0.0, "", 0};
    }

    void write(int folhas)
    {

        if (grafite.tamanho == 0)
        {
            cout << "Não ha grafite" << '\n';
        }

        if (grafite.dureza == "HB")
        {
            int contador = 0;
            while (folhas != 0)
            {

                folhas--;
                contador++;
                grafite.tamanho -= 1;
                if (grafite.tamanho <= 0)
                {
                    cout << "O grafite acabou" << '\n';
                    remover();

                    break;
                }
            }

            cout << "Foram possiveis escrever " + to_string(contador) + " folhas" << '\n';
        }

        if (grafite.dureza == "2B")
        {
            int contador = 0;
            while (folhas != 0)
            {

                folhas--;
                contador++;
                grafite.tamanho -= 2;
                if (grafite.tamanho <= 0)
                {
                    cout << "O grafite acabou" << '\n';
                    remover();

                    break;
                }
            }
            cout << "Foram possiveis escrever " + to_string(contador) + " folhas" << '\n';
        }

        if (grafite.dureza == "4B")
        {
            int contador = 0;
            while (folhas != 0)
            {

                folhas--;
                contador++;
                grafite.tamanho -= 4;
                if (grafite.tamanho <= 0)
                {
                    cout << "O grafite acabou" << '\n';
                    remover();

                    break;
                }
            }
            cout << "Foram possiveis escrever " + to_string(contador) + " folhas" << '\n';
        }

        if (grafite.dureza == "6B")
        {
            int contador = 0;
            while (folhas != 0)
            {

                folhas--;
                contador++;
                grafite.tamanho -= 6;
                if (grafite.tamanho <= 0)
                {
                    cout << "O grafite acabou" << '\n';
                    remover();
                    break;
                }
            }
            cout << "Foram possiveis escrever " + to_string(contador) + " folhas" << '\n';
        }
    }

    string toString()
    {
        string object = "Calibre: " + to_string(calibre) + "\n\n" + "Grafite: " + "\n" + grafite.toString();
        cout << object << '\n';
        return object;
    }
};

int main()
{

    Grafite a{1.7, "HB", 3};
    Lapiseira p{1.7};
    p.inserir_grafite(a);
    p.write(7);
}
