#include <iostream>
#include <cstring>

using namespace std;

const int row = 5;
const int col = 2;



struct election
{
    string candidate;
    int votes;
    double voteper;
};

election   winner;

void calcPer_winner(election ele[row][col]);
void printResults(election ele[row][col]);

int main()
{
    election ele[row][col];


    for (int i = 0; i < row; i++)
    {


        for (int j = 0; j < col; j++)
        {

            cout << "Please Enter the name of the candidate: ";
            cin >> ele[i][j].candidate;
            cout << endl;

        }
    }

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {

            cout << "Please Enter the number of votes that " << ele[i][j].candidate << " received: ";
            cin >> ele[i][j].votes;
            cout << endl;
        }
    }

    calcPer_winner(ele);
    printResults(ele);



    return 0;
}

void calcPer_winner(election ele[row][col])
{
    int totalVotes = 0;


    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            totalVotes = totalVotes + ele[i][j].votes;

        }
    }

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            ele[i][j].voteper = (((static_cast<double>(ele[i][j].votes)) / totalVotes)) * 100;

        }
    }

    winner = ele[0][0];

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            if (winner.voteper < ele[i][j + 1].voteper)
            {

                winner = ele[i][j + 1];

            }

        }
    }

}

void printResults(election ele[row][col])
{
    cout << "Candidate\tVotes Received\t\t\t%of Total Votes" << endl;

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            cout << ele[i][j].candidate << "\t\t\t" << ele[i][j].votes << "\t\t\t" << ele[i][j].voteper << "%" << endl;

        }
    }
    cout << endl;
    cout << "The winner of the election is: " << winner.candidate;
}
