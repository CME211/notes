#include <string>


// Definition of the class Student
class Student
{
public:
  // Constructor
  Student(std::string name, int studentID)
  {
    name_      = name; // set break point here
    studentID_ = studentID;
  }

  // Destructor
  ~Student()
  {
    studentID_ = 0;
  }

private:
  std::string name_; // Student's name
  int studentID_;    // Student's ID number
};


int main()
{
  // The instance of Student on the stack.
  Student icmeStudent("Terry Gilliam", 123444);

  // The instance of Student on the heap.
  Student* pGeographyStudent = new Student("Terry Jones", 123555);

  delete pGeographyStudent;
    
  return 0;
}
