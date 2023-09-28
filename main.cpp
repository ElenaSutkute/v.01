#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
using namespace std;

struct Duomenys
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    double vid, med;
};


vector<Duomenys> skaitytiDuomenisIsFailo();
void spausdintiDuomenis(const vector<Duomenys> &studentai);
vector<Duomenys> ivestiDuomenisRanka();
pair<double, double> skaiciuotiGalutini(const Duomenys &studentas);
double vidurkis(const vector<int> &vektorius);
double mediana(const vector<int> &vektorius);
bool rusiavimas(const Duomenys &a, const Duomenys &b);

int main()
{
    string ats;
    vector<Duomenys> studentai;

    cout << "Ar skaityti duomenis is failo? taip/ne" << endl;
    string tekstinis;
    cin >> tekstinis;

    if (tekstinis == "taip")
    {
        studentai = skaitytiDuomenisIsFailo();
    }
    else
    {
            studentai = ivestiDuomenisRanka();
    }

    spausdintiDuomenis(studentai);

    return 0;
}

vector<Duomenys> skaitytiDuomenisIsFailo()
{
    vector<Duomenys> studentai;

    ifstream infile("studentai.txt");
    if (!infile)
    {
        cerr << "Error: Unable to open the file." << endl;
        exit(1);
    }

    string eile;
    getline(infile, eile);
    while (getline(infile, eile))
    {
        Duomenys studentas;
        istringstream iss(eile);
        iss >> studentas.vardas >> studentas.pavarde;
        for (int i = 0; i < 15; i++)
        {
            int pazimys;
            iss >> pazimys;
            if (pazimys == -1)
            {
                break;
            }
            studentas.nd.push_back(pazimys);
        }
        iss >> studentas.egz;
        studentai.push_back(studentas);
    }
    infile.close();
    sort(studentai.begin(), studentai.end(), rusiavimas);

    return studentai;
}

vector<Duomenys> ivestiDuomenisRanka()
{
    int zmones;
    string atsakymas;
    cout << "Iveskite zmoniu skaiciu: ";
    cin >> zmones;

    vector<Duomenys> studentai;

    for (int i = 0; i < zmones; i++)
    {
        Duomenys studentas;


        cout << "Iveskite varda: ";
        try {
        cin >> studentas.vardas;
        if (!isalpha(studentas.vardas.front())) {
            throw runtime_error("Negalima sintakse vedant varda. Naudokite tik raides.");
            }
        }
        catch (const runtime_error& e) {
        cerr << e.what() << endl;
        }
        cout << "Iveskite pavarde: ";
        try {
        cin >> studentas.pavarde;
        if (!isalpha(studentas.pavarde.front())) {
            throw runtime_error("Negalima sintakse vedant pavarde. Naudokite tik raides.");
            }
        }
        catch (const runtime_error& e) {
        cerr << e.what() << endl;
        }

        cout << "Ar norite ivesti savo pazymius? Atsakymas: taip arba ne" << endl;
        try {
        cin >> atsakymas;
        if (atsakymas != "taip" && atsakymas != "ne") {
            throw runtime_error("Neteisinga ivestis. Veskite 'taip' arba 'ne'.");
            }
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
        }

        if (atsakymas == "taip")
        {
cout << "Iveskite nd pazymius noredami uzbaigti ivedima, iveskite -1" << endl;
int pazimys;

while (cin >> pazimys)
{
    try {
        if (pazimys == -1) {
            break;
        }
        if (pazimys <= 0 || pazimys > 10) {
            throw runtime_error("Pazimys turi buti (0,10] ribose.");
        }
        studentas.nd.push_back(pazimys);
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
}

    cout << "Iveskite egzamino rezultata: ";
    cin >> studentas.egz;
        }
        else
        {
            int n;
            cout << "Kiek namu darbu atlikote? ";
            cin >> n;
            random_device rd;
            mt19937 generator(rd());
            int min = 5;
            int max = 10;

            for (int j = 0; j < n; j++)
            {
                uniform_int_distribution<int> distribution(min, max);
                int random_skaicius = distribution(generator);
                studentas.nd.push_back(random_skaicius);
                cout<<random_skaicius<<endl;
            }
            uniform_int_distribution<int> distribution(min, max);
            studentas.egz = distribution(generator);
            cout<<"Egazamino pazimys: "<<distribution(generator)<<endl;
        }
        studentai.push_back(studentas);
    }
    return studentai;
}




pair<double, double> skaiciuotiGalutini(const Duomenys &studentas)
{
    double vidurkis_nd = vidurkis(studentas.nd);
    double galutinis_vid = round((0.4 * vidurkis_nd + 0.6 * studentas.egz) * 100.0) / 100.0;
    double galutinis_med = round((0.4 * mediana(studentas.nd) + 0.6 * studentas.egz) * 100.0) / 100.0;


    return make_pair(galutinis_vid, galutinis_med);
}

void spausdintiDuomenis(const vector<Duomenys> &studentai)
{
    cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas"
         << setw(20) << left << "Galutinis(Vid.)" << setw(20) << left << "Galutinis(Med.)" << endl;

    for (const Duomenys &studentas : studentai)
    {
        cout << setw(15) << left << studentas.pavarde << setw(15) << left << studentas.vardas;


        pair<double, double> galutiniai = skaiciuotiGalutini(studentas);

        cout << setw(20) << fixed << setprecision(2) << left << galutiniai.first << setw(20) << left << galutiniai.second << endl;
    }
}

double vidurkis(const vector<int> &vektorius)
{
    int kiekis = vektorius.size();
    int suma = 0;
    for (int i = 0; i < kiekis; i++)
    {
        suma += vektorius[i];
    }
    return static_cast<double>(suma) / static_cast<double>(kiekis);
}

double mediana(const vector<int> &vektorius)
{
    int kiekis = vektorius.size();
    vector<int> kopija = vektorius;
    sort(kopija.begin(), kopija.end());
    if (kiekis % 2 != 0)
    {
        return static_cast<double>(kopija[kiekis / 2]);
    }
    return static_cast<double>(kopija[kiekis / 2 - 1] + kopija[kiekis / 2]) / 2.0;
}

bool rusiavimas(const Duomenys &a, const Duomenys &b)
{
    if (a.pavarde != b.pavarde)
    {
        return a.pavarde < b.pavarde;
    }
    else
    {
        return a.vardas < b.vardas;
    }
}
