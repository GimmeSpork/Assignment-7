/******************************************************************************
# Author:           Lucy P
# Lab:              Assignment 7
# Date:             May 24, 2021
# Description:      calculates your numeric and letter grade from given 
#                   assignment scores, midterm exam score, and final exam score.
# Input:            numAssigns as int, numScore as double, 
# Output:           decimalGrade as double, letterGrade as char, prompt as string.
# Sources:          zybooks, assignment 7 resources, zoom recordings.
#******************************************************************************/
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// display constant variables
const double ASSIGNMENT_WEIGHT = 0.60;
const double EXAM_WEIGHT = 0.20;

// display function prototypes
void welcome();
void displayGrade();

int readInt(string prompt);
double readScore(string prompt);

double getScoreInRange(string prompt);
double assignAverage(int numAssigns);
double calcFinalScore(double assignAvg, double midterm, double final);
char calcLetterGrade(double finalScore);

// start main function
int main();

int main() {
  welcome();

  double assignAvg = 0.0;
  double midterm = 0.0;
  double final = 0.0;

  int numberOfAssignments = 0;
  bool next = true;
  while(next) {
    numberOfAssignments = readInt("Enter the number of assignments (0 to 10): ");
    if(0 <= numberOfAssignments 
       and 
       numberOfAssignments <= 10) {
      next = false;
    } else {
      cout << "Illegal Value! Please try again!!" << endl;
    }
  }

  assignAvg = assignAverage(numberOfAssignments);
  midterm = getScoreInRange("\nEnter your midterm exam score: ");
  final = getScoreInRange("Enter your final exam score: ");

  double decimalGrade = calcFinalScore(assignAvg, midterm, final);
  char letterGrade = calcLetterGrade(decimalGrade);

  cout << fixed << setprecision(1);
  cout << "\nYour Final Numeric score is " << decimalGrade << endl;
  cout << "Your Final Grade is " << letterGrade << endl;

  cout << "\nThank you for using my Grade Calculator!" << endl;

  return 0;
}

// welcome function
void welcome() {
  cout << "Welcome to the Grade Calculation Program!" << endl;
  cout << "Please enter the following information and I will calculate your" << endl;
  cout << "Final Numerical Grade and Letter Grade for you!" << endl;
  cout << "The number of assignments must be between 0 and 10." << endl;
  cout << "All scores entered must be between 0 and 4." << endl;
  cout << endl;
}

// read number of assignments
int readInt(string prompt) {
   int numAssigns = 0;
   bool next = true;
    
   while (next) {
      cout << prompt;
      cin >> numAssigns;
      if (cin && numAssigns >= 0) {
            next = false;
      } else {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  return numAssigns;
}

// read assignment scores
double readScore(string prompt) {
  double numScore = 0.0;
  bool next = true;
    
  while (next) {
      cout << prompt;
      cin >> numScore;
      if (cin) {
          next = false;
      } else {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
  }
  return numScore;
}

// check scores are in proper range
double getScoreInRange(string prompt) {
    double score = 0.0;
    bool next = true;
    while(next) {
      score = readScore(prompt);
      if(0.0 <= score and score <= 4.0) {
        next = false;
      } else {
        cout << "Illegal Score! Please try again!" << endl;
      }
    }
    return score;
}

// assign averages
double assignAverage(int numAssigns) {
  double sum = 0.0;
  double avg = 0.0;

  for(int i = 1; i <= numAssigns; i++) {
    string promptScore = "Enter score " + to_string(i) + ": ";
    double score = getScoreInRange(promptScore);
    sum += score;
  }
  avg = sum / numAssigns;
  return avg;
}

// calculate final score numeric
double calcFinalScore(double assignAvg, double midterm, double final){
  double finalScore = 0.0;
  finalScore += assignAvg * ASSIGNMENT_WEIGHT;
  finalScore += midterm * EXAM_WEIGHT;
  finalScore += final * EXAM_WEIGHT;
  return finalScore;
}

// calculate final letter grade
char calcLetterGrade(double finalScore){
  char grade = '\0';

  if(finalScore >= 3.3) {
    grade = 'A';
  } else if(finalScore >= 2.8) {
    grade = 'B';
  } else if(finalScore >= 2.0) {
    grade = 'C';
  } else if(finalScore >= 1.2) {
    grade = 'D';
  } else {
    grade = 'F';
  }
  return grade;
}

// function to display final grades
void displayGrade(double decimalGrade, char letterGrade) {
  cout << fixed << setprecision(1);
  cout << "\nYour Final Numeric score is " << decimalGrade << endl;
  cout << "Your Final Grade is " << letterGrade << endl;
}





