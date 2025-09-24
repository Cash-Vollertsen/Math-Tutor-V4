 /********************************
    Program.......:MathTutorV1
    Programmers...:Cash Vollertsen and
    Date..........:9/22/25
    Github Repo...:
    Description...:





    **********************************************/

#include <chrono>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;


int main() {
    cout << "************************************************************************************" << endl;
    cout << "*                         Welcome to Silly Simple Math Tutor V1                    *" << endl;
    cout << "************************************************************************************" << endl;

    cout << "Fun Math Facts" << endl;
    cout << "   -Math wasn't created at any one time but developed over thousands of years." << endl;
    cout << "   -""Forty"" is the only number that is spelt with letters arranged in alphabetical order." << endl;
    cout << "   -Every odd number has an ""e"" in it." << endl;

    string name;

    cout << "Hey this is your Simple Silly Math Tutor, What's your name." << endl;
    getline(cin, name );
    cout << "Hello " << name << ", welcome to your math tutor." << endl;
    cout << "Let's begin" << endl << endl;

    double userans;
    double ans;
    int rando2 = rand() % 10 + 1;
    int rando1= rand() % 10 + 1;
    int mathvar = rand() % 4 + 1;



    switch (mathvar) {
        case 1:
          ans = rando1 + rando2;
          cout << "Please solve this math expression " << rando1 << " + " << rando2 << endl;
                break;

        case 2:
            if (rando1 < rando2) {
                ans = rando2 - rando1;
                cout << "Please solve this math expression " << rando2 << " - " << rando1 << endl;
            }
        else if (rando2 < rando1) {
            ans = rando1 - rando2;
            cout << "Please solve this math expression " << rando1 << " - " << rando2 << endl;
        }
                break;

        case 3:
            ans = rando1 * rando2;
        cout << "Please solve this math expression " << rando1 << " * " << rando2 << endl;
                break;

        case 4:
            ans = rando1 / rando2;
        cout << "Please solve this math expression " << rando1 << " / " << rando2 << endl;
                break;
    }
    cin >> userans;

    if (userans == ans) {
        cout << "Good work answering the problem. You have a bright future ahead of you." << endl;
    }
    else if (userans != ans)
        cout << "Looks like you need to look at the problem again." << endl;


    cout << endl;
    cout << "Thank you for playing the game!" << endl;





    return 0;
}
