#pragma once
#include "Function.h"
#include "Pattern.h"

int _Menu, _StudentsMenu, _TeachersMenu, _PatternMenu;

void Menu()
{
	cout	<< "Виберіть з ким хочете працювати " << endl
			<< "(0)  Вихід з програми" << endl
			<< "(1)  Студенти " << endl
			<< "(2)  Викладачі " << endl
			<< "Ви обрали: ";
	cin		>> _Menu;
};

void StudentsMenu() {
	cout << "(0)  Назад" << endl
		 << "(1)  Вивести дані студента(студентів)" << endl
		 << "(2)  Отримати перелік і загальне число студентів зазначених груп або вказаного курсу(курсів) факультету повністю" << endl
		 << "(3)  Отримати список і загальне число студентів зазначених груп, які здали залік або іспит із зазначеної дисципліни із встановленою оцінкою." << endl
		 << "(4)  Отримати список і загальне число студентів зазначених груп або вказаного курсу зазначеного факультету, які здали зазначену сесію на відмінно, без трійок, без двійок. " << endl
		 << "(5)  Отримати список студентів зазначених груп, або яким заданий викладач поставив деяку оцінку за іспит з певних дисциплін, у зазначеному семестрі. " << endl
		 << "(6)  Отримати список студентів і тем дипломних робіт на зазначеній кафедрі або у вказаного викладача. " << endl
		 << "(7)  Зберегти дані" << endl
		 << "Ви обрали: ";
	cin >> _StudentsMenu;

	int _actions;
	string filename;

	int _size  = 0;   //.... К-сть даних
	Students* s = new Students[_size];
	int _size_teachers = 0;  //.... масив
	Teachers* t = new Teachers[_size_teachers]; //.... масив

	StudentsReading(s, _size, "Students.txt");
	TeachersReading(t, _size_teachers, "Teachers.txt");
	system("cls"); //....очищення консолі

	while (_StudentsMenu != 0) {
		switch (_StudentsMenu) {
//________________________________________________________________________________
		case 1:

			system("cls"); //....очищення консолі

			if (_size != 0)
				StudentsPrint(s, _size);
			else
				cout << "Дані порожні " << endl;

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			StudentsMenu();
			break;
//________________________________________________________________________________
		case 2:

			system("cls"); //....очищення консолі

			cout << "Шукати за (1)групою чи (2)курсом ?" << endl;
			cin >> _actions;

			system("cls"); //....очищення консолі

			if (_actions == 1) {
				string faculty, group;
				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;
				system("cls"); //....очищення консолі

				cout << "Введіть групу для пошуку: " << endl;
				cin >> group;
				system("cls"); //....очищення консолі

				printStudentsByGroup(s, _size, faculty, group );
			}
			else {
				string faculty;
				int course;
				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;
				system("cls"); //....очищення консолі

				do {
					cout << "Введіть курс(1-4) для пошуку: " << endl;
					cin >> course;
					if (course < 1 || course > 4) {
						system("cls"); //....очищення консолі
						cout << "Курс введено невірно" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						course = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі
				printStudentsByCourse(s, _size, faculty, course);

			}

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			StudentsMenu();
			break;
//________________________________________________________________________________
		case 3:

			system("cls"); //....очищення консолі

			if (_size != 0) {

				string group, subject;
				int semester, grade;

				cout << "Введіть групу для пошуку: " << endl;
				cin >> group;
				system("cls"); //....очищення консолі

				cout << "Введіть назву дисципліни: " << endl;
				cin >> subject;
				system("cls"); //....очищення консолі

				do {
					cout << "Введіть семестр(1-2): " << endl;
					cin >> semester;
					if (semester < 1 || semester > 2) {
						system("cls"); //....очищення консолі
						cout << "Семестр введено невірно" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						semester = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі

				do {
					cout << "Введіть оцінку(1-5) для пошуку: " << endl;
					cin >> grade;
					if (grade < 1 || grade > 5) {
						system("cls"); //....очищення консолі
						cout << "Невірна оцінка" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						grade = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі
				printStudentsByGrades(s, _size, group, subject, semester, grade);
			}
			else
				cout << "Дані порожні " << endl;

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			StudentsMenu();
			break;
//________________________________________________________________________________
		case 4:

			system("cls"); //....очищення консолі

			cout << "Шукати за (1)групою чи (2)курсом ?" << endl;
			cin >> _actions;

			system("cls"); //....очищення консолі

			if (_actions == 1) {
				string faculty, group;
				int exam, examgrade;

				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;
				system("cls"); //....очищення консолі

				cout << "Введіть групу: " << endl;
				cin >> group;
				system("cls"); //....очищення консолі

				do {

					cout << "Введіть номер сесії(1-8): " << endl;
					cin >> exam;
					if (exam < 1 || exam > 8) {
						system("cls"); //....очищення консолі
						cout << "Невірний номер сесії" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						exam = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі

				do {

					cout << "Введіть оцінку(1-5) для пошуку:  " << endl;
					cin >> examgrade;
					if (examgrade < 1 || examgrade > 5) {
						system("cls"); //....очищення консолі
						cout << "невірна оцінка" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						examgrade = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі
				printStudentsExamsByGroup(s, _size, faculty, group, exam, examgrade);

			}
			else {
				string faculty;
				int course, exam, examgrade;

				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;
				system("cls"); //....очищення консолі

				do {
					cout << "Введіть курс(1-4) для пошуку: " << endl;
					cin >> course;
					if (course < 1 || course > 4) {
						system("cls"); //....очищення консолі
						cout << "Курс введено невірно" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						course = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі

				do {

					cout << "Введіть номер сесії(1-8): " << endl;
					cin >> exam;
					if (exam < 1 || exam > 8) {
						system("cls"); //....очищення консолі
						cout << "Невірний номер сесії" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						exam = 0;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі

				do {
					cout << "Введіть оцінку(1-5) для пошуку: " << endl;
					cin >> examgrade;
					if (examgrade < 1 || examgrade > 5) {
						system("cls"); //....очищення консолі
						cout << "Невірна оцінка" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						examgrade = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі
				printStudentsExamsByCourse(s, _size, faculty, course, exam, examgrade);

			}

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			StudentsMenu();
			break;
//________________________________________________________________________________	
		case 5:
			system("cls");
			if (_size != 0) {
				string group, subject, teacherlastname, teachername;
				int semester;
				cout << "Введіть групу: " << endl;
				cin >> group;
				system("cls");

				cout << "Введіть назву дисципліни: " << endl;
				cin >> subject;
				system("cls");

				do {
					cout << "Введіть семестр (1-2): " << endl;
					cin >> semester;
					if (semester < 1 || semester > 2) {
						system("cls");
						cout << "Семестр введено невірно" << endl;
						system("pause");
						system("cls");
						semester = 0;
						continue;
					}
					break;
				} while (true);

				system("cls");
				cout << "Введіть прізвище та ім'я викладача: " << endl;
				cin >> teacherlastname >> teachername;

				system("cls");
				PrintStudentsByTeacher(s, t, _size, _size_teachers, group, teacherlastname, teachername, subject, semester);
			}
			else {
				cout << "Дані порожні" << endl;
			}
			system("pause");
			system("cls");
			StudentsMenu();
//________________________________________________________________________________	
		case 6:
			system("cls"); //....очищення консолі

			cout << "Шукати за (1)кафедрою чи (2)викладачем ? " << endl;
			cin >> _actions;
			system("cls"); //....очищення консолі

			if (_actions == 1) {
				string kafedra;
				cout << " Введіть кафедру " << endl;
				cin >> kafedra;
				system("cls"); //....очищення консолі
				printStudentDuplomThemeByKafedra(s, _size, kafedra);
			}
			else {
				string teacherlastname, teachername;
				cout << "Введіть прізвище та ім'я викладача" << endl;
				cin >> teacherlastname >> teachername;
				system("cls"); //....очищення консолі
				printStudentDuplomThemeByTeacher(s, t, _size, _size_teachers, teacherlastname, teachername);
			}

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			StudentsMenu();
//________________________________________________________________________________	
		case 7:
			system("cls"); //....очищення консолі

			if (_size != 0)
				SaveStudents(s, _size, "Students.txt");
			else
				cout << " Дані порожні " << endl;

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			StudentsMenu();
			break;
//________________________________________________________________________________	
		default:
			system("cls"); //....очищення консолі
			cout << " Пункт меню введено невірно " << endl;
			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			StudentsMenu();
			break;

		}
	}
	system("cls"); //....очищення консолі
	cout << " Робота завершена " << endl;
	system("pause"); //....затримка консолі

}

void TeachersMenu() {
	cout	<< "(0)  Назад" << endl
			<< "(1)  Вивести дані викладача(викладачів)" << endl
			<< "(2)  Отримати список і загальне число викладачів зазначених кафедр, зазначеного факультету повністю, або зазначених категорій" << endl
			<< "(3)  Отримати перелік і загальне число тем кандидатських і докторських дисертацій, які захистили співробітники вказаної кафедри для зазначеного факультету." << endl
			<< "(4)  Отримати перелік кафедр, які проводять заняття у зазначеній групі або назазначеному курсі вказаного факультету в зазначеному семестрі." << endl
			<< "(5)  Отримати список і загальне число викладачів, що проводили (проводять) заняття за вказаною дисципліною в зазначеній групі або на зазначеному курсі вказаного факультету" << endl
			<< "(6)  Отримати перелік і загальне число викладачів, які проводили (проводять) лекційні, семінарські та інші види занять у зазначеній групі або на зазначеному курсі вказаного факультету в зазначеному семестрі" << endl
			<< "(7)  Отримати перелік викладачів, які беруть (брали) іспити у зазначених групах, з зазначених дисциплін, у вказаному семестрі " << endl
			<< "(8)  Отримати список керівників дипломних робіт з встановленої кафедри, або факультету повністю і окремо по деяким категоріям викладачів" << endl
			<< "(9)  Отримати навантаження викладачів (назва дисципліни, кількість годин), її обсяг на окремі види занять і загальне навантаження в зазначеному семестрі для конкретного викладача або для викладачів зазначеної кафедри." << endl
		    << "(10) Зберегти дані " << endl
			<< "Ви обрали: ";
	cin		>> _TeachersMenu;

	int _actions;
	string filename;

	int _size = 0;   //.... К-сть даних
	Students* s = new Students[_size];
	int _size_teachers = 0;  //.... масив
	Teachers* t = new Teachers[_size_teachers]; //.... масив

	StudentsReading(s, _size, "Students.txt");
	TeachersReading(t, _size_teachers, "Teachers.txt");

	system("cls"); //....очищення консолі

	while (_TeachersMenu != 0) {
		switch (_TeachersMenu) {
//________________________________________________________________________________
		case 1:

			system("cls"); //....очищення консолі
			
			if (_size_teachers != 0)
				TeachersPrint(t, _size_teachers);
			else
				cout << "Дані порожні " << endl;

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			TeachersMenu();
			break;
//________________________________________________________________________________
		case 2:
			system("cls"); //....очищення консолі

			cout << "Шукати за (1)факультетом, (2)кафедрою чи (3)категорією " << endl;
			cin >> _actions;

			system("cls"); //....очищення консолі

			if (_actions == 1) {
				string faculty;

				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;

				system("cls"); //....очищення консолі

				PrintTeachersByFaculty(t, _size_teachers, faculty);
			}
			else if (_actions == 2) {
				string kafedra;

				cout << "Введіть кафедру для пошуку: " << endl;
				cin >> kafedra;

				system("cls"); //....очищення консолі

				PrintTeachersByKafedra(t, _size_teachers, kafedra);
			}
			else {
				string type;

				cout << "Введіть категорію викладача для пошуку: " << endl;
				cin >> type;

				system("cls"); //....очищення консолі

				PrintTeachersByType(t, _size_teachers, type);
			}

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			TeachersMenu();
			break;
//________________________________________________________________________________	
		case 3:
			system("cls"); //....очищення консолі

			if (_size_teachers != 0) {

				string faculty, kafedra;

				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;
				system("cls"); //....очищення консолі
				cout << "Введіть кафедру для пошуку: " << endl;
				cin >> kafedra;

				PrintTeachersByKandidAndDoctor(t, _size_teachers, faculty, kafedra);
			}
			else
				cout << "Дані порожні " << endl;

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			TeachersMenu();
			break;
//________________________________________________________________________________	
		case 4:
			system("cls"); //....очищення консолі

			cout << " Шукати за (1)групою чи  (2)курсом " << endl;
			cin >> _actions;

			system("cls"); //....очищення консолі

			if (_actions == 1) {
				string faculty, group;
				int semester;

				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;
				system("cls"); //....очищення консолі
				cout << "Введіть групу для пошуку: " << endl;
				cin >> group;
				system("cls"); //....очищення консолі

				do {
					cout << "Введіть семестр(1-2): " << endl;
					cin >> semester;
					if (semester < 1 || semester > 2) {
						system("cls"); //....очищення консолі
						cout << "Семестр введено невірно" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						semester = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі
				PrintKafedraByGroup(s, _size, t, _size_teachers, faculty, group, semester);
			}
			else if (_actions == 2) {
				string faculty;
				int semester, course;

				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;
				system("cls"); //....очищення консолі

				do {
					cout << "Введіть курс(1-4) для пошуку: " << endl;
					cin >> course;
					if (course < 1 || course > 4) {
						system("cls"); //....очищення консолі
						cout << "Курс введено невірно" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						course = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі

				do {
					cout << "Введіть семестр(1-2): " << endl;
					cin >> semester;
					if (semester < 1 || semester > 2) {
						system("cls"); //....очищення консолі
						cout << "Семестр введено невірно" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						semester = 0;
						continue;
					}
					break;
				} while (true);
			
				system("cls"); //....очищення консолі
				PrintKafedraByCourse(s, _size, t, _size_teachers, faculty, course, semester);
			}

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			TeachersMenu();
			break;
//________________________________________________________________________________	
		case 5:
			system("cls"); //....очищення консолі

			cout << " Шукати за (1)групою чи  (2)курсом " << endl;
			cin >> _actions;
			system("cls"); //....очищення консолі

			if (_actions == 1) {
				string faculty, subject, group;

				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;
				system("cls"); //....очищення консолі

				cout << "Введіть групу для пошуку: " << endl;
				cin >> group;
				system("cls"); //....очищення консолі

				cout << "Введіть дисципліну для пошуку: " << endl;
				cin >> subject;

				system("cls"); //....очищення консолі
				PrintTeachersByGroup (s, _size, t, _size_teachers, faculty, group, subject);
			}
			else if (_actions == 2) {
				string faculty, subject;
				int course;

				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;
				system("cls"); //....очищення консолі

				cout << "Введіть дисципліну для пошуку: " << endl;
				cin >> subject;
				system("cls"); //....очищення консолі

				do {
					cout << "Введіть курс(1-4) для пошуку: " << endl;
					cin >> course;
					if (course < 1 || course > 4) {
						system("cls"); //....очищення консолі
						cout << "Курс введено невірно" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						course = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі
				PrintTeachersByCourse(s, _size, t, _size_teachers, faculty, subject, course);
			}

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			TeachersMenu();
			break;
//________________________________________________________________________________	
		case 6:
			system("cls"); //....очищення консолі

			cout << " Шукати за (1)групою чи  (2)курсом " << endl;
			cin >> _actions;
			system("cls"); //....очищення консолі

			if (_actions == 1) {
				string faculty, group;
				int semester;

				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;
				system("cls"); //....очищення консолі

				cout << "Введіть групу для пошуку: " << endl;
				cin >> group;
				system("cls"); //....очищення консолі

				do {
					cout << "Введіть семестр(1-2): " << endl;
					cin >> semester;
					if (semester < 1 || semester > 2) {
						system("cls"); //....очищення консолі
						cout << "Семестр введено невірно" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						semester = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі
				PrintSubjectTypeByGroup(s, _size, t, _size_teachers, faculty, group, semester);

			}
			else if (_actions == 2) {
				string faculty;
				int course, semester;

				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;
				system("cls"); //....очищення консолі

				do {
					cout << "Введіть курс(1-4) для пошуку: " << endl;
					cin >> course;
					if (course < 1 || course > 4) {
						system("cls"); //....очищення консолі
						cout << "Курс введено невірно" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						course = 0;
						continue;
					}
					break;
				} while (true);
				system("cls"); //....очищення консолі

				do {
					cout << "Введіть семестр(1-2): " << endl;
					cin >> semester;
					if (semester < 1 || semester > 2) {
						system("cls"); //....очищення консолі
						cout << "Семестр введено невірно" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						semester = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі
				PrintSubjectTypeByCourse(s, _size, t, _size_teachers, faculty, course, semester);

			}
			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			TeachersMenu();
			break;
//________________________________________________________________________________	
		case 7:
			system("cls"); //....очищення консолі

			if (_size_teachers != 0) {
				string group, subject;
				int semester;

				cout << "Введіть групу для пошуку: " << endl;
				cin >> group;
				system("cls"); //....очищення консолі

				cout << "Введіть дисципліну для пошуку: " << endl;
				cin >> subject;
				system("cls"); //....очищення консолі

				do {
					cout << "Введіть семестр(1-2): " << endl;
					cin >> semester;
					if (semester < 1 || semester > 2) {
						system("cls"); //....очищення консолі
						cout << "Семестр введено невірно" << endl;
						system("pause"); //....затримка консолі
						system("cls"); //....очищення консолі
						semester = 0;
						continue;
					}
					break;
				} while (true);

				system("cls"); //....очищення консолі
				PrintExamTeachers(t, _size_teachers, group, subject, semester);
			}
			else
				cout << "Дані порожні " << endl;

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			TeachersMenu();
			break;
//________________________________________________________________________________
		case 8:
			system("cls"); //....очищення консолі

			cout << " Шукати за (1)факультетом, (2)кафедрою чи (3)типом" << endl;
			cin >> _actions;
			system("cls"); //....очищення консолі


			if (_actions == 1) {
				string faculty;

				cout << "Введіть факультет для пошуку: " << endl;
				cin >> faculty;
				system("cls"); //....очищення консолі

				PrintKerivnkDuplomByFaculty(t, _size_teachers, faculty);
			}
			else if (_actions == 2) {
				string kafedra;

				cout << "Введіть кафедру для пошуку: " << endl;
				cin >> kafedra;
				system("cls"); //....очищення консолі

				PrintKerivnkDuplomByKafedra(t, _size_teachers, kafedra);
			}
			else if (_actions == 3) {
				string type;

				cout << "Введіть тип викладача для пошуку: " << endl;
				cin >> type;
				system("cls"); //....очищення консолі

				PrintKerivnkDuplomByType(t, _size_teachers, type);
			}
			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			TeachersMenu();
			break;
//________________________________________________________________________________
		case 9:
			system("cls"); //....очищення консолі

			cout << "Отримати (1)навантаження викладачів, (2)обсяг на окремі види занять, (3)загальне навантаження в зазначеному семестрі для конкретного викладача або для викладачів зазначеної кафедри" << endl;
			cin >> _actions;
			system("cls"); //....очищення консолі

			if (_actions == 1) {
				PrintTeachersWork(t, _size_teachers);
			}
			else if (_actions == 2) {
				PrintSubjectHours(t, _size_teachers);
			}
			else if (_actions == 3) {
				cout << "Для (1)конкретного викладача для (2)кафедри" << endl;
				cin >> _actions;
				system("cls"); //....очищення консолі
				if (_actions == 1) {
					string  teacherlastname, teachername;
					int semester;

					cout << "Введіть прізвище та ім'я викладача" << endl;
					cin >> teacherlastname >> teachername;
					system("cls"); //....очищення консолі

					do {
						cout << "Введіть семестр(1-2): " << endl;
						cin >> semester;
						if (semester < 1 || semester > 2) {
							system("cls"); //....очищення консолі
							cout << "Семестр введено невірно" << endl;
							system("pause"); //....затримка консолі
							system("cls"); //....очищення консолі
							semester = 0;
							continue;
						}
						break;
					} while (true);

					system("cls"); //....очищення консолі
					PrintTeachersHoursBySemester(t, _size_teachers, semester, teacherlastname, teachername);
				}
				else if (_actions == 2) {
					int semester; 
					string kafedra;

					cout << "Введіть кафедру для пошуку: " << endl;
					cin >> kafedra;
					system("cls"); //....очищення консолі

					do {
						cout << "Введіть семестр(1-2): " << endl;
						cin >> semester;
						if (semester < 1 || semester > 2) {
							system("cls"); //....очищення консолі
							cout << "Семестр введено невірно" << endl;
							system("pause"); //....затримка консолі
							system("cls"); //....очищення консолі
							semester = 0;
							continue;
						}
						break;
					} while (true);

					system("cls"); //....очищення консолі
					PrintKafedraByHours(t, _size_teachers, semester, kafedra);
				}
			}

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			TeachersMenu();
			break;
//________________________________________________________________________________
		case 10:
			system("cls"); //....очищення консолі

			if (_size_teachers != 0)
				SaveTeachers(t, _size_teachers, "Teachers1.txt");
			else
				cout << " Дані порожні " << endl;

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			TeachersMenu();
			break;
//________________________________________________________________________________
		default:
			system("cls"); //....очищення консолі
			cout << " Пункт меню введено невірно " << endl;
			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			TeachersMenu();
			break;

		}
	}
	system("cls"); //....очищення консолі
	cout << " Робота завершена " << endl;
	system("pause"); //....затримка консолі
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu();
	while (_Menu != 0) {
		switch (_Menu) {
			//________________________________________________________________________________
		case 1:
			system("cls"); //....очищення консолі

			StudentsMenu();

			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			Menu();
			break;
			//________________________________________________________________________________
		case 2:
			system("cls"); //....очищення консолі

			TeachersMenu();
			
			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			Menu();
			break;
			//________________________________________________________________________________
		default:
			system("cls"); //....очищення консолі
			cout << " Пункт меню введено невірно " << endl;
			system("pause"); //....затримка консолі
			system("cls"); //....очищення консолі
			Menu();
			break;

		}
	}
	system("cls"); //....очищення консолі
	cout << " Робота завершена " << endl;
	system("pause"); //....затримка консолі	
}