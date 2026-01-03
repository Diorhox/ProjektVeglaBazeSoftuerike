# **Language Learning Project in C++ Overview**

This project is a C++ console application designed to help users learn new languages interactively. Users can:

Register by entering their first name and last name

Choose a language they want to learn

Access various features through a menu, including:

Take a quiz related to the chosen language

View a Word of the Day

See their profile

Translate basic words in the chosen language

Track their learning progress

The project is entirely built using C++, with a focus on console-based interaction.

Features

1.User Registration
  Users can register by entering their first name, last name, and language choice.

2.Quizzes
  Users can take quizzes tailored to their selected language. Quizzes track correct and incorrect answers and contribute to progress tracking.

3.Word of the Day
  Every time the user chooses this option, they will see a new word in the selected language to learn.

4.Profile Management
  Users can view their profile, including their name, selected language, and progress statistics.

5.Basic Translations
  Translate simple words from the selected language to the user's native language.

6.Progress Tracking
  The program keeps track of the user’s learning progress, including quiz performance and words learned.

Requirements

To run this project, you need:

A C++ compiler (e.g., g++, clang++, or any IDE that supports C++ like Visual Studio, Code::Blocks, or CLion)

A console/terminal for running the compiled program

Basic knowledge of how to compile and run a C++ program

How to Run

1.Clone or download the repository:

  git clone <repository-url>
  cd <project-folder>


2.Compile the project:

  If using g++:
  
  g++ ProjektiVeglaBazeSoftuerike.cpp -o LanguageLearningApp


Run the compiled program:

1. On Windows:

  ProjektiVeglaBazeSoftuerike.exe


2.On Linux/macOS:

  ./ProjektiVeglaBazeSoftuerike

Notes

Make sure your C++ compiler is properly installed and added to your system's PATH.

The program is console-based and does not require any additional libraries beyond standard C++.

All data (user profile, progress) is stored in memory. Closing the program will reset progress unless persistent storage is implemented.
