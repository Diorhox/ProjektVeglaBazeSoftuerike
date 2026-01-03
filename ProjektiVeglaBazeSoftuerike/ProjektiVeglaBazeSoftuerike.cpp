// ProjektiVeglaBazeSoftuerike.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <ctime>
#include <cstdlib> 
#include <iostream>
#include <string>
#include <unordered_map>
#define NUMRI_GJUHEVE 5
#define NUMRI_MUNDESIVE 6

using namespace std;

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
    SeeUserProgress,
    BackToStart,
    viewProfile
};

struct Student
{
    string emri;
    string mbiemri;
    Language languageChoice;
    string username = "";
    string email = "";
    string birthdate = "";
    string phoneNumber = "";
};

struct QuestionStructure
{
    string question;
    string options[4];
    int correct_index;
};

struct LevelStructure
{
    string level_name;
    QuestionStructure questions[2];
};

struct QuizStructure
{
    Language language;
    LevelStructure levels[2];
};

struct ProgressStructure
{
    Language current_language;
    LevelStructure current_level;
};

struct StudentProgress
{
    Student s;
    ProgressStructure progress;
};


struct WordOfTheDay
{
    Language lang;
    string word;
    string translation;
    string example_sentence;
};


struct userprogress
{
    Student student;
    int quizzes_taken = 0;
    int bestScore = 0;
    int currentLevel = 0;
};

userprogress progres;


void displayOptions();
AppOptions chooseOption();
void TakeTheQuiz(Student s);
void showTranslations(Language lang);
void SeeWordOfTheDay_(Student s);
void SeeUsersProgress(Student s);
void displayPersonalDetails(Student s);
void changePersonalDetails(Student& s);


void showTranslations(Language lang)
{

    unordered_map<string, string> translations;

    switch (lang)
    {
    case GERMAN:
        translations = {
            {"Hello", "Hallo"},
            {"Goodbye", "Tschüss"},
            {"Yes", "Ja"},
            {"No", "Nein"},
            {"Thank you", "Danke"},
            {"Please", "Bitte"},
            {"Book", "Buch"},
            {"Water", "Wasser"},
            {"Food", "Essen"},
            {"House", "Haus"},
            {"Friend", "Freund"},
            {"Family", "Familie"},
            {"School", "Schule"},
            {"Student", "Student"},
            {"Teacher", "Lehrer"},
            {"Day", "Tag"},
            {"Night", "Nacht"}
        };
        break;

    case ITALIAN:
        translations = {
            {"Hello", "Ciao"},
            {"Goodbye", "Addio"},
            {"Yes", "Si"},
            {"No", "No"},
            {"Thank you", "Grazie"},
            {"Please", "Per favore"},
            {"Book", "Libro"},
            {"Water", "Acqua"},
            {"Food", "Cibo"},
            {"House", "Casa"},
            {"Friend", "Amico"},
            {"Family", "Famiglia"},
            {"School", "Scuola"},
            {"Student", "Studente"},
            {"Teacher", "Insegnante"},
            {"Day", "Giorno"},
            {"Night", "Notte"}
        };
        break;

    case SPANISH:
        translations = {
            {"Hello", "Hola"},
            {"Goodbye", "Adios"},
            {"Yes", "Si"},
            {"No", "No"},
            {"Thank you", "Gracias"},
            {"Please", "Por favor"},
            {"Book", "Libro"},
            {"Water", "Agua"},
            {"Food", "Comida"},
            {"House", "Casa"},
            {"Friend", "Amigo"},
            {"Family", "Familia"},
            {"School", "Escuela"},
            {"Student", "Estudiante"},
            {"Teacher", "Profesor"},
            {"Day", "Dia"},
            {"Night", "Noche"}
        };
        break;

    case FRENCH:
        translations = {
            {"Hello", "Bonjour"},
            {"Goodbye", "Au revoir"},
            {"Yes", "Oui"},
            {"No", "Non"},
            {"Thank you", "Merci"},
            {"Please", "S'il vous plait"},
            {"Book", "Livre"},
            {"Water", "Eau"},
            {"Food", "Nourriture"},
            {"House", "Maison"},
            {"Friend", "Ami"},
            {"Family", "Famille"},
            {"School", "Ecole"},
            {"Student", "Etudiant"},
            {"Teacher", "Professeur"},
            {"Day", "Jour"},
            {"Night", "Nuit"}
        };
        break;

    case ALBANIAN:
        translations = {
            {"Hello", "Pershendetje"},
            {"Goodbye", "Mirupafshim"},
            {"Yes", "Po"},
            {"No", "Jo"},
            {"Thank you", "Faleminderit"},
            {"Please", "Ju lutem"},
            {"Book", "Liber"},
            {"Water", "Uje"},
            {"Food", "Ushqim"},
            {"House", "Shtepi"},
            {"Friend", "Mik"},
            {"Family", "Familje"},
            {"School", "Shkolle"},
            {"Student", "Student"},
            {"Teacher", "Mesues"},
            {"Day", "Dite"},
            {"Night", "Nate"}
        };
        break;
    }


    for (const auto& pair : translations)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }
}



