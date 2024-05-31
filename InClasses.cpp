#pragma once
#include "Classes.h"

Students::Students()
{
	initials.Lastname = "";
	initials.Name = ""; 
	initials.Gender = "";

	university.Faculty = "";
	university.Kafedra = "";
	university.Group = "";
	university.Course = 0;

	date.BirthYear = 0;
	date.Age = 0;

	personal.HasChildren = 0;
	personal.HasScholarship = 0;
	personal.ScholarshipAmount = 0;

	subjects.Subject1 = "";
	subjects.Subject2 = "";
	subjects.Subject3 = "";
	subjects.Subject4 = "";
	subjects.Subject5 = "";

	subjects.Grade1_1 = 0;
	subjects.Grade1_2 = 0;

	subjects.Grade2_1 = 0;
	subjects.Grade2_2 = 0;

	subjects.Grade3_1 = 0;
	subjects.Grade3_2 = 0;

	subjects.Grade4_1 = 0;
	subjects.Grade4_2 = 0;

	subjects.Grade5_1 = 0;
	subjects.Grade5_2 = 0;

	grades.ExamGrade1 = 0;
	grades.ExamGrade2 = 0;
	grades.ExamGrade3 = 0;
	grades.ExamGrade4 = 0;
	grades.ExamGrade5 = 0;
	grades.ExamGrade6 = 0;
	grades.ExamGrade7 = 0;
	grades.ExamGrade8 = 0;

	grades.DuplomTheme = "";
}

Students::Students(Initials initials_, University university_, Date date_, Personal personal_, Subjects subjects_, Grades  grades_)
{
	initials.Lastname = initials_.Lastname;
	initials.Name = initials_.Name;
	initials.Gender = initials_.Gender;

	university.Faculty = university_.Faculty;
	university.Kafedra = university_.Kafedra;
	university.Group = university_.Group;
	university.Course = university_.Course;

	date.BirthYear = date_.BirthYear;
	date.Age = date_.Age;

	personal.HasChildren = personal_.HasChildren;
	personal.HasScholarship = personal_.HasScholarship;
	personal.ScholarshipAmount = personal_.ScholarshipAmount;

	subjects.Subject1 = subjects_.Subject1;
	subjects.Subject2 = subjects_.Subject2;
	subjects.Subject3 = subjects_.Subject3;
	subjects.Subject4 = subjects_.Subject4;
	subjects.Subject5 = subjects_.Subject5;

	subjects.Grade1_1 = subjects_.Grade1_1;
	subjects.Grade1_2 = subjects_.Grade1_2;

	subjects.Grade2_1 = subjects_.Grade2_1;
	subjects.Grade1_2 = subjects_.Grade1_2;

	subjects.Grade3_1 = subjects_.Grade3_1;
	subjects.Grade3_1 = subjects_.Grade3_2;

	subjects.Grade4_1 = subjects_.Grade4_1;
	subjects.Grade4_2 = subjects_.Grade4_2;

	subjects.Grade5_1 = subjects_.Grade5_1;
	subjects.Grade5_2 = subjects_.Grade5_2;

	grades.ExamGrade1 = grades_.ExamGrade1;
	grades.ExamGrade2 = grades_.ExamGrade2;
	grades.ExamGrade3 = grades_.ExamGrade3;
	grades.ExamGrade4 = grades_.ExamGrade4;
	grades.ExamGrade5 = grades_.ExamGrade5;
	grades.ExamGrade6 = grades_.ExamGrade6;
	grades.ExamGrade7 = grades_.ExamGrade7;
	grades.ExamGrade8 = grades_.ExamGrade8;

	grades.DuplomTheme = grades_.DuplomTheme;
}

