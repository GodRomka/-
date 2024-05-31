#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <unordered_set>
#include <map>
#include <stdexcept>


using namespace std;

struct Initials {
	//....ПІБ та стать 
	string	Lastname,
			Name,
			Gender;
};

struct University {
	//....Дані студента в університеті 
	string	Faculty,
			Kafedra,
			Group;
	int		Course;
};

struct Date {
	//.... Рік народження та вік 
	int		BirthYear,
			Age;
};
 
struct Personal {
	//....Особисті дані студента 
	bool	HasChildren,
			HasScholarship;
	float	ScholarshipAmount;
};

struct Subjects {
	//.... 5 предметів у студентів (в групі одинакові)
	string	Subject1, 
			Subject2,
			Subject3,
			Subject4,
			Subject5;
	//.... оцінки за зазначені 5 предметів по порядку 
	//....за 1 та 2 семестр
	int     Grade1_1, Grade1_2,
		    Grade2_1, Grade2_2,
			Grade3_1, Grade3_2,
			Grade4_1, Grade4_2,
			Grade5_1, Grade5_2;
};

struct Grades {
	//....Оцінки за сесії ( кожен курс 2 сесії, (2 курс - 4 сесії))	
	int		ExamGrade1,
			ExamGrade2,
			ExamGrade3,
			ExamGrade4,
			ExamGrade5,
			ExamGrade6,
			ExamGrade7,
			ExamGrade8;
	//....Тема дипломної роботи ( 4 курс) 
	string  DuplomTheme;
};

struct TeacherUniversity {
	string	TeachingType, //.... (асистент, викладач, старший викладач, доцент, професор)
		    Faculty,
			Kafedra, //.... Кафедра
			KandidTheme, //....тема кандидатської роботи (якщо є) 
		    DoctorTheme,
			Subject, //.... Предмет, який веде
			SubjectType1,//.... 2 типи занять (асистент:     1)практичні 2)лабораторні  )                                   
			SubjectType2;//...................(викладач:	 1)практичні 2)лабораторні  )
	                     //...................(ст. викладач: 1)практичні 2)лабораторні  )
						 //...................(доцент:       1)семінари  2)лекції       )
	                     //...................(професор:     1)курсові   2)консультації )
	int		SubjectHours1_1,//.... к-сть годин для різних типів предметів 
			SubjectHours2_1,
	        SubjectHours1_2,//.... к-сть годин для різних типів предметів 
		    SubjectHours2_2;

	string	TeachingGroup_sem1, //.... Група, яку навчав у 1 семестрі (всі типи вчителів)
			TeachingGroup_sem2,//.... 2 семестр (всі типи вчителів)
			CourseGroup_sem1, //.... Група, в якій бере екзамен 
			CourseGroup_sem2;//.... 2 семестр 
			
	//....Наукові досягнення 
	bool	IsAspirant, //.... чи навчається в аспурантурі
			HasKandid, //....Чи захистив кандидатську 
			HasDoctor, //....Чи захистив докторську 
			KerivnukDuplom; //.... Чи є керівником дипломної 

};

struct TeacherPersonal {
	//....Особисті дані викладача 
	bool	HasChildren;
	int		ChildrenAmount;
	float	Salary;
};

class Students {
	//.... Закрита частина класу 
	private:

	Initials	initials;
	University	university;
	Date		date;
	Personal	personal;
	Subjects	subjects;
	Grades		grades;

	//....Відкрита частина класу
	public:

	//....обов'язкові методи класу
	Students();//Констуктор за замовчуванням. Створює пустий об'єт
	Students(Initials initials_, University university_, Date date_, Personal Personal_ ,Subjects Subjects_, Grades  Grades_);//Конструктор з параметрами. Створює об'єкт з параметрами.

	//.....не обов'язкові методи
	void Print();
	void StudentsEntry(Initials initials_, University university_, Date date_, Personal Personal_, Subjects Subjects_, Grades  Grades_);
	
	//....вивід даних з класу
	Initials	GetInitials()	{ return initials;	 };
	University	GetUniversity() { return university; };
	Date		GetDate()		{ return date;	     };
	Personal	GetPersonal()	{ return personal;   };
	Subjects	GetSubjects()	{ return subjects;   };
	Grades		GetGrades()		{ return grades;     };

	//....перезавантаження оператора
	Students& operator = (Students s_o);

};

class Teachers {
	//.... Закрита частина класу 
	private:

	Initials			teacherinitials;
	Date				teacherdate;
	TeacherUniversity	teacherUniversity;
	TeacherPersonal		teacherPersonal;

	//....Відкрита частина класу
	public:

	//....обов'язкові методи класу
	Teachers();//Констуктор за замовчуванням. Створює пустий об'єт
	Teachers(Initials teacherinitials_, Date dteacherate_, TeacherUniversity teacherUniversity_, TeacherPersonal teacherPersonal_);//Конструктор з параметрами. Створює об'єкт з параметрами.

	//.....не обов'язкові методи
	void Print();
	void TeachersEntry(Initials initials_, Date date_, TeacherUniversity teacherUniversity_ , TeacherPersonal teacherPersonal_);

	//....вивід даних з класу
	Initials			GetTeachersInitials()		   { return teacherinitials;	};
	Date				GetTeachersDate()			   { return teacherdate;		};
	TeacherUniversity	GetTeacherUniversity()         { return teacherUniversity;  };
	TeacherPersonal		GetTeacherPersonal()           { return teacherPersonal;	};

	//....перезавантаження оператора
	Teachers& operator = (Teachers t_o);
};