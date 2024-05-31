#pragma once
#include "Classes.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

// Singleton FileManager
class FileManager {
private:
    static FileManager* instance;
    FileManager() {}
public:
    FileManager(const FileManager&) = delete;
    FileManager& operator=(const FileManager&) = delete;

    static FileManager* getInstance() {
        if (instance == nullptr) {
            instance = new FileManager();
        }
        return instance;
    }

    std::ifstream openInputFile(const std::string& fileName) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            throw std::runtime_error("Unable to open input file: " + fileName);
        }
        return file;
    }

    void closeFile(std::ifstream& file) {
        if (file.is_open()) {
            file.close();
        }
    }
};

FileManager* FileManager::instance = nullptr;

// Builder for Student
class StudentBuilder {
private:
    Initials initials;
    University university;
    Date date;
    Personal personal;
    Subjects subjects;
    Grades grades;
public:
    StudentBuilder& setInitials(const Initials& initials_) {
        initials = initials_;
        return *this;
    }

    StudentBuilder& setUniversity(const University& university_) {
        university = university_;
        return *this;
    }

    StudentBuilder& setDate(const Date& date_) {
        date = date_;
        return *this;
    }

    StudentBuilder& setPersonal(const Personal& personal_) {
        personal = personal_;
        return *this;
    }

    StudentBuilder& setSubjects(const Subjects& subjects_) {
        subjects = subjects_;
        return *this;
    }

    StudentBuilder& setGrades(const Grades& grades_) {
        grades = grades_;
        return *this;
    }

    Students build() {
        return Students(initials, university, date, personal, subjects, grades);
    }
};

// Builder for Teacher
class TeacherBuilder {
private:
    Initials initials;
    Date date;
    TeacherUniversity teacherUniversity;
    TeacherPersonal teacherPersonal;
public:
    TeacherBuilder& setInitials(const Initials& initials_) {
        initials = initials_;
        return *this;
    }

    TeacherBuilder& setDate(const Date& date_) {
        date = date_;
        return *this;
    }

    TeacherBuilder& setTeacherUniversity(const TeacherUniversity& teacherUniversity_) {
        teacherUniversity = teacherUniversity_;
        return *this;
    }

    TeacherBuilder& setTeacherPersonal(const TeacherPersonal& teacherPersonal_) {
        teacherPersonal = teacherPersonal_;
        return *this;
    }

    Teachers build() {
        return Teachers(initials, date, teacherUniversity, teacherPersonal);
    }
};

// Factory
class Factory {
public:
    static Students createStudent(const Initials& initials, const University& university, const Date& date,
        const Personal& personal, const Subjects& subjects, const Grades& grades) {
        return Students(initials, university, date, personal, subjects, grades);
    }

    static Teachers createTeacher(const Initials& initials, const Date& date,
        const TeacherUniversity& teacherUniversity, const TeacherPersonal& teacherPersonal) {
        return Teachers(initials, date, teacherUniversity, teacherPersonal);
    }
};

// Facade
class UniversityFacade {
public:
    void readStudentsFromFile(const std::string& fileName, Students* students, int& size) {
        std::ifstream file = FileManager::getInstance()->openInputFile(fileName);
        if (!file) {
            throw std::runtime_error("Unable to open file");
        }

        int studentCount;
        file >> studentCount;

        if (studentCount > size) {
            throw std::runtime_error("Not enough space in the array to read all students");
        }

        for (int i = 0; i < studentCount; ++i) {
            Initials initials;
            University university;
            Date date;
            Personal personal;
            Subjects subjects;
            Grades grades;

            file >> initials.Lastname >> initials.Name >> initials.Gender
                >> date.BirthYear >> date.Age
                >> university.Faculty >> university.Kafedra >> university.Group >> university.Course
                >> personal.HasChildren >> personal.HasScholarship >> personal.ScholarshipAmount
                >> subjects.Subject1 >> subjects.Grade1_1 >> subjects.Grade1_2
                >> subjects.Subject2 >> subjects.Grade2_1 >> subjects.Grade2_2
                >> subjects.Subject3 >> subjects.Grade3_1 >> subjects.Grade3_2
                >> subjects.Subject4 >> subjects.Grade4_1 >> subjects.Grade4_2
                >> subjects.Subject5 >> subjects.Grade5_1 >> subjects.Grade5_2
                >> grades.ExamGrade1 >> grades.ExamGrade2 >> grades.ExamGrade3 >> grades.ExamGrade4
                >> grades.ExamGrade5 >> grades.ExamGrade6 >> grades.ExamGrade7 >> grades.ExamGrade8
                >> grades.DuplomTheme;

            students[i] = Factory::createStudent(initials, university, date, personal, subjects, grades);
        }

        size = studentCount;
        FileManager::getInstance()->closeFile(file);
    }

