#include "my_lib.h""

int main()
{
    string ats;
    vector<Duomenys> studentai;

    cout << "Ar skaityti duomenis is failo? taip/ne" << endl;
    string tekstinis;
    try
    {
        cin >> tekstinis;
        if (tekstinis != "taip" && tekstinis != "ne")
        {
            throw runtime_error("Error. Veskite tik 'taip' arba 'ne'");
        }
    }
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

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

