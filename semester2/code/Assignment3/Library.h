#ifndef LIBRARY_H
#define LIBRARY_H

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


class BookRecord {
private:
    std::string book_id, book_title, name;
    int year_published;
    int numberOfCopies;
    int availableCopies;

public:
    BookRecord(const std::string& id, const std::string& title, const std::string& author, int year, int totalCopies, int availableCopies);

    ~BookRecord() = default;

    std::string getBookID() const;

    void display() const;
};

class Borrower {
private:
    int borrowerID;
    std::string borrowerName;
    int borrowedBooksCount;
    std::vector<std::string> borrowedBookIDs;

public:
    // Constructor
    Borrower(int id, const std::string& borrowerName, int borrowedCount, const std::vector<std::string>& borrowedBookIDs);

    // Destructor
    ~Borrower() = default;

    // Display function
    void display() const;
};

class Catalogue {
private:
    int totalBookRecords;
    std::vector<BookRecord> bookRecords;

public:
    // Constructor
    Catalogue(const std::vector<BookRecord>& records);

    // Destructor
    ~Catalogue() = default;

    // Display function
    void addBookRecord(const BookRecord& record);
    void display() const;
};

class Library {
private:
    int totalBorrowedBooks;
    int totalBorrowers;
    Catalogue catalogue;
    std::vector<Borrower> borrowers;

public:
    // Constructor
    Library();
    // Destructor
    ~Library() = default;

    // Display functions
    void display() const;
    void input(int choice = 1);

};
#endif