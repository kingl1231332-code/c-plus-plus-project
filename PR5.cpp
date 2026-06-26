#include <iostream>
using namespace std;

class LibraryItem
{
    private:
    char title[20];

    public:
    void setTitle(){
	    cout << "Enter Title: ";
        cin >> title;
    }

    char* getTitle(){
	    return title;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;
};

class Book : public LibraryItem
{
    public:
    void checkOut(){
	  cout << "Book Checked Out\n";
    }
    void returnItem(){
	 cout << "Book Returned\n";
    }
    void displayDetails(){
	 cout << "Book: " << getTitle() << endl;
    }
};

class DVD : public LibraryItem
{
    public:
    void checkOut(){
	    cout << "DVD Checked Out\n";
    }

    void returnItem(){
	    cout << "DVD Returned\n";
    }

    void displayDetails(){
	  cout << "DVD: " << getTitle() << endl;
    }
};

int main()
{
    LibraryItem *item[2];

    item[0] = new Book();
    item[1] = new DVD();

    item[0]->setTitle();
    item[1]->setTitle();

    int ch;

    do{
	    cout << "\n1.Display\n2.CheckOut\n3.Return\n4.Exit\n";
        cout << "Enter Choice: ";
        cin >> ch;

        switch (ch){
		case 1:
            item[0]->displayDetails();
            item[1]->displayDetails();
            break;

        case 2:
            item[0]->checkOut();
            item[1]->checkOut();
            break;

        case 3:
            item[0]->returnItem();
            item[1]->returnItem();
            break;
        }
    } while (ch != 4);

    delete item[0];
    delete item[1];
}
/*outout
Enter Title: animalhistory
Enter Title: mahabharat

1.Display
2.CheckOut
3.Return
4.Exit
Enter Choice: 1
Book: animalhistory
DVD: mahabharat

1.Display
2.CheckOut
3.Return
4.Exit
Enter Choice: 2
Book Checked Out
DVD Checked Out

1.Display
2.CheckOut
3.Return
4.Exit
*/