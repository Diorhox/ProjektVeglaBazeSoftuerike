// ProjektiVeglaBazeSoftuerike.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
#define NUMRI_GJUHEVE 5

enum Language 
{
    GERMAN,
    ITALIAN,
    SPANISH,
    FRENCH,
    ALBANIAN
};

enum AppOptions
{
    TakeQuiz,
    SeeTranslations,
    SeeWordOfTheDay,
    SeeUserProgress
};

struct Student 
{
    string emri;
    string mbiemri;
    Language languageChoice;
};

// IDEJA E PROGRAMIT
// 1. Kur ne bojm run programin duhet qe te kerkohet emri,mbiemri,dhe pastaj ti vendosen userit disa opsione
// se qfar useri mund te zgjedh nga gjuhet e huaja qe te mesoj
// 2. Pasi te zgjedh njeren nga gjuhet e huaja ja bojme display disa mundesi ati, disa prej tyre mundesive jane:
//  2.1. Me iu nenshtru nje quizi ( ne fund tregon rezultatin pergjate ati quizi )
//  2.2. Me i shiku disa perkthime te disa fjaleve baze te asaj gjuhe
//  2.3. Word of the day ( qdo here mundet me zgjedh opsionin "Word of the day" dhe pastaj shfaqet nje fjale random nga gjuha e huaj )
//  2.4. User Progress ( Useri mundet me pa progressin qe ai ka pas ne program p.sh levelin ne te cilin eshte, rezultatin me te mire gjate quizeve etj )
// 3.Useri mundet me u kthy ne menu kryesore kur te doje edhe ta zgjedh perseri ndonje gjuhe tjeter per ta mesuar


string returnSpecificLanguage(Language lang)
{
    switch (lang)
    {
        case GERMAN:
		    return "German";
        case ITALIAN:
            return "Italian";
        case SPANISH:
		    return "Spanish";
	    case FRENCH:
		    return "French";
        case ALBANIAN:
			return "Albanian";
        default:
            return "";
    }
}

string returnSpecificOption(AppOptions option)
{
    switch (option) {
        case TakeQuiz:
            return "Continue Your Quizes";
        case SeeTranslations:
            return "See Some Of The Basic Word Translations";
        case SeeWordOfTheDay:
            return "See The Word Of The Day!";
        case SeeUserProgress:
            return "See Your Progress So Far!";
        default:
            return "";
    }
}

Language returnLanguageChoosen(char choice)
{
    switch(choice)
    {
        case 'G':
        case 'g':
            return GERMAN;
        case 'I':
        case 'i':
            return ITALIAN;
        case 'S':
        case 's':
            return SPANISH;
        case 'F':
        case 'f':
            return FRENCH;
        case 'A':
        case 'a':
            return ALBANIAN;
        default:
            return GERMAN; // Default value
	}
}

void displayPersonalDetails(Student s)
{
    cout << "Emri: " << s.emri << endl;
    cout << "Mbiemri: " << s.mbiemri << endl;
    cout << "Gjuha Zgjedhur: " << returnSpecificLanguage(s.languageChoice) << endl;
}

Student krijoStudentin()
{
    Student newStudent;
    string languages[] = [returnSpecificLanguage(GERMAN), returnSpecificLanguage(ITALIAN), returnSpecificLanguage(SPANISH), returnSpecificLanguage(FRENCH), 
        returnSpecificLanguage(ALBANIAN)];
    cout << "Pershendetje!" << endl;
    cout << "Ju lutem jepni emrin tuaj: " << endl;
    
    cin >> newStudent.emri;

	cout << "Jepni mbiemrin tuaj: " << endl;
    cin >> newStudent.mbiemri;
    cout << "Zgjidhni gjuhen qe doni te mesoni: " << endl;

    char choice;

    for (int i = 0; i < NUMRI_GJUHEVE; i++) {
        cout << i + 1 << ". " << languages[i] << '( ' << languages[i][0] << ' )' << endl;
    }

    cin >> choice;

    newStudent.languageChoice = returnLanguageChoosen(choice);

    displayPersonalDetails(newStudent);
}

void displayOptions()
{
    //TakeQuiz,
    //    SeeTranslations,
    //    SeeWordOfTheDay,
    //    SeeUserProgress
    string options[] = {
        returnSpecificOption(TakeQuiz),
        returnSpecificOption(SeeTranslations),
        returnSpecificOption(SeeWordOfTheDay),
        returnSpecificOption(SeeUserProgress)
    };
}



int main()
{
    Student studenti = krijoStudentin();

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
