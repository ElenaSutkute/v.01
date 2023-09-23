#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Duomenys {
  char vardas[15];
  char pavarde[15];
  vector<int> nd;
  int egz;
  double vid;
  double med;
};
int main() {
  Duomenys g[20];
  int zmones;
  int pazimys;
  cout<<"Iveskite zmoniu skaiciu: ";
  cin>>zmones;
  for(int i=0; i<zmones; i++){
    cout<<"Iveskite varda: ";
    cin>>g[i].vardas;
    cout<<"Iveskite pavarde: ";
    cin>>g[i].pavarde;
    cout<<"Iveskite namu darbu pazymius noredami ubaigti ivedima, iveskite -1, maksimalus nd kiekis yra 10"<<endl;
    while (cin>>pazimys){
    if (pazimys==-1){
      break;
    }
    g[i].nd.push_back(pazimys);
  }
  cout<<"Iveskite egzamino rezulata: ";
  cin>>g[i].egz;
  }
  cout<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde";
  for(int i=1; i<=10; i++){
    cout<<"Nd"<<i<<" ";
  }
  cout<<"Egz"<<endl;

  for(int i=0; i<zmones; i++){
    cout<<setw(15)<<left<<g[i].pavarde<<setw(15)<<left<<g[i].vardas;
    for (int j=0; j<10; j++){
        if (j<g[i].nd.size()){
            cout<<setw(4)<<left<<g[i].nd[j];
        }else{
        cout<<"    ";
        }
    }
    cout<<" "<<g[i].egz<<endl;
  }


  return 0;
}
