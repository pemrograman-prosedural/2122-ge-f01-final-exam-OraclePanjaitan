#include "student.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct student_t create_student(char *_id, char *_name, char *_year,enum gender_t _gender)
{
  struct student_t std;

  strcpy(std.id, _id);
  strcpy(std.name, _name);
  strcpy(std.year, _year);
  std.gender=_gender;
  strcpy(std.asrama,"unassigned");
  
  return std;
}

void print_studs(struct student_t *_students, int size)
{
  for (int j = 0; j < size-3; j++)
    {
        if(_students[j].gender == 1)
        {
            printf("%s|%s|%s|female|%s\n", _students[j].id, _students[j].name, _students[j].year, _students[j].asrama);
        }
        else
        {
            printf("%s|%s|%s|male|%s\n", _students[j].id, _students[j].name, _students[j].year,_students[j].asrama);
        }
    }
}