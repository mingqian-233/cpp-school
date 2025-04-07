#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

class BookRecord {
private:
    std::string book_id,book_title,name;
    int year_published;
    int numberOfCopies;
    int availableCopies;

public:
    // Constructor
    BookRecord(const std::string& id, const std::string& title, const std::string& author, int year, int totalCopies, int availableCopies);

    // Destructor
    ~BookRecord() = default;

    // Getters
    std::string getBookID() const;

    // Display function
    void display() const;
};

class Borrower {
private:
    std::string borrowerID;
    std::string firstName;
    std::string lastName;
    int borrowedBooksCount;
    std::vector<std::string> borrowedBookIDs;

public:
    // Constructor
    Borrower(const std::string& id, const std::string& firstName, const std::string& lastName, int borrowedCount);

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
    void displayBorrowedBooks() const;
    void displayBorrowers() const;
    void inputInitialState(int choice);
    void inputBorrowerInfo(int choice);
};

#endif