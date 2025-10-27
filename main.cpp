/*
 * Program:       Math Tutor V4
 * Programmer(s): Brecken Schwartz, Cash Vollertsen
 * Date:          2025.10.22
 * GitHub:        https://github.com/Cash-Vollertsen/Math-Tutor-V4
 * Description:   This program teaches math to students. It first
 *                gives them an intro, has them give a name, and then
 *                asks math question with various levels and ranges
 *                and tells them if they answered the question correctly.
 *                Then gives you a summary report to see how hyou did.
 *                It has loops that allow a person to infinitely play
 *                the math tutor.
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <limits>
#include <cctype>
#include <vector>
#include <iomanip>

using namespace std;




int main() {
    enum MATH_TYPE { MT_ADD = 1, MT_SUB = 2,  //used for the switch case
                    MT_MUL = 3, MT_DIV = 4 }; //for the math symbols

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
    int i = 1;
    double percentCrt = 0;      // Percent they got correct
    double numAnsCrtTot = 0;    // Total correct
    const int NUM_ATTEMPTS = 3;
    int numAnsCrt = 0;          // answers they have gotten correct
    int numAnsIncr = 0;         // answers they have gotten wrong
    int levelRang = 10;
    int numAtp = 3;
    int attemptsUsed = 1; // assume first try unless they miss
    char mathSymb = '?';
    vector<vector<int> > mathQuestions;




    string loop;
    string name;
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

    cout << endl;
    cout << "What is your name? ";
    getline(cin, name); // gets their entire name
    cout << "Welcome, " << name << ", to the Simple Math Tutor!" << endl;


    do
    {
        //starts the do loop that generates math problems


        //left number and right number generation using levelRang(e)
        leftNum = (rand() % levelRang) + 1;
        rightNum = (rand() % levelRang) + 1;
        mathType = (rand() % 4) + 1; //Generates numbers 1-4 to use in the switch


        switch (mathType)
        {
        case MT_ADD: // Addition problem
            mathSymb = '+';
            correctAns = leftNum + rightNum;
            break;
        case MT_SUB: //Subtraction problem
            mathSymb = '-';
            if (leftNum < rightNum) {
                temp = leftNum;
                leftNum = rightNum;
                rightNum = temp;
            }
            correctAns = leftNum - rightNum;
            break;
        case MT_MUL: // Multiplication problem
            mathSymb = '*';
            correctAns = leftNum * rightNum;
            break;
        case MT_DIV: // Division problem
            mathSymb = '/';
            leftNum = leftNum * rightNum;
            correctAns = leftNum / rightNum;
            break;
        default:
            cout << "Invalid question type: " << mathType << endl;
            cout << "Program ended with an error -1" << endl;
            cout << "Please report this error to Cash Vollertsen or William Wilkey";
            return -1;
        }



        cout << "[Level " << lvlNum << "]" << endl;
        cout << leftNum << " " << mathSymb << " " << rightNum << endl;

        vector<int> row = {lvlNum, leftNum, static_cast<int>(mathSymb), rightNum, correctAns, numAtp};



        while (!(cin >> userAns)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input!" << endl;
            cout << "Please enter a number: ";
        }


        for (int i = 0; userAns != correctAns && i < NUM_ATTEMPTS; i++) {
            cout << "That is incorrect. You have " << (NUM_ATTEMPTS - (i + 1)) << " attempts left:" << endl;
            cout << leftNum << " " << mathSymb << " " << rightNum << endl;
            cin >> userAns;

            attemptsUsed = i + 2; // updates attempts count each loop

            if (userAns == correctAns) break; // stop early if they got it right

            if ((i + 1) == NUM_ATTEMPTS) {
                cout << "You are out of attempts." << endl;
                numAnsIncr++;
                numAnsIncrTot++;
                row.push_back(0); // 0 = failed
            }
        }


        if (userAns == correctAns) {
            numAnsCrt++;
            numAnsCrtTot++;
            cout << "You got it correct!" << endl << endl;

            row.push_back(attemptsUsed); // record actual attempts
        }

        if (numAnsCrt == 3) {
            levelRang += 10;
            lvlNum++;
            numAnsCrt = 0;
            numAnsIncr = 0;
            cout << "Leveling up! " << "The Levels will be a smidge harder." << endl;
            cout << "The new range of numbers is 1-" << levelRang << endl <<endl;
        }

        if (numAnsIncr == 3 && levelRang != 10) {
            levelRang -= 10;
            numAnsCrt = 0;
            numAnsIncr = 0;
            lvlNum--;

            cout << "Leveling down! The levels will be a little easier." << endl;
            cout << "The new range of numbers is 1-" << levelRang << endl;
        }

        mathQuestions.push_back(row);


        getline(cin, loop);

        while ((numAnsIncr == 0) && (numAnsCrt == 0)) {

            cout << "Do you want to continue (y=yes | n=no)? ";
            getline(cin, loop);

            for (int i = 0; i < loop.size(); i++) {
                loop.at(i) = tolower(loop.at(i));
            }
            if (loop == "yes" || loop == "y") {
                break;
            }
            if (loop == "no" || loop == "n") {
                stop++;
                questionTot = numAnsIncrTot + numAnsCrtTot;
                percentCrt = (numAnsCrtTot / questionTot) * 100;



                cout << "---------------------------------------" << endl;
                cout << "            Summary Report             " << endl;
                cout << "---------------------------------------" << endl;
                cout << "Level          Question        Attempts" << endl;
                cout << "_______ _____________________ _________" << endl;
                for (int n = 0; n < mathQuestions.size(); n++) {
                    lvlNum = mathQuestions.at(n).at(0);
                    leftNum = mathQuestions.at(n).at(1);
                    mathSymb = static_cast<char>(mathQuestions.at(n).at(2));
                    rightNum = mathQuestions.at(n).at(3);
                    correctAns = mathQuestions.at(n).at(4);
                    attemptsUsed = mathQuestions.at(n).at(5);
                    cout << " " << setw(2) << right << lvlNum << " " <<
                     setw(12) << right << leftNum << " " << mathSymb <<
                     " " << rightNum << " = " << correctAns << " " << setw(4)
                     << setw(10) << attemptsUsed << endl;
                }



                cout << "---------------------------------------" << endl;
                cout << "Total Questions:    " << questionTot << endl;
                cout << "Total Correct  :    " << numAnsCrtTot << endl;
                cout << "Total Incorrect:    " << numAnsIncrTot << endl;
                cout << "Average Correct :    " << percentCrt << "%" << endl;
                cout << "Thanks for playing, " << name << "! Keep practicing your math!";

                break;
            }
            else {
                cout << "Invalid input, please try again..." << endl;
                cout << endl;
            }
        }

    }while (stop == 0);

    return 0;
}