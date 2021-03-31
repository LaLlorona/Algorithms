#include <bits/stdc++.h>

using namespace std;

#define NAME_SIZE 50
class Person {
	int id;
	char name[NAME_SIZE];

	public:
		virtual bool addCourse(string s) = 0;

		virtual ~Person() {
			cout << "deleting a person.\n";
		}
		
};
class Student : public Person {
	public:
		void aboutMe() {
			cout << "I am a student\n";
		}

		bool addCourse(string s) {
			cout << "Added course " << s << " to student.\n";
			return true;
		}

		~Student() {
			cout << "deleting a student\n";
		}
};

int main()
{
  // std::ios_base::sync_with_stdio(false);
  // std::cin.tie(NULL);
  // std::cout.tie(NULL);

	
	Person* a_student = new Student();
	a_student->addCourse("mathematics");
	delete a_student;

	// Person* a_person = new Person();
	// a_person->addCourse("asdf");
	// a_student->onlyStudent();

  
  

  return 0;
}
