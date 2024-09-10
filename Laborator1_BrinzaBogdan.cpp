/*#include <iostream>
#include <string>
using  namespace std;

class Book
{
    char title[], author[], isbn[];


return 0;
};



class Library
{
    
} */

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Book
{
public:
    string title;
    string author;
    string isbn;

    Book(string t, string a, string i) {  
        title = t;
        author = a;
        isbn = i;
    }
};

class Library
{
    
private:
    list<Book> books;


public:
    // metoda sa adaug o carte
    void addBook(const Book& book)
    {
        books.push_back(book);
    }

    // metoda sa scot o carte dupa isbn
    void removeBook(const string& isbn)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
        {
            if (it->isbn == isbn)
            {
                books.erase(it);
                return;
            }
        }
        cout << "The book with the ISBN: " << isbn << " NOT FOUND." << endl;
    }

    // metoda sa arat cartile
    void displayBooks() const
    {
        if (books.empty())
        {
            cout << "there are no books in the list" << endl;
            return;
        }
        for (const auto& book : books)
        {
            cout << "Title: " << book.title << endl; 
            cout <<", Author: " << book.author << endl;
            cout <<", ISBN: " << book.isbn << endl;
        }
    }
};

int main()
{
    Library lib;
    int choice;
    string title, author, isbn;

    do
    {
        cout << "\n------------- Enter a number between 0-3 -------------" << endl;
        cout << "0. ------- Exit ------- " << endl;
        cout << "1. ------- Add a book ------- " << endl;
        cout << "2. ------- Remove a book ------- " << endl;
        cout << "3. ------- Display all books ------- " << endl;
        cout << "------------- Enter a number between 0-3: -------------" << endl;

        cin >> choice;
        cin.ignore(); // ignoram newlineul

        switch (choice)
        {
            case 0:
                cout << "quitting..." << endl;
                break;
            case 1:
                cout << "enter a title for the next book: ";
                getline(cin, title);
                cout << "enter an author for the book: ";
                getline(cin, author);
                cout << "enter its isbn: ";
                getline(cin, isbn);
                lib.addBook(Book(title, author, isbn));
                cout << "the book was added to the list..." << endl;
                break;
            case 2:
                cout << "enter the book's isbn to remove from the list: ";
                getline(cin, isbn);
                lib.removeBook(isbn);
                break;
            case 3:
                cout << "displaying the list of books ->" << endl;
                lib.displayBooks();
                break;
            default:
                cout << "enter a number from 0-3, not else" << endl;
                break;
        }

    } while (choice != false);

    return 0;
}