    Students buildStudent(StudentBuilder& builder) {
        return builder.build();
    }

    Teachers buildTeacher(TeacherBuilder& builder) {
        return builder.build();
    }
};

// Singleton Demo
void singletonDemo() {
    const std::string fileName = "Students.txt";
    std::ifstream file = FileManager::getInstance()->openInputFile(fileName);

    int n;
    file >> n;
    Students* students = new Students[n];

    for (int i = 0; i < n; ++i) {
        Initials initials;
        University university;
        Date date;
        Personal personal;
        Subjects subjects;
        Grades grades;

        file >> initials.Lastname >> initials.Name >> initials.Gender
            >> date.BirthYear >> date.Age
            >> university.Faculty >> university.Kafedra >> university.Group >> university.Course
            >> personal.HasChildren >> personal.HasScholarship >> personal.ScholarshipAmount
            >> subjects.Subject1 >> subjects.Grade1_1 >> subjects.Grade1_2
            >> subjects.Subject2 >> subjects.Grade2_1 >> subjects.Grade2_2
            >> subjects.Subject3 >> subjects.Grade3_1 >> subjects.Grade3_2
            >> subjects.Subject4 >> subjects.Grade4_1 >> subjects.Grade4_2
            >> subjects.Subject5 >> subjects.Grade5_1 >> subjects.Grade5_2
            >> grades.ExamGrade1 >> grades.ExamGrade2 >> grades.ExamGrade3 >> grades.ExamGrade4
            >> grades.ExamGrade5 >> grades.ExamGrade6 >> grades.ExamGrade7 >> grades.ExamGrade8
            >> grades.DuplomTheme;

        students[i] = Students(initials, university, date, personal, subjects, grades);
    }

    std::cout << "Кількість студентів у файлі: " << n << std::endl;
    for (int i = 0; i < n; ++i) {
        students[i].Print();
    }

    delete[] students;
    FileManager::getInstance()->closeFile(file);
}

// Builder Demo for Student
void builderStudentDemo() {
    StudentBuilder builder;
    Students student = builder.setInitials({ "Doe", "John", "M" })
        .setUniversity({ "Engineering", "CS", "CS101", 3 })
        .setDate({ 2000, 23 })
        .setPersonal({ false, true, 1000.0 })
        .setSubjects({ "Math", "Physics", "Chemistry", "Biology", "History",
                      5, 4, 5, 3, 4, 5, 4, 3, 5, 4 })
        .setGrades({ 5, 4, 3, 4, 5, 4, 3, 5, "AI Research" })
        .build();
    student.Print();
}

// Builder Demo for Teacher
void builderTeacherDemo() {
    TeacherBuilder builder;
    Teachers teacher = builder.setInitials({ "Smith", "Anna", "F" })
        .setDate({ 1985, 39 })
        .setTeacherUniversity({ "Humanities", "Literature", "Lit101", "10" })
        .setTeacherPersonal({ true, true, 2000.0 })
        .build();
    teacher.Print();
}

// Factory Demo
void factoryDemo() {
    Students student = Factory::createStudent({ "Doe", "Jane", "F" },
        { "Science", "Biology", "Bio101", 2 },
        { 2001, 22 },
        { false, true, 1500.0 },
        { "Math", "Biology", "Chemistry", "Physics", "English",
         5, 4, 4, 5, 3, 4, 5, 4, 5, 5 },
        { 5, 4, 3, 4, 5, 4, 3, 5, "Genetics Research" });
    student.Print();
}

// Реалізація патерну Facade
void facadeDemo() {
    UniversityFacade facade;
    Students students[10];
    int size = 10;
    facade.readStudentsFromFile("Students.txt", students, size);
    for (int i = 0; i < size; ++i) {
        students[i].Print();
    }
}