void Students::Print()
{
	cout << setiosflags(ios::left);
	cout << " Прізвище та ім'я: " << initials.Lastname << " " << initials.Name << endl;
	cout << " Стать:            " << initials.Gender << endl;
	cout << " Рік народження:   " << date.BirthYear << " "  << "Вік:" << date.Age << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Факультет: " << university.Faculty << endl;
	cout << " Кафедра:   " << university.Kafedra << endl;
	cout << " Група:     " << university.Group << endl;
	cout << " Курс:      " << university.Course << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Чи має дітей ?:     " << (personal.HasChildren ? "Так" : "Ні") << endl;
	cout << " Чи має стипендію ?: " << (personal.HasScholarship ? "Так" : "Ні") << " " << "Розмір:" << personal.ScholarshipAmount << " грн " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Дисципліни та оцінки:" << endl;
	cout << " " << endl;
	cout << " 1-ша: " << setw(20) << subjects.Subject1   << " Оцінка за 1 семестр: " << subjects.Grade1_1 <<  " За 2 семестр: " << subjects.Grade1_2 << endl;
	cout << " 2-га: " << setw(20) << subjects.Subject2   << " Оцінка за 1 семестр: " << subjects.Grade2_1 << " За 2 семестр: " << subjects.Grade2_2 << endl;
	cout << " 3-тя: " << setw(20) << subjects.Subject3   << " Оцінка за 1 семестр: " << subjects.Grade3_1 << " За 2 семестр: " << subjects.Grade3_2 << endl;
	cout << " 4-та: " << setw(20) << subjects.Subject4   << " Оцінка за 1 семестр: " << subjects.Grade4_1 << " За 2 семестр: " << subjects.Grade4_2 << endl;
	cout << " 5-та: " << setw(20) << subjects.Subject5   << " Оцінка за 1 семестр: " << subjects.Grade5_1 << " За 2 семестр: " << subjects.Grade5_2 << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Оцінки за сесії " << endl;
	cout << " " << endl;
	cout << " 1-ша: " << grades.ExamGrade1 << endl;
	cout << " 2-га: " << grades.ExamGrade2 << endl;
	cout << " 3-тя: " << grades.ExamGrade3 << endl;
	cout << " 4-та: " << grades.ExamGrade4 << endl;
	cout << " 5-та: " << grades.ExamGrade5 << endl;
	cout << " 6-та: " << grades.ExamGrade6 << endl;
	cout << " 7-ма: " << grades.ExamGrade7 << endl;
	cout << " 8-ма: " << grades.ExamGrade8 << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Tема дипломної роботи: " << grades.DuplomTheme << endl;
	cout << " " << endl;

}

void Students::StudentsEntry(Initials initials_, University university_, Date date_, Personal personal_, Subjects subjects_, Grades  grades_)
{
	initials.Lastname = initials_.Lastname;
	initials.Name = initials_.Name;
	initials.Gender = initials_.Gender;

	date.BirthYear = date_.BirthYear;
	date.Age = date_.Age;

	university.Faculty = university_.Faculty;
	university.Kafedra = university_.Kafedra;
	university.Group = university_.Group;
	university.Course = university_.Course;

	personal.HasChildren = personal_.HasChildren;
	personal.HasScholarship = personal_.HasScholarship;
	personal.ScholarshipAmount = personal_.ScholarshipAmount;

	subjects.Subject1 = subjects_.Subject1;
	subjects.Grade1_1 = subjects_.Grade1_1;
	subjects.Grade1_2 = subjects_.Grade1_2;

	subjects.Subject2 = subjects_.Subject2;
	subjects.Grade2_1 = subjects_.Grade2_1;
	subjects.Grade2_2 = subjects_.Grade2_2;

	subjects.Subject3 = subjects_.Subject3;
	subjects.Grade3_1 = subjects_.Grade3_1;
	subjects.Grade3_2 = subjects_.Grade3_2;

	subjects.Subject4 = subjects_.Subject4;	
	subjects.Grade4_1 = subjects_.Grade4_1;
	subjects.Grade4_2 = subjects_.Grade4_2;

	subjects.Subject5 = subjects_.Subject5;
	subjects.Grade5_1 = subjects_.Grade5_1;
	subjects.Grade5_2 = subjects_.Grade5_2;

	grades.ExamGrade1 = grades_.ExamGrade1;
	grades.ExamGrade2 = grades_.ExamGrade2;
	grades.ExamGrade3 = grades_.ExamGrade3;
	grades.ExamGrade4 = grades_.ExamGrade4;
	grades.ExamGrade5 = grades_.ExamGrade5;
	grades.ExamGrade6 = grades_.ExamGrade6;
	grades.ExamGrade7 = grades_.ExamGrade7;
	grades.ExamGrade8 = grades_.ExamGrade8;

	grades.DuplomTheme = grades_.DuplomTheme;
}

