// ProjektiVeglaBazeSoftuerike.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Progresi {
    int numriKuizeve = 0;
    int rezultatiMax = 0;
};
void perkthime() {
    cout << "\nPERKTHIME BAZE (ANGLISHT → SHQIP)\n";

    cout << "Hello        -> Pershendetje\n";
    cout << "Bye          -> Lamtumire\n";
    cout << "Thanks       -> Faleminderit\n";
    cout << "Please       -> Ju lutem\n";
    cout << "Sorry        -> Me fal\n";
    cout << "Yes          -> Po\n";
    cout << "No           -> Jo\n";
    cout << "Friend       -> Shok / Mik\n";
    cout << "Family       -> Familje\n";
    cout << "Book         -> Liber\n";
    cout << "School       -> Shkolle\n";
    cout << "Teacher      -> Mesues\n";
    cout << "Student      -> Student\n";
    cout << "Water        -> Uje\n";
    cout << "Food         -> Ushqim\n";
    cout << "House        -> Shtepi\n";
    cout << "Love         -> Dashuri\n";
    cout << "Day          -> Dite\n";
    cout << "Night        -> Nate\n";
}
void Kuizi(Progresi p) {
    int piket = 0;
    char pergjigja;

    cout << "\nKuiz (ANGLISHT) \n";

    cout << "1. Hello ne anglisht do te thote?\n";
    cout << "a) Pershendetje\nb) Lamtumire\n";
    cin >> pergjigja;
    if (pergjigja == 'a') piket++;

    cout << "2. Thank you ne anglisht do te thote?\n";
    cout << "a) Ju lutem\nb) Faleminderit\n";
    cin >> pergjigja;
    if (pergjigja == 'b') piket++;

    cout << "3. Book ne anglisht do te thote?\n";
    cout << "a) Liber\nb) Shkolle\n";
    cin >> pergjigja;
    if (pergjigja == 'a') piket++;

    cout << "4. Water ne anglisht do te thote?\n";
    cout << "a) Uje\nb) Ushqim\n";
    cin >> pergjigja;
    if (pergjigja == 'a') piket++;

    cout << "5. Friend ne anglisht do te thote?\n";
    cout << "a) Armik\nb) Mik\n";
    cin >> pergjigja;
    if (pergjigja == 'b') piket++;

    cout << "6. House ne anglisht do te thote?\n";
    cout << "a) Shtepi\nb) Dite\n";
    cin >> pergjigja;
    if (pergjigja == 'a') piket++;

    p.numriKuizeve++;
    if (piket > p.rezultatiMax)
        p.rezultatiMax = piket;

    cout << "\nRezultati juaj: " << piket << "/6\n";
}



int main()
{
   
Progresi progres;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
