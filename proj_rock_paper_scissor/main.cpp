#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

typedef enum
{
    ROCK,
    PAPER,
    SCISSOR,
    MAX_NUM
} shape;

typedef struct
{
    shape Shape;
    char* string;
} mapShapeToString;

mapShapeToString lookupTbl[] =
{
    { ROCK, "rock" },
    { PAPER, "paper" },
    { SCISSOR, "scissor" },
};

int main(int argc, char* argv[])
{
    shape userChoice = MAX_NUM;
    int input;
    do {
        // Ask user to pick the rock, paper, or scissor
        cout << "Welcome! Please choose among\n[0] Rock\n[1] Paper\n[2] Scissor\n";
        cout << "Your choice: ";
        cin >> input;
        userChoice = (shape)input;
    } while( MAX_NUM == userChoice );

    // Computer generates a random number between 0 and 2
    shape computerChoice = static_cast<shape>(rand() % (MAX_NUM));

    // Print the outcome
    bool foundUserChoice = false;
    bool foundCompChoice = false;
    for( int cnt = 0; ( cnt < MAX_NUM ); cnt++ )
    {
        if( ( lookupTbl[cnt].Shape == userChoice ) && ( !foundUserChoice ) )
        {
            cout << "User chooses: " << lookupTbl[cnt].string << "\n";
            foundUserChoice = true;
        }

        if( ( lookupTbl[cnt].Shape == computerChoice ) && ( !foundCompChoice ) )
        {
            cout << "Computer chooses: " << lookupTbl[cnt].string << "\n";
            foundCompChoice = true;
        }
    }

    // Compare the result
    // Find the bigger number between userChoice and computerChoice
    // if the delta is 1, then the bigger number wins
    // else if the delta is 2, then it is rock vs scissor and larger number lost
    int delta = static_cast<int>(abs(userChoice - computerChoice));
    cout << delta << "\n";

    int largerNum = static_cast<int>(max(userChoice, computerChoice));
    char* largerChar;
    memcpy( largerChar, lookupTbl[largerNum].string, strlen(lookupTbl[largerNum].string) );

    int smallerNum = static_cast<int>(max(userChoice, computerChoice));
    char* smallerChar;
    memcpy( smallerChar, lookupTbl[smallerNum].string, strlen(lookupTbl[smallerNum].string) );

    if( 1 == delta )
    {
        cout << "The winner is " << largerChar << "\n";
    }
    else if( 2 == delta )
    {
        cout << "The winner is " << smallerChar << "\n";
    }
    else if( 0 == delta )
    {
        cout << "Both computer and user choose the same shape! It is a tie!\n";
    }

    return 0;
}