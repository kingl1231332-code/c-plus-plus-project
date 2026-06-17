#include <iostream>
using namespace std;

class Train
{
    int no;
    string name, source, destination, time;

public:
    void input()
    {
        cout << "Enter Train Number: ";
        cin >> no;
        cin.ignore();

        cout << "Enter Train Name: ";
        getline(cin, name);

        cout << "Enter Source: ";
        getline(cin, source);

        cout << "Enter Destination: ";
        getline(cin, destination);

        cout << "Enter Train Time: ";
        getline(cin, time);
    }

 void display(){
    
        cout << "Train Number: " << no << endl;
        cout << "Train Name: " << name << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << time << endl;
    }

    int getNo()
    {
        return no;
    }
};

int main()
{
    Train t[100];
    int total = 0, choice, num;
    bool found;

    do
    {
        cout << "\n--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            t[total].input();
            total++;
            break;

        case 2:
            for (int i = 0; i < total; i++)
            {
                cout << "\nTrain " << i + 1 << " Details:" << endl;
                t[i].display();
            }
            break;
			 case 3:
            cout << "Enter Train Number to Search: ";
            cin >> num;
            found = false;

            for (int i = 0; i < total; i++){
               if (t[i].getNo() == num){
			     t[i].display();
                    found = true;
                    break;
                }
            }
			  if (!found)
                cout << "Train not found!" << endl;
            break;
        case 4:
            cout << "Exiting the system. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }
  } while (choice != 4);
}
/*output

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 1
Enter Train Number: 101
Enter Train Name: okha express
Enter Source: surat
Enter Destination: mumbai
Enter Train Time: 10 AM

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 2

Train 1 Details:
Train Number: 101
Train Name: okha express
Source: surat
Destination: mumbai
Train Time: 10 AM

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 3
Enter Train Number to Search: 104
Train not found!

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 4
Exiting the system. Goodbye!

*/