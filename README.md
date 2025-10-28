# Math-Tutor-V4
A fun little C++ console program that greets the user, then goes into a game where you answer math questions and level up or down, while giving you a summary report at the end. 

## Features
- Displays some funny math jokes with ASCII art.
- Takes in the user's name and greets them by name
- Generates a random math question with random numbers and operator. 
- Provides feedback on whether the answer is correct.
- Based on correct answer you level up or down.
- Gives the options on whether you want to continue or end you game.
- Give you a summary report at the end. 

## Console Output:
```
Example of continuing game: 
********************************************************************
                                  ___
                   |V| _ _|_|_     |    _|_ _  __
                   | |(_| |_| |    | |_| |_(_) |
********************************************************************
*                 Welcome to the Simple Math Tutor                 *
********************************************************************

Math Jokes:
   * Why is six afraid of seven? Because seven eight nine!
   * What did zero say to eight? 'Nice belt!'
   * Why was the math book so sad? Because it had too many problems!

********************************************************************

What is your name? John

Welcome,  John, to the Simple Math Tutor!
[Level 1]
6 / 3
2

You got it correct!

[Level 1]
24 / 8
3

You got it correct!

[Level 1]
2 * 2
4

You got it correct!

Leveling up! The Levels will be a smidge harder.
The new range of numbers is 1-20

Do you want to continue (y=yes | n=no)?n

---------------------------------------
            Summary Report
---------------------------------------
Level          Question        Attempts
_______ _____________________ _________
  1            6 / 3 = 2          3
  1           24 / 8 = 3          3
  1            2 * 2 = 4          3
---------------------------------------
Total Questions:    3
Total Correct  :    3
Total Incorrect:    0
Average Correct :    100%
Thanks for playing,  John! Keep practicing your math!
Process finished with exit code 0

```
```

Example of ending game:

What is your name? GameUser

Hello,  GameUser! Welcome to the Silly Simple Math Tutor!

Level 1 GameUser What does 2+6 =
8

 Congrats! That was correct
Do you want to contine you (y=yes | n=no)?no

Never stop learning

Process finished with exit code 0
```
```

Invalid input example: 

What is your name? GameUser

Hello,  GameUser! Welcome to the Silly Simple Math Tutor!

Level 1 GameUser What does 5-3 =
2

 Congrats! That was correct
Do you want to contine you (y=yes | n=no)?lkjasdf

Invalid input, please enter (y or n).

Do you want to contine you (y=yes | n=no)?

```
## Maintainers
- [@Cash-Vollersten](https://github.com/Cash-Vollertsen/Math-Tutor-V4) Cash Vollersten
- [@BreckenSchwartz](https://github.com/BreckenSchwartz) Brecken Schwartz
