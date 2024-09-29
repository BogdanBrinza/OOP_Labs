#include <iostream>
#include <string>
#include <list>

using namespace std;

class DerivataDeLaBaza : public DeBaza {
public:
    DerivataDeLaBaza() {
        cout << "DerivataDeLaBaza class constructor called." << endl;
    }

    ~DerivataDeLaBaza() {
        cout << "DerivataDeLaBaza class destructor called." << endl;
    }

    void DerivataDeLaBazaFunction() {
        cout << "Function in DerivataDeLaBaza class." << endl;
    }
};

/*  Inheritance exemplu


// clasa de baza
class Vehicle {
    public: 
    string brand = "BMW";
    void sunet() {

    cout << "aici trb sa se scoata sunet" << endl;
}

};
//clasa derivata

class Car: public Vehicul {
    public:
    string model = "M Label" << endl;

};

int main()
{
    Car myCar;
    myCar.sunet();
    cout << myCar.brand + " " + myCar.model;
    return 0;

} */



// 2. cream clasa book
class Book {
public:
    string title;
    string author;
    string isbn;

    // constructor cu parametri 
    Book(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
    }

    // destructor care afiseaza actiunea facuta
    ~Book() {
        cout << "Book object has been destroyed: " << title << endl;
    }
};

// 3. Implementarea claselor friend și funcțiilor friend
class Library;

class FriendClass {
public:
    void showLibraryBooks(Library& lib); // Declarație funcție friend
};

class Library {
private:
    list<Book> books;

public:
    // Permitem accesul clasei FriendClass la datele private ale clasei Library
    friend class FriendClass;

    // metoda sa adaugam carte 
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // metoda pentru scoatere a cartii dupa isbn
    void removeBook(const string& isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->isbn == isbn) {
                books.erase(it);
                return;
            }
        }
        cout << "The book with the ISBN: " << isbn << " NOT FOUND." << endl;
    }

    // metoda de a afisa cartile
    void displayBooks() const {
        if (books.empty()) {
            cout << "There are no books in the list." << endl;
            return;
        }
        for (const auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn << endl;
        }
    }
};

// implementare functie friend care poate accesa date private ale clasei library
void FriendClass::showLibraryBooks(Library& lib) {
    cout << "Accessing Library's private data using a friend class:" << endl;
    lib.displayBooks();
}

int main() {
    // mostenire si oridine apel de constructor/destructor 
    cout << "Inheritance demonstration:" << endl;
    DerivataDeLaBaza d; // constructorii apelati in ordinea mostenirii, DeBaza si dupa DerivataDeLaBaza

    // utilizarea claselor si functiei friend
    Library lib;
    FriendClass fc;

    int choice;
    string title, author, isbn;

    do {
        cout << "\n------------- Enter a number between 0-4 -------------" << endl;
        cout << "0. ------- Exit ------- " << endl;
        cout << "1. ------- Add a book ------- " << endl;
        cout << "2. ------- Remove a book ------- " << endl;
        cout << "3. ------- Display all books ------- " << endl;
        cout << "4. ------- Display books using a friend class ------- " << endl;
        cout << "------------- Enter a number between 0-4: -------------" << endl;

        cin >> choice;
        cin.ignore(); // ignoram newline-u

        switch (choice) {
            case 0:
                cout << "Quitting..." << endl;
                break;
            case 1:
                cout << "Enter a title for the next book: ";
                getline(cin, title);
                cout << "Enter an author for the book: ";
                getline(cin, author);
                cout << "Enter its ISBN: ";
                getline(cin, isbn);
                lib.addBook(Book(title, author, isbn));
                cout << "The book was added to the list..." << endl;
                break;
            case 2:
cout << "Enter the book's ISBN to remove from the list: ";
                getline(cin, isbn);
                lib.removeBook(isbn);
                break;
            case 3:
                cout << "Displaying the list of books ->" << endl;
                lib.displayBooks();
                break;
            case 4:
                cout << "Displaying books using a friend class ->" << endl;
                fc.showLibraryBooks(lib);
                break;
            default:
                cout << "Enter a number from 0-4, not else." << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
