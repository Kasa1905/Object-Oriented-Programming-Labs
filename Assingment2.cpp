#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    string studentClass;
    char division;
    string dob;
    string address;
    string phoneNumber;

    static int studentCount;

public:
    // Default constructor
    Student() : rollNo(0), division('A'), dob("00-00-0000") {
        name = "No Name";
        address = "No Address";
        phoneNumber = "No Phone";
        studentCount++;
    }

    // Parameterized constructor
    Student(string name, int rollNo, string studentClass, char division, string dob, string address, string phoneNumber)
        : name(name), rollNo(rollNo), studentClass(studentClass), division(division), dob(dob), address(address), phoneNumber(phoneNumber) {
        studentCount++;
    }

    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        rollNo = other.rollNo;
        studentClass = other.studentClass;
        division = other.division;
        dob = other.dob;
        address = other.address;
        phoneNumber = other.phoneNumber;
        studentCount++;
    }

    ~Student() {
        studentCount--;
    }

    inline void setName(const string& name) { this->name = name; }
    inline void setRollNo(int rollNo) { this->rollNo = rollNo; }
    inline void setClass(const string& studentClass) { this->studentClass = studentClass; }
    inline void setDivision(char division) { this->division = division; }
    inline void setDOB(const string& dob) { this->dob = dob; }
    inline void setAddress(const string& address) { this->address = address; }
    inline void setPhoneNumber(const string& phoneNumber) { this->phoneNumber = phoneNumber; }

    static int getStudentCount() {
        return studentCount;
    }

    friend class StudentDatabase;

    friend ostream& operator<<(ostream& out, const Student& student);

    void* operator new(size_t size) {
        cout << "Allocating memory for Student object...\n";
        void* p = ::operator new(size);
        return p;
    }

    void operator delete(void* p) {
        cout << "Deallocating memory for Student object...\n";
        ::operator delete(p);
    }
};

int Student::studentCount = 0;

ostream& operator<<(ostream& out, const Student& student) {
       out << "Name: " << student.name << "\n"
              << "Roll No: " << student.rollNo << "\n"
              << "Class: " << student.studentClass << "\n"
              << "Division: " << student.division << "\n"
              << "Date of Birth: " << student.dob << "\n"
              << "Address: " << student.address << "\n"
              << "Phone Number: " << student.phoneNumber << "\n";
       return out;
}

class StudentDatabase {
public:
    static void displayStudentInfo(const Student& student) {
        cout << student;
    }

    static void createStudent() {
        try {
            Student* s = new Student("Kaushik Sambe", 31, "SE", 'D', "19-03-2005", "Pimpri", "0909090909");
            displayStudentInfo(*s);
            delete s;
        } catch (bad_alloc& ba) {
            cerr << "Bad allocation caught: " << ba.what() << endl;
        }
    }
};

int main() {
    Student s1;
    cout << "Default Student:\n";
    StudentDatabase::displayStudentInfo(s1);

    cout << "\nCreating a new student dynamically...\n";
    StudentDatabase::createStudent();

    cout << "\nTotal Students: " << Student::getStudentCount() << endl;

    return 0;
}