Students& Students::operator=(Students s_o)
{
	this -> initials.Lastname = s_o.initials.Lastname;
	this->initials.Name = s_o.initials.Name;
	this->initials.Gender = s_o.initials.Gender;

	this->university.Faculty = s_o.university.Faculty;
	this->university.Kafedra = s_o.university.Kafedra;
	this->university.Group = s_o.university.Group;
	this->university.Course = s_o.university.Course;

	this->date.BirthYear = s_o.date.BirthYear;
	this->date.Age = s_o.date.Age;

	this->personal.HasChildren = s_o.personal.HasChildren;
	this->personal.HasScholarship = s_o.personal.HasScholarship;
	this->personal.ScholarshipAmount = s_o.personal.ScholarshipAmount;

	this->subjects.Subject1 = s_o.subjects.Subject1;
	this->subjects.Grade1_1 = s_o.subjects.Grade1_1;
	this->subjects.Grade1_2 = s_o.subjects.Grade1_2;

	this->subjects.Subject2 = s_o.subjects.Subject2;
	this->subjects.Grade2_1 = s_o.subjects.Grade2_1;
	this->subjects.Grade2_2 = s_o.subjects.Grade2_2;

	this->subjects.Subject3 = s_o.subjects.Subject3;
	this->subjects.Grade3_1 = s_o.subjects.Grade3_1;
	this->subjects.Grade3_2 = s_o.subjects.Grade3_2;

	this->subjects.Subject4 = s_o.subjects.Subject4;
	this->subjects.Grade4_1 = s_o.subjects.Grade4_1;
	this->subjects.Grade4_2 = s_o.subjects.Grade4_2;

	this->subjects.Subject5 = s_o.subjects.Subject5;
	this->subjects.Grade5_1 = s_o.subjects.Grade5_1;
	this->subjects.Grade5_2 = s_o.subjects.Grade5_2;
	
	this->grades.ExamGrade1 = s_o.grades.ExamGrade1;
	this->grades.ExamGrade2 = s_o.grades.ExamGrade2;
	this->grades.ExamGrade3 = s_o.grades.ExamGrade3;
	this->grades.ExamGrade4 = s_o.grades.ExamGrade4;
	this->grades.ExamGrade5 = s_o.grades.ExamGrade5;
	this->grades.ExamGrade6 = s_o.grades.ExamGrade6;
	this->grades.ExamGrade7 = s_o.grades.ExamGrade7;
	this->grades.ExamGrade8 = s_o.grades.ExamGrade8;

	this->grades.DuplomTheme = s_o.grades.DuplomTheme;

	return *this;

}



Teachers::Teachers(){

	teacherinitials.Lastname = "";
	teacherinitials.Name = "";
	teacherinitials.Gender = "";

	teacherdate.BirthYear = 0;
	teacherdate.Age = 0;

	teacherUniversity.TeachingType = "";
	teacherUniversity.Faculty = "";
	teacherUniversity.Kafedra = "";
	teacherUniversity.KandidTheme = "";
	teacherUniversity.DoctorTheme = "";
	teacherUniversity.Subject = "";

	teacherUniversity.SubjectType1 = "";
	teacherUniversity.SubjectType2 = "";
	teacherUniversity.SubjectHours1_1 = 0;
	teacherUniversity.SubjectHours2_1 = 0;
	teacherUniversity.SubjectHours1_2 = 0;
	teacherUniversity.SubjectHours2_2 = 0;

	teacherUniversity.TeachingGroup_sem1 = "";
	teacherUniversity.TeachingGroup_sem2 = "";
	teacherUniversity.CourseGroup_sem1 = "";
	teacherUniversity.CourseGroup_sem2 = "";

	teacherUniversity.IsAspirant = 0;
	teacherUniversity.HasKandid = 0;
	teacherUniversity.HasDoctor = 0;
	teacherUniversity.KerivnukDuplom = 0;

	teacherPersonal.HasChildren = 0;
	teacherPersonal.ChildrenAmount = 0;
	teacherPersonal.Salary = 0;

}

