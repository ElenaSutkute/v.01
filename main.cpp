#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <random>
using namespace std;

struct Duomenys
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    double vid, med;
}; // sito kabliataskio cj nereikia

double vidurkis(vector<int> vektorius);
double mediana(vector<int> vektorius);

int main()
{
  Duomenys g[20];
  string atsakymas;
  int n;
  int zmones;
  int pazimys;
  int kiek;
  string kuris;
  random_device rd;
  mt19937 generator(rd());
  int min = 5;
  int max = 10;
  cout << "Iveskite zmoniu skaiciu: ";
  cin >> zmones;
  cout << "Pagal mediana ar vidurki? " << endl;
  cin >> kuris;

    for(int i = 0; i < zmones; i++)
    {
        cout << "Iveskite varda: ";
        cin >> g[i].vardas;
        cout << "Iveskite pavarde: ";
        cin >> g[i].pavarde;
        cout << "Ar norite ivesti savo pazymius? Atsakymas: taip arba ne" << endl;
        cin >> atsakymas;

        if (atsakymas == "taip")
        {
            cout << "Iveskite nd pazymius noredami uzbaigti ivedima, iveskite -1, maksimalus nd kiekis yra 15" << endl;
            while (cin >> pazimys)
            {
                if (pazimys == -1)
                {
                    break;
                }
                g[i].nd.push_back(pazimys);
            }
            cout << "Iveskite egzamino rezulata: ";
            cin >> g[i].egz;

        }
        else
        {
            cout << "Kiek namu darbu atlikote? ";
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                uniform_int_distribution<int> distribution(min, max);
                int random_skaicius = distribution(generator);
                g[i].nd.push_back(random_skaicius);
                cout << random_skaicius << endl;
            }
            uniform_int_distribution<int> distribution(min, max);
            int random_skaicius = distribution(generator);
            g[i].egz=random_skaicius;
            cout << "Egzamino pazimys: " << random_skaicius << endl;

        }
    }
    cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas";
    for (int i=1; i<=15; i++){
        cout << "Nd" << i << " ";
    }
          if(kuris == "vidurki")
      {
        cout<< "Galutinis(Vid.) " <<endl;
      }
      else
      {
      cout<<"Galutinis(Med.)"<<endl;
      }

    for (int i = 0; i < zmones; i++)
    {
    cout << setw(15) << left << g[i].pavarde << setw(15) << left << g[i].vardas;
    for (int j = 0; j < 15; j++)
    {
        if (j < g[i].nd.size())
        {
            cout << setw(4) << left << g[i].nd[j];
        }
        else
        {
            cout << "    ";
        }
    }

    // Calculate the average of nd
    double vidurkis_nd = vidurkis(g[i].nd);

    if (kuris == "vidurki")
    {
        cout << "      " << round((0.4 * vidurkis_nd + 0.6 * g[i].egz) * 100.0) / 100.0;
    }
    else
    {
        cout << "      " << round((0.4 * vidurkis_nd + 0.6 * mediana(g[i].nd)) * 100.0) / 100.0;
    }
    cout << endl;
}

    return 0;
}

double vidurkis(vector<int> vektorius){
    int kiekis = vektorius.size();
    int suma = 0;
    for (int i = 0; i < kiekis; i++) {
        suma += vektorius[i];
    }
    return (double)suma / (double)kiekis;
}

double mediana(vector<int> vektorius){
    int kiekis = vektorius.size();
    sort(vektorius.begin(), vektorius.end());
    if (kiekis % 2 != 0) {
        return (double)vektorius[(kiekis / 2)];
    }
    return (double)(vektorius[(kiekis - 1) / 2] + vektorius[kiekis / 2]) / 2.0;
}