const QuizStructure quizes[] = {
    {
        GERMAN,
        {
            {
                "Introduction To Greetings",
                {
                    {"How do you say 'Hello'?", {"Hola", "Hallo", "Ciao", "Bonjour"}, 1},
                    {"How do you say 'Goodbye'?", {"Adios", "Tschüss", "Ciao", "Au revoir"}, 1}
                }
            },
            {
                "Introduction to Numbers",
                {
                    {"What is '5'?", {"Cinco", "Cinq", "Fünf", "Pesë"}, 2},
                    {"How do you say '10'?", {"Ten", "Zehn", "Diez", "Dhjetë"}, 1}
                }
            }
        }
    },

    {
        FRENCH,
        {
            {
                "Introduction To Greetings",
                {
                    {"How do you say 'Hello'?", {"Hola", "Hallo", "Ciao", "Bonjour"}, 3},
                    {"How do you say 'Goodbye'?", {"Adios", "Tschüss", "Ciao", "Au revoir"}, 3}
                }
            },
            {
                "Introduction to Numbers",
                {
                    {"What is '5'?", {"Cinco", "Cinq", "Fünf", "Pesë"}, 1},
                    {"How do you say '10'?", {"Ten", "Zehn", "Diez", "Dhjetë"}, 0} // French: 'Dix' would be correct
                }
            }
        }
    },

    {
        ITALIAN,
        {
            {
                "Introduction To Greetings",
                {
                    {"How do you say 'Hello'?", {"Hola", "Hallo", "Ciao", "Bonjour"}, 2},
                    {"How do you say 'Goodbye'?", {"Adios", "Tschüss", "Addio", "Au revoir"}, 2}
                }
            },
            {
                "Introduction to Numbers",
                {
                    {"What is '5'?", {"Cinco", "Cinq", "Cinque", "Pesë"}, 2},
                    {"How do you say '10'?", {"Ten", "Zehn", "Dieci", "Dhjetë"}, 2}
                }
            }
        }
    },

    {
        SPANISH,
        {
            {
                "Introduction To Greetings",
                {
                    {"How do you say 'Hello'?", {"Hola", "Hallo", "Ciao", "Bonjour"}, 0},
                    {"How do you say 'Goodbye'?", {"Adios", "Tschüss", "Ciao", "Au revoir"}, 0}
                }
            },
            {
                "Introduction to Numbers",
                {
                    {"What is '5'?", {"Cinco", "Cinq", "Fünf", "Pesë"}, 0},
                    {"How do you say '10'?", {"Diez", "Zehn", "Ten", "Dhjetë"}, 0}
                }
            }
        }
    },

    {
        ALBANIAN,
        {
            {
                "Introduction To Greetings",
                {
                    {"How do you say 'Hello'?", {"Hola", "Hallo", "Ciao", "Përshëndetje"}, 3},
                    {"How do you say 'Goodbye'?", {"Adios", "Tschüss", "Ciao", "Mirupafshim"}, 3}
                }
            },
            {
                "Introduction to Numbers",
                {
                    {"What is '5'?", {"Cinco", "Cinq", "Fünf", "Pesë"}, 3},
                    {"How do you say '10'?", {"Ten", "Zehn", "Diez", "Dhjetë"}, 3}
                }
            }
        }
    }
};


const WordOfTheDay wordOfTheDayList[] = {
    { GERMAN, "Haus", "House", "Das Haus ist groß." },
    { ITALIAN, "Libro", "Book", "Il libro è interessante." },
    { SPANISH, "Amigo", "Friend", "Mi amigo es muy simpático." },
    { FRENCH, "Famille", "Family", "Ma famille est importante pour moi." },
    { ALBANIAN, "Ujë", "Water", "Uji është i nevojshëm për jetën." }
};




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
    case BackToStart:
        return "Go Back!";
    case viewProfile:
        return "View Your Profile!";
    default:
        return "";
    }
}

Language returnLanguageChoosen(char choice)
{
    switch (choice)
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
        return GERMAN;
    }
}

