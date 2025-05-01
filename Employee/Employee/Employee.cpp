#include <string>
#include <stdbool.h> 

//4
class Employee {
public:
	char Name[20];
	int Salary;
	int Seniority;

	Employee(const char* name, int salary, int seniority) {
		//strcpy(this->Name, name);
		strcpy_s(this->Name, sizeof(this->Name), name);
		this->Salary = salary;
		this->Seniority = seniority;
	}

	//הפכתי את הפונקציות לסטטיות ולגנריות  
	//הסיבה לסטטית:
	// חייבת להיות פונקציה חופשית או פונקציה סטטית qsort -פונקציית ההשוואה שמועברת ל
	//הסיבה לגנרית:
	//תוכל לעבוד באופן גנרי עם כל סוג מערך qsort-כדי ש

	static int CompareEmployeeBySalary(const void* a, const void* b) {
		const Employee* emp1 = *(const Employee**)a;
		const Employee* emp2 = *(const Employee**)b;

		if (emp1->Salary < emp2->Salary) return -1;
		if (emp1->Salary > emp2->Salary) return 1;
		return 0;
	}
	/*static int CompareEmployeeBySalary(Employee* e1, Employee* e2) {
		if (e1->Salary < e2->Salary)
			return -1;
		else if (e1->Salary > e2->Salary)
			return 1;
		else
			return 0;
	}*/

	static int CompareEmployeeBySeniority(const void* a, const void* b) {
		const Employee* emp1 = *(const Employee**)a;
		const Employee* emp2 = *(const Employee**)b;

		if (emp1->Seniority < emp2->Seniority) return -1;
		if (emp1->Seniority > emp2->Seniority) return 1;
		return 0;
	}
	/*static int CompareEmployeeBySeniority(Employee* e1, Employee* e2) {
		if (e1->Seniority < e2->Seniority)
			return -1;
		else if (e1->Seniority > e2->Seniority)
			return 1;
		else
			return 0;
	}*/
	static int compereEmployeeByName(const void* a, const void* b) {
		const Employee* empA = *(const Employee**)a;
		const Employee* empB = *(const Employee**)b;

		return strcmp(empA->Name, empB->Name);
	}
	
	static int compereEmployeeByNameForB(const void* key, const void* elem) {
		return strcmp(((const Employee*)key)->Name, (*(const Employee**)elem)->Name);
	}
	/*static int compereEmployeeByName(Employee* e1, Employee* e2) {
		return strcmp(e1->Name, e2->Name);
	}*/
};

int main() {
	Employee* arrEmployee[5] = {
		new Employee("Alice", 90000, 3),
		new Employee("Bob", 75000, 5),
		new Employee("Charlie", 55000, 2),
		new Employee("David", 80000, 7),
		new Employee("Eve", 70000, 4),
	};

	//מיון לפי משכורת
	qsort(arrEmployee, 5, sizeof(Employee*), Employee::CompareEmployeeBySalary);
	printf("Employees sorted by salary:\n");
	for (int i = 0; i < 5; ++i) {
		printf("Name: %s, Salary: %d,Seniority: %d\n", arrEmployee[i]->Name, arrEmployee[i]->Salary, arrEmployee[i]->Seniority);
	}
	printf("\n");


	//מיון לפי ותק
	qsort(arrEmployee, 5, sizeof(Employee*), Employee::CompareEmployeeBySeniority);
	printf("Employees sorted by Seniority:\n");
	for (int i = 0; i < 5; ++i) {
		printf("Name: %s, Salary: %d,Seniority: %d\n", arrEmployee[i]->Name, arrEmployee[i]->Salary, arrEmployee[i]->Seniority);
	}
	printf("\n");


	//מיון לפי שם
	qsort(arrEmployee, 5, sizeof(Employee*), Employee::compereEmployeeByName);
	printf("Employees sorted by Name:\n");
	for (int i = 0; i < 5; ++i) {
		printf("Name: %s, Salary: %d,Seniority: %d\n", arrEmployee[i]->Name, arrEmployee[i]->Salary, arrEmployee[i]->Seniority);
	}
	printf("\n");


	// בדיקה באמצעות bsearch (מחייב שהמערך ממוין לפי שם)
	//בדיקה אם עובד שקיים -קיים במערך
	Employee keyFound("Bob", 0, 0); // אין חשיבות לשכר וותק
	Employee* foundPtr = (Employee*)bsearch(&keyFound, arrEmployee, 5, sizeof(Employee*), Employee::compereEmployeeByNameForB);
	if (foundPtr != NULL) {
		printf("Employee with name '%s' found using bsearch.\n", keyFound.Name);
	}
	else {
		printf("Employee with name 'Bob' not found using bsearch.\n");
	}

	//בדיקה אם עובד שלא שקיים -קיים במערך
	Employee keyNotFound("Charlie Brown", 0, 0); // אין חשיבות לשכר וותק
	foundPtr = (Employee*)bsearch(&keyNotFound, arrEmployee, 5, sizeof(Employee*), Employee::compereEmployeeByNameForB);
	if (foundPtr != NULL) {
		printf("Employee with name '%s' found using bsearch.\n", keyFound.Name);
	}
	else {
		printf("Employee with name 'Charlie Brown' not found using bsearch.\n");
	}

	// חשוב לשחרר את הזיכרון שהוקצה
	for (int i = 0; i < 5; ++i) {
		delete arrEmployee[i];

	}
}