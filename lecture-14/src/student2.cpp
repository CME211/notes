///
/// Composition is "has-a" relationship between classes.
/// Helps create a more modular code.
///

#include <iostream>
#include <string>
#include <cassert>

/// The class Name contains family and given names.
class Name
{
public:
  Name(const std::string givenName, const std::string familyName)
    : givenName_(givenName),
      familyName_(familyName)
  {
  }

  ~Name()
  {
  }

  std::string getName() const
  {
    return (givenName_ + " " + familyName_);
  }

private:
  std::string givenName_;
  std::string familyName_;
};



/// Declaration (definition) of the class Student
/// The Student has a Name
class Student
{
public:
  /// Constructor
  Student(std::string givenName, std::string familyName, int studentID)
    : name_(new Name(givenName, familyName)),
      studentID_(studentID)
  {
    name_ = nullptr; ///< Bug!
  }

  /// Destructor
  ~Student()
  {
  }

  /// Return a copy of the student's ID number
  int getStudentID() const
  {
    return studentID_;
  }

  /// Return a copy of student's name
  std::string getName() const
  {
    return name_->getName();
  }
  
private:
  Name* name_;    ///< Student's name
  int studentID_; ///< Student's ID number
};


int main()
{
  /// Create a geography student (who is an instance of the Student) on the heap.
  /// Pointer pGeographyStudent point to the instance of the geography student.
  Student* pGeographyStudent = new Student("Terry", "Jones", 111234);

  std::cout << "Student name: " << pGeographyStudent->getName() << ", "
            << "ID#: " << pGeographyStudent->getStudentID()  << "\n";

  /// Delete the geography student
  delete pGeographyStudent;
  return 0;
}
