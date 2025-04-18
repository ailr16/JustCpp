#ifndef LIBRARY_SYSTEM_HPP
#define LIBRARY_SYSTEM_HPP

#include <iostream>
#include <list>

namespace Library {
    class Book{
        private:
            std::string title;
            std::string author;
            int isbn;

        public:
            Book(std::string title, std::string author, int isbn);
            std::string getTitle(void);
            std::string getAuthor(void);
            int getIsbn(void);
            friend std::ostream& operator<<(std::ostream& os, const Book& book);
    };

    class Library {
        private:
            std::list<Book> books;

        public:
            int addBook(std::string title, std::string author, int isbn);
            int removeBook(void);
            void listAllBooks(void);
    };
}

namespace Utils {
    void input(void);
    void display(void);
}

#endif