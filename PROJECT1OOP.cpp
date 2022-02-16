#include <iostream>

using namespace std;

const int LNAME = 25;

class STUDENT {

private: //закрытые члены класса
	char name[LNAME];
	int age;
	float grade;//рейтинг
public:    //открытые члены класса
	STUDENT() {    //создание конструктора                      
		for (int i = 0; i <= 25; i++) {
			name[i] = 0;   //заполнение 0 во избежание появления "мусора"
		}
		int age = 0;
		float grade = 0;
	}
	char* GetName() {  //получение имени
		return name;
	};
	int GetAge() const {  //получение возраста
		return age;
	};
	float GetGrade() const {  //получение рейтинга
		return grade;
	};
	void SetName(char* name) {  //установка имени
		int i = 0;
		while (*name != 0) {//посимвольный перебор всего имени
			this->name[i] = *name; //присваивание его массиву
			name++; //переход на следующий символ,
			i++;
		}
	};
	void SetAge(int age) {  //установка возраста
		this->age = age;
	};
	void SetGrade(float grade) { //установка рейтинга 
		this->grade = grade;
	};
	void Set(char* name, int age, float greade) {  // установка всех трех полей
		int i = 0;
		while (*name != 0) {
			this->name[i] = *name;
			name++;
			i++;
		}
		this->grade = grade;
		this->age = age;

	};
	void Show() {   // отображение информации о студенте 
		setlocale(LC_ALL, "Russian");
		cout << "Имя студента - " << name << endl;
		cout << "Возраст студента - " << age << endl;
		cout << "Рейтинг студента - " << grade << endl;
	};
};
int main() {
	STUDENT student; //объект класса STUDENT 
	setlocale(LC_ALL, "Russian");
	char name[LNAME];
	int age;
	float grade;
	//вывод результатов, проверка каждого метода(функции)
	cout << "Введите имя студента не превышающее 24 символа ";
	cin >> name;
	cout << "Введите возраст студента ";
	cin >> age;
	cout << "Введите рейтинг студента ";
	cin >> grade;
	cout << endl;
	student.SetName(name);
	cout << "Имя студента - " << student.GetName() << endl;
	student.SetAge(age);
	cout << "Возраст студента - " << student.GetAge() << endl;
	student.SetGrade(grade);
	cout << "Рейтинг студента - " << student.GetGrade() << endl;
	student.Set(name, age, grade);
	cout << endl;
	cout << "Результат работы Set и Show " << endl << endl;
	student.Show();
}