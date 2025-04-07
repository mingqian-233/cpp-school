#include "Library.h"
#include <fstream>
#include <sstream>
#include <limits>

// Method to load data from files
void Library::inputInitialState(int choice) {//只输入图书馆的书，不输入借书人

    if(choice==1){
        std::cout<<"从文件读取数据。请输入文件名：\n";
        std::string bookFileName;
        std::cin>>bookFileName;
        std::ifstream bookFile(bookFileName);
        if (!bookFile.is_open()) {
            throw std::runtime_error("Error: Unable to open book file.");
        }
        int bookCount;
        bookFile >> bookCount;
        //接下来读入bookCount本书的信息，每行按序输入每本书的信息如下：
        /*
        std::string book_id,book_title,name;
        int year_published;
        int numberOfCopies;
        */
       //其中book_id要大写开头，book_title不含空格，格式不对就抛出错误
       for(int i = 0; i < bookCount; ++i) {
            std::string book_id, book_title, name;
            int year_published;
            int numberOfCopies;
            bookFile >> book_id >> book_title >> name >> year_published >> numberOfCopies;
            // Check if the first character of book_id is uppercase
            if (!std::isupper(book_id[0])) {
                throw std::invalid_argument("Error: Book ID must start with an uppercase letter.");
            }
            // Check if book_title contains spaces
            if (book_title.find(' ') != std::string::npos) {
                throw std::invalid_argument("Error: Book title must not contain spaces.");
            }
            // Check if year_published is a valid integer
            if (year_published <= 0) {
                throw std::invalid_argument("Error: Year published must be a positive integer.");
            }
            // Check if numberOfCopies is a valid integer
            if (numberOfCopies <= 0) {
                throw std::invalid_argument("Error: Number of copies must be a positive integer.");
            }
            if(bookFile.fail()){
                bookFile.clear();
                bookFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Error: Invalid input format.");
            }
            
            BookRecord record(book_id, book_title, name, year_published, numberOfCopies, numberOfCopies);
            catalogue.addBookRecord(record);
        }
    } else if(choice==2){
        // Implement keyboard input logic here
    } else {
        throw std::invalid_argument("Invalid choice for input method.");
    }

    std::vector<BookRecord> bookRecords;

}