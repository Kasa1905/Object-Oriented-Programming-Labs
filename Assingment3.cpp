#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <vector>
#include <memory>
#include <type_traits>

class Publication {
public:
    std::string title;
    float price;

    Publication(std::string t, float p) : title(t), price(p) {}
    virtual ~Publication() {}
    virtual void display() const = 0;
};

class Book : public Publication {
public:
    int pageCount;

    Book(std::string t, float p, int pc) : Publication(t, p), pageCount(pc) {}
    void display() const override {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Page Count: " << pageCount << std::endl;
    }
};

class Tape : public Publication {
public:
    float playingTime;

    Tape(std::string t, float p, float pt) : Publication(t, p), playingTime(pt) {}
    void display() const override {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Playing Time: " << playingTime << " minutes" << std::endl;
    }
};

template <typename T>
T getPublicationData() {
    std::string title;
    float price;
    int pageCount;
    float playingTime;

    try {
        std::cout << "Enter " << (std::is_same<T, Book>::value ? "book" : "tape") << " title: ";
        std::getline(std::cin, title);

        std::cout << "Enter " << (std::is_same<T, Book>::value ? "book" : "tape") << " price: ";
        std::cin >> price;
        if (std::cin.fail() || price < 0) throw std::runtime_error("Invalid price");

        if (std::is_same<T, Book>::value) {
            std::cout << "Enter page count: ";
            std::cin >> pageCount;
            if (std::cin.fail() || pageCount < 0) throw std::runtime_error("Invalid page count");
            std::cin.ignore();
            return T(title, price, pageCount);
        } else {
            std::cout << "Enter playing time (in minutes): ";
            std::cin >> playingTime;
            if (std::cin.fail() || playingTime < 0) throw std::runtime_error("Invalid playing time");
            std::cin.ignore();
            return T(title, price, playingTime);
        }
    } catch (const std::runtime_error& e) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Error: " << e.what() << std::endl;
        if (std::is_same<T, Book>::value) {
            return T("Invalid", 0.0f, 0);
        } else {
            return T("Invalid", 0.0f, 0.0f);
        }
    }
}

int main() {
    std::vector<std::unique_ptr<Publication>> publications;

    std::cout << "Enter data for a book:" << std::endl;
    publications.push_back(std::make_unique<Book>(getPublicationData<Book>()));

    std::cout << "\nEnter data for a tape:" << std::endl;
    publications.push_back(std::make_unique<Tape>(getPublicationData<Tape>()));

    for (const auto& publication : publications) {
        publication->display();
        std::cout << std::endl;
    }

    return 0;
}