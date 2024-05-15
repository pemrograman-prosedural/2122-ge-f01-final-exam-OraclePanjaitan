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

void print_dorm(struct dorm_t *_dorm, int size)
{
    for(int i = 0; i<size ;i++)
    {
        if(_dorm[i].gender == 1)
        {
            printf("%s|%d|female|%d\n",  _dorm[i].name, _dorm[i].capacity, _dorm[i].residents_num);            
        }
        if(_dorm[i].gender == 0)
        {
            printf("%s|%d|male|%d\n",  _dorm[i].name, _dorm[i].capacity, _dorm[i].residents_num);            
        }


    }
}