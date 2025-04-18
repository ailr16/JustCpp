#include "librarySystem.hpp"

namespace Library {
    Book::Book(std::string title, std::string author, int isbn) :
        title(title),
        author(author),
        isbn(isbn)
    {}

    std::string Book::getTitle(void){
        return title;
    }

    std::string Book::getAuthor(void){
        return author;
    }

    int Book::getIsbn(void){
        return isbn;
    }

    std::ostream& operator<<(std::ostream& os, const Book& book){
        os << "Title: " << book.title
           << ", Author: " << book.author
           << ", ISBN: "  << book.isbn;

        return os;
    }

    int Library::addBook(std::string title, std::string author, int isbn){
        try{
            books.push_back(Book(title, author, isbn));
            return 0;
        }
        catch(const std::exception& e){
            std::cerr << "Error adding a book: " << e.what() << std::endl;
            return 1;
        }
    }
    
    int Library::removeBook(void){
        return 0;
    }
    void Library::listAllBooks(void){
        for(const auto& book : books){
            std::cout << book << std::endl;
        }
    }
}

namespace Utils {
    void input(void){

    }

    void display(void){

    }
}
