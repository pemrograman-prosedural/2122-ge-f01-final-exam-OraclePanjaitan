// 12S23032 - Seprian Martinus Siagian
// 12S23037 - Oracle Tio Panjaitan

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv) 
{

    // int size = 0;
    // struct dorm_t *dorms = malloc(size * sizeof(struct dorm_t));
    // int sizee = 0;
    // struct student_t *students = malloc(sizee * sizeof(struct student_t));
    struct student_t *students = malloc(67 * sizeof(struct student_t));
    struct dorm_t *dorms = malloc(25 * sizeof(struct dorm_t));
    char data[75];
    char id[12];
    char name[25];
    char year[5];
    char *token;
    int j = 0;
    int n = 0;
    int i = 0;
    char left[10];
    

    while(1)
    {
        fflush(stdin);
        fgets(data,75,stdin);
        data[strlen(data) -1] = '\0';

        token = strtok(data, "#");
        if(strcmp(token, "---")==0)
        {
            break;
        }
        else if (strcmp(token, "student-add")== 0)
        {
            // sizee++;
            // students = realloc(students, sizee * sizeof(struct student_t));
            token = strtok(NULL, "#");
            strcpy(id, token);
            token = strtok(NULL, "#");
            strcpy(name, token);
            token = strtok(NULL, "#");
            strcpy(year, token);
            token = strtok(NULL, "#");
            if (strcmp(token, "female")==0)
            {
                students[j] = create_student(id, name, year, GENDER_FEMALE);
            } 
            else if (strcmp(token, "male")==0)
            {
                students[j] = create_student(id, name, year, GENDER_MALE);  
            }
            j++;
        }
        else if (strcmp(data, "student-print-all-detail")== 0) 
        {
            print_studs(students, j);
        }

        else if(strcmp(data, "dorm-add")==0)
        {
            // size++;
            // dorms = realloc(dorms, size * sizeof(struct dorm_t));
            token = strtok(NULL, "#");
            strcpy(name, token); 
            token = strtok(NULL, "#");
            unsigned short capacity = atoi(token);
            token = strtok(NULL, "#");
            if (strcmp(token, "female")==0)
            {
                dorms[j] = create_dorm(name, capacity, GENDER_FEMALE);
            } 
            else if (strcmp(token, "male")==0)
            {
                dorms[j] = create_dorm(name, capacity, GENDER_MALE);
            }
            ++j;
        }

        else if(strcmp(data, "assign-student")==0)
        {
            token = strtok(NULL, "#");
            strcpy(id, token);
            token = strtok(NULL, "#");
            strcpy(name, token);
            if(strcmp(students[i].id, id)==0)
            {
                strcpy(students[i].asrama, name);
                
            }
            else
            {
                strcpy(students[i].asrama, "unassigned");
            }
            i++;
        }
        else if(strcmp(data, "student-leave")==0)
        {
            token = strtok(NULL, "#");
            strcpy(left, token);
           
            for(n = 0; n<j;n++)
            {
                if(strcmp(students[n].id, left)==0)
                {
                strcpy(students[n].asrama, "left");
                }
                
            }
            
        }
    
    }

    free(students);
    free(dorms);
    return 0;
}

