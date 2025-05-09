#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct PersonalRecord {
    std::string name;
    std::string dob;
    std::string phone;

    bool operator<(const PersonalRecord& other) const {
        return name < other.name;
    }
};

void inputRecords(std::vector<PersonalRecord>& records, int n) {
    for (int i = 0; i < n; i++) {
        PersonalRecord record;
        std::cout << "Enter name: ";
        std::cin >> record.name;
        std::cout << "Enter DOB (YYYY-MM-DD): ";
        std::cin >> record.dob;
        std::cout << "Enter telephone number: ";
        std::cin >> record.phone;
        records.push_back(record);
    }
}

void displayRecords(const std::vector<PersonalRecord>& records) {
    for (size_t i = 0; i < records.size(); ++i) {
        std::cout << "Name: " << records[i].name 
                  << ", DOB: " << records[i].dob 
                  << ", Phone: " << records[i].phone << std::endl;
    }
}

int main() {
    std::vector<PersonalRecord> records;
    int n;

    std::cout << "Enter number of records: ";
    std::cin >> n;
    inputRecords(records, n);

    std::sort(records.begin(), records.end());

    std::cout << "\nSorted Records:\n";
    displayRecords(records);

    std::string searchName;
    std::cout << "\nEnter name to search: ";
    std::cin >> searchName;

    for (size_t i = 0; i < records.size(); ++i) {
        if (records[i].name == searchName) {
            std::cout << "Record found:\n";
            std::cout << "Name: " << records[i].name 
                      << ", DOB: " << records[i].dob 
                      << ", Phone: " << records[i].phone << std::endl;
            return 0;
        }
    }

    std::cout << "Record not found." << std::endl;
    return 0;
}
