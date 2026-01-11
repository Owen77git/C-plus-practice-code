// File: student_manager.cpp (45 lines)
#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string name;
    int id;
    float gpa;
public:
    Student(std::string n, int i, float g) : name(n), id(i), gpa(g) {}
    
    void display() const {
        std::cout << "ID: " << id << ", Name: " << name 
                  << ", GPA: " << gpa << std::endl;
    }
    
    float getGPA() const { return gpa; }
    int getID() const { return id; }
};

class StudentManager {
private:
    std::vector<Student> students;
public:
    void addStudent(const Student& s) {
        students.push_back(s);
    }
    
    void displayAll() const {
        std::cout << "\n=== Student List ===\n";
        for (const auto& student : students) {
            student.display();
        }
    }
    
    Student* findStudent(int id) {
        for (auto& student : students) {
            if (student.getID() == id) {
                return &student;
            }
        }
        return nullptr;
    }
};

int main() {
    StudentManager manager;
    
    manager.addStudent(Student("Alice Johnson", 1001, 3.8));
    manager.addStudent(Student("Bob Smith", 1002, 3.5));
    manager.addStudent(Student("Charlie Brown", 1003, 3.9));
    
    manager.displayAll();
    
    std::cout << "\nSearching for student ID 1002:\n";
    Student* found = manager.findStudent(1002);
    if (found) {
        std::cout << "Found: ";
        found->display();
    }
    
    return 0;
}
