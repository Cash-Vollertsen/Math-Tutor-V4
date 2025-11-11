/*
 * Program:       Math Tutor V4
 * Programmer(s): Brecken Schwartz, Cash Vollertsen
 * Date:          2025.10.22
 * GitHub:        https://github.com/Cash-Vollertsen/Math-Tutor-V4
 * Description:   This program teaches math to students. It first
 *                gives them an intro, has them give a name, and then
 *                asks math question with various levels and ranges
 *                and tells them if they answered the question correctly.
 *                Then gives you a summary report to see how you did.
 *                It has loops that allow a person to infinitely play
 *                the math tutor.
 */

#include <iostream>  //for input/output
#include <cstdlib> //for rand(), srand()
#include <string> //for string operations
#include <ctime> //for time() seeding random
#include <limits> //for numeric_limits in input validation
#include <cctype> //for tolower()
#include <vector> //for storing question data
#include <iomanip> //for setw(), setprecision()

using namespace std;

int main() {
    enum MATH_TYPE { MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV = 4 };

    int leftNum = 0;            //left number for the math problem
    int rightNum = 0;           //right number for the math problem
    int correctAns = 0;         // correct answer used for
    int userAns = 0;
    int lvlNum = 1;             // what level they are currently on
    int temp = 0;
    int mathType = 0;
    int stop = 0;
    int numAnsIncrTot = 0;      // Total incorrect
    int questionTot = 0;        // Total questions answered
    int oldLvlNum = lvlNum;
    int numAnsCrt = 0;          // answers they have gotten correct
    int numAnsIncr = 0;         // answers they have gotten wrong
    int levelRang = 10;
    int attemptsUsed = 3; // assume first try unless they miss

    double percentCrt = 0;      // Percent they got correct
    double numAnsCrtTot = 0;    // Total correct

    const int NUM_ATTEMPTS = 3;

    char mathSymb = '?';

    vector<vector<int> > mathQuestions;

    string loop, name;

    srand(time(nullptr));

    cout << "********************************************************************" << endl;
    cout << "                                  ___                               " << endl;
    cout << "                   |V| _ _|_|_     |    _|_ _  __                   " << endl;
    cout << "                   | |(_| |_| |    | |_| |_(_) |                    " << endl;
    cout << "********************************************************************" << endl;
    cout << "*                 Welcome to the Simple Math Tutor                 *" << endl;
    cout << "********************************************************************" << endl;
    cout << endl;

    cout << "Math Jokes:" << endl;
    cout << "   * Why is six afraid of seven? Because seven eight nine!" << endl;
    cout << "   * What did zero say to eight? 'Nice belt!'" << endl;
    cout << "   * Why was the math book so sad? Because it had too many problems!" << endl;
    cout << endl;
    cout << "********************************************************************" << endl;

    cout << "What is your name? ";
    getline(cin, name);
    cout << "Welcome, " << name << ", to the Simple Math Tutor!" << endl;

    do {
        // generate numbers
        leftNum = (rand() % levelRang) + 1;
        rightNum = (rand() % levelRang) + 1;
        mathType = (rand() % 4) + 1;

        switch (mathType) {
            case MT_ADD:
                mathSymb = '+';
                correctAns = leftNum + rightNum;
                break;
            case MT_SUB:
                mathSymb = '-';
                //Makes sure there are no negative results
                if (leftNum < rightNum) {
                    temp = leftNum;
                    leftNum = rightNum;
                    rightNum = temp;
                }
                correctAns = leftNum - rightNum;
                break;
            case MT_MUL:
                mathSymb = '*';
                correctAns = leftNum * rightNum;
                break;
            case MT_DIV:
                mathSymb = '/';
                //Force interger division
                //Multiply left num by right num so division is always exact
                leftNum = leftNum * rightNum;
                correctAns = leftNum / rightNum;
                break;
            default:
                cout << "Invalid question type: " << mathType << endl;
                return -1;
        }

        cout << "[Level " << lvlNum << "]" << endl;
        cout << leftNum << " " << mathSymb << " " << rightNum << " = ";

        vector<int> row = { lvlNum, leftNum, static_cast<int>(mathSymb), rightNum, correctAns };

        bool gotCorrect = false;

        // Countdown attempts loop
        for (int i = NUM_ATTEMPTS; i > 0; i--) {
            attemptsUsed = i; // starts at 3, counts down
            //Ensures the user enters a valid number
            //if input fails, the invalid data is ignored
            //user is prompted the question again
            while (!(cin >> userAns)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number: ";
            }

            if (userAns == correctAns) {
                gotCorrect = true;
                numAnsCrt++;
                numAnsCrtTot++;
                cout << "You got it correct!" << endl << endl;
                row.push_back(i);
                break;
            } else {
                if (i > 1) {
                    cout << "Incorrect. You have " << (i - 1)
                         << " attempt" << ((i - 1) > 1 ? "s" : "") << " left." << endl;
                    cout << leftNum << " " << mathSymb << " " << rightNum << " = ";
                } else {
                    cout << "Out of attempts! The correct answer was "
                         << correctAns << "." << endl << endl;
                    numAnsIncr++;
                    numAnsIncrTot++;
                    row.push_back(0);
                }
            }
        }

        // store results
        if (gotCorrect) {
            row.push_back(attemptsUsed); // how many left when correct

        } else {
            row.push_back(0); // incorrect only gets 0
        }

        mathQuestions.push_back(row);

        // level up/down
        int oldLvlNum = lvlNum;
        if (numAnsCrt == 3) {
            levelRang += 10;
            lvlNum++;
            numAnsCrt = 0;
            numAnsIncr = 0;
            cout << "Leveling up! The levels will be a bit harder." << endl;
            cout << "New range: 1-" << levelRang << endl << endl;
        } else if (numAnsIncr == 3 && levelRang != 10) {
            levelRang -= 10;
            lvlNum--;
            numAnsCrt = 0;
            numAnsIncr = 0;
            cout << "Leveling down! The levels will be a bit easier." << endl;
            cout << "New range: 1-" << levelRang << endl << endl;
        }

        // check if level changed

        if (oldLvlNum != lvlNum)
        {
            cout << "Do you want to continue (y=yes | n=no)? ";
            cin >> loop;
            for (char &c : loop) c = tolower(c);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            oldLvlNum = lvlNum;
        }
        if (loop == "no" || loop == "n") {
            stop = 1;
        }

    } while (stop == 0);

    // SUMMARY REPORT (outside loop)
    questionTot = numAnsIncrTot + numAnsCrtTot;
    percentCrt = (static_cast<double>(numAnsCrtTot) / questionTot) * 100.0;

    cout << "---------------------------------------" << endl;
    cout << "            Summary Report             " << endl;
    cout << "---------------------------------------" << endl;
    cout << "Level           Question         Result" << endl;
    cout << "_______  _____________________  _______" << endl;

    for (int i = 0; i < mathQuestions.size(); i++) {
        lvlNum = mathQuestions.at(i).at(0);
        leftNum = mathQuestions.at(i).at(1);
        mathSymb = static_cast<char>(mathQuestions.at(i).at(2));
        rightNum = mathQuestions.at(i).at(3);
        correctAns = mathQuestions.at(i).at(4);
        int result = mathQuestions.at(i).at(5);

        cout << " " << setw(2) << right << lvlNum << " "
             << setw(12) << right << leftNum << " " << mathSymb
             << " " << rightNum << " = " << setw(4) << correctAns << " ";

        if (result > 0)
            cout << setw(10) << result;
        else
            cout << setw(10) << "incorrect";

        cout << endl;
    }

    cout << "---------------------------------------" << endl;
    cout << setw(20) << right << "Total Questions : " << setw(5) << questionTot << endl;
    cout << setw(20) << right << "Total Correct   : " << setw(5) << numAnsCrtTot << endl;
    cout << setw(20) << right << "Total Incorrect : " << setw(5) << numAnsIncrTot << endl;
    cout << setw(20) << right << "Average Correct : " << setw(8) << fixed << setprecision(1) << percentCrt << "%" << endl;
    cout << "Thanks for playing, " << name << "! Keep practicing your math!" << endl;

    return 0;
}