Teachers::Teachers(Initials teacherinitials_, Date teacherdate_,TeacherUniversity teacherUniversity_ , TeacherPersonal teacherPersonal_) {

	teacherinitials.Lastname = teacherinitials_.Lastname;
	teacherinitials.Name = teacherinitials_.Name;
	teacherinitials.Gender = teacherinitials_.Gender;

	teacherdate.BirthYear = teacherdate_.BirthYear;
	teacherdate.Age = teacherdate_.Age;

	teacherUniversity.TeachingType = teacherUniversity_.TeachingType;
	teacherUniversity.Faculty = teacherUniversity_.Faculty;
	teacherUniversity.Kafedra = teacherUniversity_.Kafedra;
	teacherUniversity.KandidTheme = teacherUniversity_.KandidTheme;
	teacherUniversity.DoctorTheme = teacherUniversity_.DoctorTheme;
	teacherUniversity.Subject = teacherUniversity_.Subject;

	teacherUniversity.SubjectType1 = teacherUniversity_.SubjectType1;
	teacherUniversity.SubjectType2 = teacherUniversity_.SubjectType2;
	teacherUniversity.SubjectHours1_1 = teacherUniversity_.SubjectHours1_1;
	teacherUniversity.SubjectHours2_1 = teacherUniversity_.SubjectHours2_1;
	teacherUniversity.SubjectHours1_2 = teacherUniversity_.SubjectHours1_2;
	teacherUniversity.SubjectHours2_2 = teacherUniversity_.SubjectHours2_2;

	teacherUniversity.TeachingGroup_sem1 = teacherUniversity_.TeachingGroup_sem1;
	teacherUniversity.TeachingGroup_sem2 = teacherUniversity_.TeachingGroup_sem2;
	teacherUniversity.CourseGroup_sem1 = teacherUniversity_.CourseGroup_sem1;
	teacherUniversity.CourseGroup_sem2 = teacherUniversity_.CourseGroup_sem2;


	teacherUniversity.IsAspirant = teacherUniversity_.IsAspirant;
	teacherUniversity.HasKandid = teacherUniversity_.HasKandid;
	teacherUniversity.HasDoctor = teacherUniversity_.HasDoctor;
	teacherUniversity.KerivnukDuplom = teacherUniversity_.KerivnukDuplom;

	teacherPersonal.HasChildren = teacherPersonal_.HasChildren;
	teacherPersonal.ChildrenAmount = teacherPersonal_.ChildrenAmount;
	teacherPersonal.Salary = teacherPersonal_.Salary;
}

void Teachers::Print() {

	cout << "Прізвище та ім'я: " << teacherinitials.Lastname << " " << teacherinitials.Name << endl;
	cout << "Стать:            " << teacherinitials.Gender << endl;
	cout << "Рік народження:   " << teacherdate.BirthYear << " Вік: " << teacherdate.Age << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Тип вчителя: " << teacherUniversity.TeachingType << endl;
	cout << "Факультет:   " << teacherUniversity.Faculty << endl;
	cout << "Кафедра:     " << teacherUniversity.Kafedra << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Тема кандидатської: " << setw(15) << teacherUniversity.KandidTheme << endl;
	cout << "Тема докторської:   " << setw(15) << teacherUniversity.DoctorTheme << endl;
	cout << "Предмет, який веде: " << setw(15) << teacherUniversity.Subject << endl;
	cout << "Вид занять:         " << setw(15) << teacherUniversity.SubjectType1  << " К-сть годин 1 сем.: " << teacherUniversity.SubjectHours1_1 << " 2 сем.: " << teacherUniversity.SubjectHours1_2 << endl;
	cout << "Вид занять:         " << setw(15) << teacherUniversity.SubjectType2  << " К-сть годин 1 сем.: " << teacherUniversity.SubjectHours2_1 << " 1 сем.: " << teacherUniversity.SubjectHours2_2 << endl;
	cout << "Група, яку навчав у 1 семестрі:          " << teacherUniversity.TeachingGroup_sem1 << " У 2 семестрі: " << teacherUniversity.TeachingGroup_sem2 << endl;
	cout << "Група, у якій брав екзамен у 1 семестрі: " << teacherUniversity.CourseGroup_sem1   << " У 2 семестрі: " << teacherUniversity.CourseGroup_sem2 << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Чи вчиться в аспірантурі ?:         " << (teacherUniversity.IsAspirant ? "Так" : "Ні") << endl;
	cout << "Чи захистив кандидатську роботу ?:  " << (teacherUniversity.HasKandid ? "Так" : "Ні") << endl;
	cout << "Чи захистив докторську роботу ?:    " << (teacherUniversity.HasDoctor ? "Так" : "Ні") << endl;
	cout << "Чи є керівником дипломної роботи ?: " << (teacherUniversity.KerivnukDuplom ? "Так" : "Ні") << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Чи має дітей ?: "                   << (teacherPersonal.HasChildren ? "Так" : "Ні")<< " К-сть дітей: " << teacherPersonal.ChildrenAmount << endl;
	cout << "Розмір зарплати: "                  << teacherPersonal.Salary << endl;

}

