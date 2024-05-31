#pragma once
#include "Classes.h"

using namespace std;

//.....Студенти.....

void StudentsReading(Students* (&s), int& n, string filename);
void StudentsPrint(Students* s, int n);
void SaveStudents(Students* s, int n, string filename);
void printStudentsByGroup(Students* (&s), int n, string faculty, string group);
void printStudentsByCourse(Students* (&s), int n, string faculty, int  course);
void printStudentsByGrades(Students* (&s), int n, string group, string subject, int semestr, int  grade);
void printStudentsExamsByGroup(Students* (&s), int n, string faculty, string group, int exam, int examgrade);
void printStudentsExamsByCourse(Students* (&s), int n, string faculty, int  course, int exam, int examgrade);
void PrintStudentsByTeacher(Students* s, Teachers* t, int n, int k, string group, string teacherlastname, string teachername, string subject, int semester);
void printStudentDuplomThemeByKafedra(Students* s, int n, string kafedra);
void printStudentDuplomThemeByTeacher(Students* s, Teachers* t, int n, int size_teachers, string teacherlastname, string teachername);

//.....Викладачі

void TeachersReading(Teachers* (&t), int& k, string filename);
void TeachersPrint(Teachers* t, int k);
void SaveTeachers(Teachers* t, int k, string filename);
void PrintTeachersByKafedra(Teachers* t, int k, string kafedra);
void PrintTeachersByFaculty(Teachers* t, int k, string faculty);
void PrintTeachersByType(Teachers* t, int k, string type);
void PrintTeachersByKandidAndDoctor(Teachers* t, int k, string faculty, string kafedra);
void PrintKafedraByGroup(Students* s, int n, Teachers* t, int k, string faculty, string group, int semestr);
void PrintKafedraByCourse(Students* s, int n, Teachers* t, int k, string faculty, int course, int semestr);
void PrintTeachersByGroup(Students* s, int n, Teachers* t, int k, string faculty, string subject, string group);
void PrintTeachersByCourse(Students* s, int n, Teachers* t, int k, string faculty, string subject, int course);
void PrintSubjectTypeByGroup(Students* s, int n, Teachers* t, int k, string faculty, string group, int semestr);
void PrintSubjectTypeByCourse(Students* s, int n, Teachers* t, int k, string faculty, int course, int semestr);
void PrintExamTeachers(Teachers* t, int n, string group, string subject, int semester);
void PrintKerivnkDuplomByFaculty(Teachers* t, int k, string faculty);
void PrintKerivnkDuplomByKafedra(Teachers* t, int k, string kafedra);
void PrintKerivnkDuplomByType(Teachers* t, int k, string type);
void PrintTeachersWork(Teachers* t, int k);
void PrintSubjectHours(Teachers* t, int k);
void PrintTeachersHoursBySemester(Teachers* t, int k, int semester, string teacherlastname, string teachername);
void PrintKafedraByHours(Teachers* t, int k, int semester, string kafedra);
