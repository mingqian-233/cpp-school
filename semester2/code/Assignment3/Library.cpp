#include "Library.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "Library.h"

void handleInputError(std::istream& inputStream, const std::string& errorMessage) {
    if (inputStream.fail()) {
        inputStream.clear();
        inputStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument(errorMessage);
    }
}

// 输出 x: y的格式
void outputKeyValue(const std::string& key, const std::string& value) {
    std::cout << key << ": " << value << std::endl;
}
void outputKeyValue(const std::string& key, const std::vector<std::string>& value) {
    std::cout << key << ": ";
    for (const auto& v : value) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}
void outputKeyValue(const std::string& key, int value) {
    std::cout << key << ": " << value << std::endl;
}

// BookRecord 类实现
BookRecord::BookRecord(const std::string& id, const std::string& title, const std::string& author, int year, int totalCopies, int availableCopies)
    : book_id(id), book_title(title), name(author), year_published(year), numberOfCopies(totalCopies), availableCopies(availableCopies) {}

std::string BookRecord::getBookID() const {
    // 返回书籍 ID
    return book_id;
}

void BookRecord::display() const {
    outputKeyValue("Book ID", book_id);
    outputKeyValue("Book Title", book_title);
    outputKeyValue("Author", name);
    outputKeyValue("Year Published", std::to_string(year_published));
    outputKeyValue("Total number of Copies", std::to_string(numberOfCopies));
    outputKeyValue("Number available for loan", std::to_string(availableCopies));
    // 显示书籍信息
}

// Borrower 类实现
Borrower::Borrower(const int id, const std::string& borrowerName, int borrowedCount, const std::vector<std::string>& borrowedBookIDs)
    : borrowerID(id), borrowerName(borrowerName), borrowedBooksCount(borrowedCount), borrowedBookIDs(borrowedBookIDs) {}

void Borrower::display() const {
    outputKeyValue("Borrower ID", borrowerID);
    outputKeyValue("Name", borrowerName);
    outputKeyValue("Number of loaned books", std::to_string(borrowedBooksCount));
    outputKeyValue("IDs of books on loan", borrowedBookIDs);
}

// Catalogue 类实现
Catalogue::Catalogue(const std::vector<BookRecord>& records)
    : bookRecords(records), totalBookRecords(records.size()) {}

void Catalogue::addBookRecord(const BookRecord& record) {
    bookRecords.push_back(record);
    totalBookRecords++;
}

void Catalogue::display() const {
    outputKeyValue("Total number of books in the catalogue", totalBookRecords);
    int i = 0;
    for (const auto& record : bookRecords) {
        std::cout << "Book " << i++ << ":" << std::endl;
        std::cout << "-------------------------" << std::endl;
        record.display();  // 显示每本书籍的信息
    }
}

// Library 类实现
Library::Library()
    : totalBorrowedBooks(0), totalBorrowers(0), catalogue(std::vector<BookRecord>()) {}

void Library::display() const {
    // 显示借阅者总数和详细信息
    outputKeyValue("Total number of books on loan", totalBorrowedBooks);
    catalogue.display();  // 显示书籍目录

    for (int i = 0; i < totalBorrowers; ++i) {
        std::cout << "Borrower " << i  << ":" << std::endl;
        std::cout << "-------------------------" << std::endl;
        borrowers[i].display();  // 显示每个借阅者的信息
    }
    std::cout << "-------------------------" << std::endl;
    std::cout << "End of the Library Management System" << std::endl;
}

void Library::input(int choice) {
    std::istream* inputStream = nullptr;  // 通用输入流指针
    std::ifstream fileStream;

    if (choice == 1) {
        // 从文件读取
        std::cout << "Read data from file. \n";
        std::string bookFileName = "books.txt";  // 默认文件名
        fileStream.open(bookFileName);
        if (!fileStream.is_open()) {
            throw std::runtime_error("Error: Unable to open book file.");
        }
        inputStream = &fileStream;  // 指向文件流
    } else if (choice == 2) {
        // 从键盘读取
        std::cout << "Read data from keyboard. Please enter the number of books:\n";
        inputStream = &std::cin;  // 指向标准输入流
    } else {
        throw std::invalid_argument("Invalid choice for input method.");
    }

    // 书籍
    int bookCount;
    *inputStream >> bookCount;
    handleInputError(*inputStream, "Error: Invalid input for number of books.");
    // 读取每本书的信息
    for (int i = 0; i < bookCount; ++i) {
        std::string book_id, book_title, firstName,lastName;
        int year_published, numberOfCopies;

        *inputStream >> book_id;

        if (!std::isupper(book_id[0])) {  // 检查书籍 ID 是否以大写字母开头
            throw std::invalid_argument("Error: Book ID must start with an uppercase letter.");
        }

        *inputStream >> book_title;

        *inputStream >> firstName >> lastName;
        *inputStream >> year_published;
        if (year_published <= 1000 || year_published > 2999) {  // 检查年份是否合理
            throw std::invalid_argument("Error: Year published must be a reasonable number.");
        }

        handleInputError(*inputStream, "Error: Invalid input format for year published.");

        *inputStream >> numberOfCopies;
        if (numberOfCopies <= 0) {
            throw std::invalid_argument("Error: Number of copies must be a positive integer.");
        }

        handleInputError(*inputStream, "Error: Invalid input format for number of copies.");

        // 创建书籍记录并添加到目录
        BookRecord record(book_id, book_title, firstName+' '+lastName, year_published, numberOfCopies, numberOfCopies);
        catalogue.addBookRecord(record);
    }

    // 借阅者
    int borrowerCount;
    *inputStream >> borrowerCount;
    handleInputError(*inputStream, "Error: Invalid input for number of borrowers.");
    // 读取每个借阅者的信息
    for (int i = 0; i < borrowerCount; ++i) {
        int borrowerID;
        std::string firstName, lastName;
        int borrowedBooksCount;
        std::vector<std::string> borrowedBookIDs;

        *inputStream >> borrowerID;
        handleInputError(*inputStream, "Error: Invalid input format for borrower ID.");
        if (borrowerID > 99999 || borrowerID < 10000) {  // 检查借阅者 ID 是否为五位数
            throw std::invalid_argument("Error: Borrower ID must start with a digit.");
        }
        *inputStream >> firstName >> lastName;
        *inputStream >> borrowedBooksCount;
        handleInputError(*inputStream, "Error: Invalid input format for number of borrowed books.");
        if(borrowedBooksCount < 0) {  
            throw std::invalid_argument("Error: Number of borrowed books must be a non-negative integer.");
        }
        if(borrowedBooksCount > 5) {  
            throw std::invalid_argument("Error: Number of borrowed books must be less than or equal to 5.");
        }
        for (int j = 0; j < borrowedBooksCount; ++j) {
            std::string bookID;
            *inputStream >> bookID;
            handleInputError(*inputStream, "Error: Invalid input format for borrowed book ID.");
            if (bookID.length() != 4 || !std::isupper(bookID[0])) {  // 检查书籍 ID 是否为四位且以大写字母开头
                throw std::invalid_argument("Error: Book ID must be four characters long and start with an uppercase letter.");
            }
            borrowedBookIDs.push_back(bookID);
        }
        // 创建借阅者记录并添加到列表
        Borrower borrower(borrowerID, firstName + ' ' + lastName, borrowedBooksCount, borrowedBookIDs);
        borrowers.push_back(borrower);
        totalBorrowers++;
        totalBorrowedBooks += borrowedBooksCount;  // 更新借阅的书籍总数

    }
    if (fileStream.is_open()) {
        fileStream.close();
    }
}