void Teachers::TeachersEntry(Initials teacherinitials_, Date teacherdate_, TeacherUniversity teacherUniversity_, TeacherPersonal teacherPersonal_) {

	teacherinitials.Lastname = teacherinitials_.Lastname;
	teacherinitials.Name = teacherinitials_.Name;
	teacherinitials.Gender = teacherinitials_.Gender;

	teacherdate.BirthYear = teacherdate_.BirthYear;
	teacherdate.Age = teacherdate_.Age;

	teacherUniversity.TeachingType = teacherUniversity_.TeachingType;
	teacherUniversity.Faculty = teacherUniversity_.Faculty;
	teacherUniversity.Kafedra = teacherUniversity_.Kafedra;
	teacherUniversity.KandidTheme = teacherUniversity_.KandidTheme;
	teacherUniversity.DoctorTheme = teacherUniversity_.DoctorTheme;
	teacherUniversity.Subject = teacherUniversity_.Subject;

	teacherUniversity.SubjectType1 = teacherUniversity_.SubjectType1;
	teacherUniversity.SubjectType2 = teacherUniversity_.SubjectType2;

	teacherUniversity.SubjectHours1_1 = teacherUniversity_.SubjectHours1_1;
	teacherUniversity.SubjectHours2_1 = teacherUniversity_.SubjectHours2_1;
	teacherUniversity.SubjectHours1_2 = teacherUniversity_.SubjectHours1_2;
	teacherUniversity.SubjectHours2_2 = teacherUniversity_.SubjectHours2_2;

	teacherUniversity.TeachingGroup_sem1 = teacherUniversity_.TeachingGroup_sem1;
	teacherUniversity.TeachingGroup_sem2 = teacherUniversity_.TeachingGroup_sem2;
	teacherUniversity.CourseGroup_sem1 = teacherUniversity_.CourseGroup_sem1;
	teacherUniversity.CourseGroup_sem2 = teacherUniversity_.CourseGroup_sem2;

	teacherUniversity.IsAspirant = teacherUniversity_.IsAspirant;
	teacherUniversity.HasKandid = teacherUniversity_.HasKandid;
	teacherUniversity.HasDoctor = teacherUniversity_.HasDoctor;
	teacherUniversity.KerivnukDuplom = teacherUniversity_.KerivnukDuplom;

	teacherPersonal.HasChildren = teacherPersonal_.HasChildren;
	teacherPersonal.ChildrenAmount = teacherPersonal_.ChildrenAmount;
	teacherPersonal.Salary = teacherPersonal_.Salary;

}

Teachers& Teachers::operator=(Teachers t_o) {

	this ->teacherinitials.Lastname = t_o.teacherinitials.Lastname;
	this->teacherinitials.Name = t_o.teacherinitials.Name;
	this->teacherinitials.Gender = t_o.teacherinitials.Gender;

	this->teacherdate.BirthYear = t_o.teacherdate.BirthYear;
	this->teacherdate.Age = t_o.teacherdate.Age;

	this->teacherUniversity.TeachingType = t_o.teacherUniversity.TeachingType;
	this->teacherUniversity.Faculty = t_o.teacherUniversity.Faculty;
	this->teacherUniversity.Kafedra = t_o.teacherUniversity.Kafedra;
	this->teacherUniversity.KandidTheme = t_o.teacherUniversity.KandidTheme;
	this->teacherUniversity.DoctorTheme = t_o.teacherUniversity.DoctorTheme;
	this->teacherUniversity.Subject = t_o.teacherUniversity.Subject;

	this->teacherUniversity.SubjectType1 = t_o.teacherUniversity.SubjectType1;
	this->teacherUniversity.SubjectType2 = t_o.teacherUniversity.SubjectType2;
	this->teacherUniversity.SubjectHours1_1 = t_o.teacherUniversity.SubjectHours1_1;
	this->teacherUniversity.SubjectHours2_1 = t_o.teacherUniversity.SubjectHours2_1;
	this->teacherUniversity.SubjectHours1_2 = t_o.teacherUniversity.SubjectHours1_2;
	this->teacherUniversity.SubjectHours2_2 = t_o.teacherUniversity.SubjectHours2_2;

	this->teacherUniversity.TeachingGroup_sem1 = t_o.teacherUniversity.TeachingGroup_sem1;
	this->teacherUniversity.TeachingGroup_sem2 = t_o.teacherUniversity.TeachingGroup_sem2;
	this->teacherUniversity.CourseGroup_sem1 = t_o.teacherUniversity.CourseGroup_sem1;
	this->teacherUniversity.CourseGroup_sem2 = t_o.teacherUniversity.CourseGroup_sem2;


	this->teacherUniversity.IsAspirant = t_o.teacherUniversity.IsAspirant;
	this->teacherUniversity.HasKandid = t_o.teacherUniversity.HasKandid;
	this->teacherUniversity.HasDoctor = t_o.teacherUniversity.HasDoctor;
	this->teacherUniversity.KerivnukDuplom = t_o.teacherUniversity.KerivnukDuplom;

	this->teacherPersonal.HasChildren = t_o.teacherPersonal.HasChildren;
	this->teacherPersonal.ChildrenAmount = t_o.teacherPersonal.ChildrenAmount;
	this->teacherPersonal.Salary = t_o.teacherPersonal.Salary;

	return *this;

}