void displayPersonalDetails(Student s)
{
    cout << "Emri: " << s.emri << endl;
    cout << "Mbiemri: " << s.mbiemri << endl;
    cout << "Gjuha Zgjedhur: " << returnSpecificLanguage(s.languageChoice) << endl;
    cout << "Username: " << s.username << endl;
    cout << "Email: " << s.email << endl;
    cout << "Birthdate: " << s.birthdate << endl;
}
void changePersonalDetails(Student& s)
{
    cout << "Nese nuk doni te ndryshoni nje fushe, shtypni '-' ne vend te saj." << endl;
    cout << "Vendosni username te ri: ";
    cin >> s.username;
    cout << "Vendosni email te ri: ";
    cin >> s.email;
    cout << "Vendosni date te lindjes (DD/MM/YYYY): ";
    cin >> s.birthdate;
    cout << "Vendosni numrin e telefonit: ";
    cin >> s.phoneNumber;
}

void SeeWordOfTheDay_(Student s)
{
    srand(time(0));

    int totalWords = sizeof(wordOfTheDayList) / sizeof(wordOfTheDayList[0]);
    int index;


    do {
        index = rand() % totalWords;
    } while (wordOfTheDayList[index].lang != s.languageChoice);

    WordOfTheDay wod = wordOfTheDayList[index];

    cout << "\n--- WORD OF THE DAY ---\n";
    cout << "Word: " << wod.word << endl;
    cout << "Translation: " << wod.translation << endl;
    cout << "Example Sentence: " << wod.example_sentence << endl;
}



Student krijoStudentin()
{
    Student newStudent;
    string languages[] = { returnSpecificLanguage(GERMAN), returnSpecificLanguage(ITALIAN), returnSpecificLanguage(SPANISH), returnSpecificLanguage(FRENCH),
        returnSpecificLanguage(ALBANIAN) };
    cout << "Pershendetje!" << endl;
    cout << "Ju lutem jepni emrin tuaj: " << endl;

    cin >> newStudent.emri;

    cout << "Jepni mbiemrin tuaj: " << endl;
    cin >> newStudent.mbiemri;
    cout << "Zgjidhni gjuhen qe doni te mesoni: " << endl;

    char choice;

    for (int i = 0; i < NUMRI_GJUHEVE; i++) {
        cout << i + 1 << ". " << languages[i] << "( " << languages[i][0] << " )" << endl;
    }

    cin >> choice;

    newStudent.languageChoice = returnLanguageChoosen(choice);

    return newStudent;
}

AppOptions returnParticularOption(int choosen_option)
{
    switch (choosen_option)
    {
    case 1:
        return TakeQuiz;
    case 2:
        return SeeTranslations;
    case 3:
        return SeeWordOfTheDay;
    case 4:
        return SeeUserProgress;
    case 5:
        return BackToStart;
    case 6:
        return viewProfile;
    default:
        return TakeQuiz;
    }
}

struct QuizResult
{
    string question;
    string userAnswer;
    string correctAnswer;
    bool correct;
};

void TakeTheQuiz(Student s)
{
    int totalQuestions = 0;
    int correctAnswers = 0;
    QuizResult results[4];
    int resultIndex = 0;

    const QuizStructure* selectedQuiz = nullptr;
    for (int i = 0; i < 5; i++)
    {
        if (quizes[i].language == s.languageChoice)
        {
            selectedQuiz = &quizes[i];
            break;
        }
    }

    if (!selectedQuiz)
    {
        cout << "Quiz not found for your chosen language!" << endl;
        return;
    }

    for (int lvl = 0; lvl < 2; lvl++)
    {
        LevelStructure currentLevel = selectedQuiz->levels[lvl];
        cout << "\nLevel: " << currentLevel.level_name << endl;

        for (int q = 0; q < 2; q++)
        {
            QuestionStructure currentQuestion = currentLevel.questions[q];
            totalQuestions++;

            cout << "\nQ" << totalQuestions << ": " << currentQuestion.question << endl;
            for (int opt = 0; opt < 4; opt++)
            {
                cout << opt + 1 << ". " << currentQuestion.options[opt] << endl;
            }

            int userAnswer;
            cout << "Your answer (1-4): ";
            cin >> userAnswer;

            while (cin.fail() || userAnswer < 1 || userAnswer > 4)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Enter 1-4: ";
                cin >> userAnswer;
            }

            string userAnswerText = currentQuestion.options[userAnswer - 1];
            string correctAnswerText = currentQuestion.options[currentQuestion.correct_index];
            bool isCorrect = (userAnswer - 1 == currentQuestion.correct_index);

            if (isCorrect) {
                cout << "Correct!\n";
                correctAnswers++;
            }
            else {
                cout << "Incorrect! Correct answer: " << correctAnswerText << "\n";
            }

            results[resultIndex++] = { currentQuestion.question, userAnswerText, correctAnswerText, isCorrect };
        }

        progres.currentLevel = lvl + 1;
    }

    progres.quizzes_taken += 1;

    if (correctAnswers > progres.bestScore) {
        progres.bestScore = correctAnswers;
    }

    cout << "\n=== Quiz Completed ===\n";
    cout << "You got " << correctAnswers << " out of " << totalQuestions << " correct.\n";

    cout << "\nDetailed results:\n";
    for (int i = 0; i < totalQuestions; i++)
    {
        cout << "Q" << i + 1 << ": " << results[i].question << "\n";
        cout << "Your answer: " << results[i].userAnswer
            << " | Correct answer: " << results[i].correctAnswer
            << " | " << (results[i].correct ? "Correct" : "Incorrect") << "\n\n";
    }
}

