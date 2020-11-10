#include <iostream>
#include <vector>
using namespace std;

struct Person
{
    std::string fnamn;
    std::string enamn;
    std::string nummer;
};

void visa_person(const vector<Person>& telefonregister, string visa)
{
    // Denna funktion tar emot ett telefonregister och ett f�rnamn p� den person-post som skall visas. 

    // Om det finns en eller flera person-poster med detta f�rnamn i registret, 
    // s� skall telefonnumret till dessa visas, p� formen: "f�rnamn efternamn: telefonnummer".
    string fnamn, enamn, nummer;
    bool found = false;

    for (int i = 0; i < telefonregister.size(); i++)
    {
        if (telefonregister[i].fnamn == visa)
        {
            found = true;
            fnamn = telefonregister[i].fnamn;
            enamn = telefonregister[i].enamn;
            nummer = telefonregister[i].nummer;
            std::cout << fnamn << " " << enamn << ": " << nummer << std::endl;
        }
    }




    // Om ingen person-post hittas med det s�kta f�rnamnet, s� skall f�ljande skrivas ut.
    if (!found)
        std::cout << "Hittade inget nummer!" << std::endl;
}

void skriv_hela_telefonreg(const vector<Person>& telefonregister)
{
    // Denna funktion tar emot ett telefonregister och visar samtliga poster i 
    // telefonregistret p� formen: "f�rnamn efternamn: telefonnummer".
    for (Person p : telefonregister)
    {
        string fnamn, enamn, nummer;
        fnamn = p.fnamn;
        enamn = p.enamn;
        nummer = p.nummer;

        std::cout << fnamn << " " << enamn << ": " << nummer << std::endl;
    }
}

void ny_person(vector<Person>& telefonregister, string fnamn, string enamn, string nummer)
{
    // Denna funktion tar emot ett telefonregister och ett f�rnamn, ett efternamn och 
    // ett telefonnummer till den nya person-post som skall skapas och l�ggas till i telefonboken, 
    // d�refter l�ggs person-posten till registret.

    Person p;
    p.fnamn = fnamn;
    p.enamn = enamn;
    p.nummer = nummer;

    telefonregister.push_back(p);

}

void ta_bort_person(vector<Person>& telefonregister, string tabort)
{
    // Denna funktion tar emot ett telefonregister och ett f�rnamn p� den person-post 
    // som skall tas bort ur registret.
    // Om det finns fler person-poster med samma f�rnamn, s� tas alla dessa bort.

    // N�r en person-post tas bort s� skrivs namnet p� person-posten ut p� sk�rmen (f�rnamn efternamn), 
    // men ingen anv�ndardialog skall finnas, dvs. anv�ndaren skall inte bekr�fta borttag.

    string fnamn, enamn;

    for (int i = 0; i < telefonregister.size(); i++)
    {
        if (telefonregister[i].fnamn == tabort)
        {
            fnamn = telefonregister[i].fnamn;
            enamn = telefonregister[i].enamn;
            telefonregister.erase(telefonregister.begin() + i);
        }
    }

    std::cout << fnamn << " " << enamn << " tas nu bort." << std::endl;

}

int main()
{
    // Dessa personer skall finnas med som person-poster i telefonregistret.
    /*
    "Christina", "Nyberg","0707423653"
    "Josefin", "Danielsson", "0705463245"
    "Ellen", "Lindgren", "0705643229"
    "Stig", "Ek", "0705673247"
    "Linus", "Jonasson", "0703457923"
    "Adam", "Nordin", "0203456297"
    */

    Person christina, josefine, ellen, stig, linus, adam;
    christina.fnamn = "Christina";
    christina.enamn = "Nyberg";
    christina.nummer = "0707423653";

    josefine.fnamn = "Josefin";
    josefine.enamn = "Danielsson";
    josefine.nummer = "0705463245";


    ellen.fnamn = "Ellen";
    ellen.enamn = "Lindgren";
    ellen.nummer = "0705643229";

    stig.fnamn = "Stig";
    stig.enamn = "Ek";
    stig.nummer = "0705673247";

    linus.fnamn = "Linus";
    linus.enamn = "Jonasson";
    linus.nummer = "0703457923";

    adam.fnamn = "Adam";
    adam.enamn = "Nordin";
    adam.nummer = "0203456297";
    // H�r ska du deklarera den variabel som skall inneh�lla ditt register!

    vector<Person> telefonregister;
    telefonregister.push_back(christina);
    telefonregister.push_back(josefine);
    telefonregister.push_back(ellen);
    telefonregister.push_back(stig);
    telefonregister.push_back(linus);
    telefonregister.push_back(adam);
    // H�r skall en liten kommandostyrd huvudmeny skrivas. Observera att vissa kommandon
    // beh�ver fler v�rden som skall matas in. I menyn skall f�ljande val 
    // av Kommandon finnas:
    //  Ny person               - 'n' f�rnamn efternamn telefonnummer
    //  Visa en person          - 'v' f�rnamn
    //  Skriv hela telefonboken - 's'
    //  Ta bort en person       - 'd' f�rnamn
    //  Avsluta                 � 'q'

    char kommando = NULL;
    string fnamn, enamn, nummer;
    while (kommando != 'q') {
        std::cout << "Kommando: ";
        cin >> kommando;

        switch (kommando)
        {
        case 'n':
            cout << "F�rnamn: ";
            cin >> fnamn;
            cout << "Efternamn: ";
            cin >> enamn;
            cout << "Nummer: ";
            cin >> nummer;
            ny_person(telefonregister, fnamn, enamn, nummer);
            break;
        case 'v':
            cin >> fnamn;
            visa_person(telefonregister, fnamn);
            break;
        case 's':
            skriv_hela_telefonreg(telefonregister);
            break;
        case 'd':
            cin >> fnamn;
            ta_bort_person(telefonregister, fnamn);
            break;
        case 'q':
            cout << "Hejd�!";
        }
    }
    return 0;
}
