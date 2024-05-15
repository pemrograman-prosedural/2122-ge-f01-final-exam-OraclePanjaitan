#include "dorm.h"
#include <string.h>
#include <stdio.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
    struct dorm_t dorm_;

    strcpy (dorm_.name,_name);
    dorm_.capacity=_capacity;  
    dorm_.gender=_gender;
    dorm_.residents_num = 0;    
    return dorm_; 
}