void SeeUsersProgress(Student s)
{
    cout << "\n--- YOUR PROGRESS ---\n";
    cout << "Language: " << returnSpecificLanguage(s.languageChoice) << endl;
    cout << "Current Level: " << progres.currentLevel << endl;
    cout << "Quizzes Taken: " << progres.quizzes_taken << endl;
    cout << "Best Score: " << progres.bestScore << " out of 4\n";
}



void ndryshoGjuhen(Student& s)
{
    string languages[] = {
        returnSpecificLanguage(GERMAN),
        returnSpecificLanguage(ITALIAN),
        returnSpecificLanguage(SPANISH),
        returnSpecificLanguage(FRENCH),
        returnSpecificLanguage(ALBANIAN)
    };

    cout << "\n--- ZGJIDHNI NJE GJUHE TE RE ---\n";
    for (int i = 0; i < NUMRI_GJUHEVE; i++) {
        cout << i + 1 << ". " << languages[i] << endl;
    }

    char choice;
    cout << "Zgjedhja juaj: ";
    cin >> choice;

    s.languageChoice = returnLanguageChoosen(choice);
    cout << "Gjuha u ndryshua me sukses ne: " << returnSpecificLanguage(s.languageChoice) << "!\n";
}

void executeOptionChoosenFromMenu(AppOptions fillimiOption, Student s)
{
    AppOptions currentOption = fillimiOption;
    Student currentStudent = s;
    bool programiVazhdon = true;

    while (programiVazhdon)
    {
        switch (currentOption)
        {
        case TakeQuiz:
            TakeTheQuiz(currentStudent);
            break;

        case SeeTranslations:
            showTranslations(currentStudent.languageChoice);
            break;

        case SeeWordOfTheDay:
            SeeWordOfTheDay_(currentStudent);
            break;

        case SeeUserProgress:
            SeeUsersProgress(currentStudent);
            break;

        case viewProfile:
            cout << "\n--- Your Profile Details ---\n";
            displayPersonalDetails(currentStudent);
            cout << "Do you want to change your personal details? (Y/N): ";
            char changeChoice;
            cin >> changeChoice;
            if (changeChoice == 'Y' || changeChoice == 'y') {
                changePersonalDetails(currentStudent);
                cout << "Personal details updated successfully!\n";
            }
            break;

        case BackToStart:
            char pergjigja;
            cout << "\n-----------------------------------" << endl;
            cout << "Deshironi te vazhdoni me gjuhe tjeter? (P - Po / J - Jo): ";
            cin >> pergjigja;

            if (pergjigja == 'P' || pergjigja == 'p')
            {
                ndryshoGjuhen(currentStudent);
                currentOption = chooseOption();
                continue;
            }
            else
            {
                cout << "Mirupafshim " << currentStudent.emri << "!" << endl;
                programiVazhdon = false;
                return;
            }
            break;
        }

        cout << "\nShtypni ENTER per te shfaqur menune...";
        cin.ignore(1000, '\n');
        cin.get();

        
        currentOption = chooseOption();
    }
}
void displayOptions()
{
    string options[] = {
        returnSpecificOption(TakeQuiz),
        returnSpecificOption(SeeTranslations),
        returnSpecificOption(SeeWordOfTheDay),
        returnSpecificOption(SeeUserProgress),
        returnSpecificOption(BackToStart),
        returnSpecificOption(viewProfile)
    };

    cout << "Qfare Deshironi Te Beni Ne Programin Tone: " << endl;

    int choosenOption;

    for (int i = 0; i < NUMRI_MUNDESIVE; i++) {
        cout << i + 1 << "." << options[i] << " ( " << i + 1 << " ) " << endl;
    }

}

AppOptions chooseOption()
{
    displayOptions();

    int choosenOption;
    cin >> choosenOption;

    return returnParticularOption(choosenOption);
}

int main()
{
    Student studenti = krijoStudentin();
    AppOptions optionChoosen = chooseOption();
    executeOptionChoosenFromMenu(optionChoosen, studenti);


}