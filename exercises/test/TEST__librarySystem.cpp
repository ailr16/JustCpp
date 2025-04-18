#include <gtest/gtest.h>
#include "librarySystem.hpp"

TEST( LibrarySystemTest, instantiatingBookGettersSetters ){
    Library::Book testBook("book1", "author1", 16);

    ASSERT_STREQ( "book1", testBook.getTitle().c_str() );
    ASSERT_STREQ( "author1", testBook.getAuthor().c_str() );
    ASSERT_EQ(16, testBook.getIsbn());
}

TEST( LibrarySystemTest, addBookAndPrint ){
    std::string consoleOutput;
    Library::Library libTest;

    ASSERT_EQ(0, libTest.addBook("book1", "author1", 1));
    testing::internal::CaptureStdout();
    libTest.listAllBooks();
    consoleOutput = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(consoleOutput.c_str(), "Title: book1, Author: author1, ISBN: 1\n");
}

TEST( LibrarySystemTest, adding3Books ){
    std::string consoleOutput;
    Library::Library libTest;

    ASSERT_EQ(0, libTest.addBook("book1", "author1", 1));
    ASSERT_EQ(0, libTest.addBook("book2", "author2", 2));
    ASSERT_EQ(0, libTest.addBook("book3", "author3", 3));
    testing::internal::CaptureStdout();
    libTest.listAllBooks();
    consoleOutput = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(consoleOutput.c_str(),
                 "Title: book1, Author: author1, ISBN: 1\nTitle: book2, Author: author2, ISBN: 2\nTitle: book3, Author: author3, ISBN: 3\n");
}

TEST( LibrarySystemTest, removeBook ){
    std::string consoleOutput;
    Library::Library libTest;

    ASSERT_EQ(0, libTest.addBook("book1", "author1", 1));
    testing::internal::CaptureStdout();
    libTest.listAllBooks();
    consoleOutput = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(consoleOutput.c_str(), "Title: book1, Author: author1, ISBN: 1\n");

    ASSERT_EQ(0, libTest.removeBook());
    ASSERT_EQ(1, libTest.removeBook());
}

TEST( LibrarySystemTest, removeBookFrom3BooksList ){
    std::string consoleOutput;
    Library::Library libTest;

    ASSERT_EQ(0, libTest.addBook("book1", "author1", 1));
    ASSERT_EQ(0, libTest.addBook("book2", "author2", 2));
    ASSERT_EQ(0, libTest.addBook("book3", "author3", 3));
    ASSERT_EQ(0, libTest.removeBook());
    testing::internal::CaptureStdout();
    libTest.listAllBooks();
    consoleOutput = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(consoleOutput.c_str(),
                 "Title: book1, Author: author1, ISBN: 1\nTitle: book2, Author: author2, ISBN: 2\n");
}