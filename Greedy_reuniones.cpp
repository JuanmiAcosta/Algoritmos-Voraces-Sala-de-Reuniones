#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct reunion
{
    float inicio;
    float fin;
};

bool operator==(const reunion& lhs, const reunion& rhs) {
    return lhs.inicio == rhs.inicio && lhs.fin == rhs.fin;
}

reunion seleccionCorta(const vector<reunion> &c)
{
    reunion corta = c[0];

    for (int i = 0; i < c.size(); i++)
    {
        if ((c[i].fin - c[i].inicio) < (corta.fin - corta.inicio))
        {
            corta = c[i];
        }
    }

    return corta;
}

reunion seleccionAntes(const vector<reunion> &c)
{
    reunion antes = c[0];

    for (int i = 0; i < c.size(); i++)
    {
        if (c[i].inicio < antes.inicio)
        {
            antes = c[i];
        }
    }

    return antes;
}

reunion seleccionAntesFin(const vector<reunion> &c)
{
    reunion antes = c[0];

    for (int i = 0; i < c.size(); i++)
    {
        if (c[i].fin < antes.fin)
        {
            antes = c[i];
        }
    }

    return antes;
}

reunion seleccionMenosSolapa(const vector<reunion> &c){

}

bool esFactible(const reunion &r1, const reunion &r2)
{
    return ((r1.inicio > r2.inicio && r1.inicio > r2.fin) || (r1.inicio<r2.inicio && r1.fin < r2.inicio));
}

bool esFactible(const reunion &r1, const vector<reunion> &r)
{
    bool factible = true;

    if (r.empty())
    {
        return true;
    }

    for (int i = 0; i < r.size() && factible == true; i++)
    {
        if (!esFactible(r1, r[i]))
        {
            factible = false;
        }
    }

    return factible;
}
/*
bool LosQueQuedanSolapan(const vector<reunion> &c, const vector<reunion> &r)
{
    bool solapan = true;

    for (int i = 0; i < c.size() && solapan == true; i++)
    {
        for (int j = 0; j < r.size(); j++)
        {
            if (esFactible(c[i], r[j]))
            {
                solapan = false;
            }
        }
    }

    return solapan;
}
*/
vector<reunion> reunionesGreedy(vector<reunion> c)
{
    vector<reunion> r;

    while ((c.empty() == false) ) 
    {
        reunion escogida = seleccionCorta(c);
        c.erase(std::remove(c.begin(), c.end(), escogida), c.end());
        if (esFactible(escogida, r))
        {
            r.push_back(escogida);
        }
    }

    return r;
}

int main()
{

    vector<reunion> reuniones;

    reunion r1;
    r1.inicio = 8.30;
    r1.fin = 10.30;
    reunion r2;
    r2.inicio = 8.10;
    r2.fin = 13.30;
    reunion r3;
    r3.inicio = 9.30;
    r3.fin = 10.20;
    reunion r4;
    r4.inicio = 10.20;
    r4.fin = 11.30;
    reunion r5;
    r5.inicio = 13.15;
    r5.fin = 15.30;
    reunion r6;
    r6.inicio = 15.20;
    r6.fin = 15.30;
    reunion r7;
    r7.inicio = 11.15;
    r7.fin = 14.30;
    reunion r8;
    r8.inicio = 8.30;
    r8.fin = 12.30;
    reunion r9;
    r9.inicio = 15.00;
    r9.fin = 17.30;
    reunion r10;
    r10.inicio = 17.31;
    r10.fin = 18.30;

    reuniones.push_back(r3);
    reuniones.push_back(r7);
    reuniones.push_back(r1);
    reuniones.push_back(r6);
    reuniones.push_back(r10);
    reuniones.push_back(r1);
    reuniones.push_back(r5);
    reuniones.push_back(r2);
    reuniones.push_back(r8);
    reuniones.push_back(r4);

    cout << "Reuniones nº: " << reuniones.size() << endl;

    vector<reunion> solucion = reunionesGreedy(reuniones);

    for (int i = 0; i < solucion.size(); i++)
    {
        cout << "Hora de inicio: " << solucion[i].inicio << ", Hora de fin: " << solucion[i].fin << std::endl;
    }

    return 0;
}