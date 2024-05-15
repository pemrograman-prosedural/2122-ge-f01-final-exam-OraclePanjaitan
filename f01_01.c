// 12S23032 - Seprian Martinus Siagian
// 12S23037 - Oracle Tio Panjaitan

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv) 
{
    struct student_t *students = malloc(50 * sizeof(struct student_t));
    struct dorm_t *dorms = malloc(25 * sizeof(struct dorm_t));
    char data[100];
    char id[12];
    char name[25];
    char year[5];
    char dname[20];
    char *token;
    char aid[15];
    char adorm[15];
    char arrayId[25];
    int j = 0;
    int n = 0;
    int i = 0;
    char left[10];
    

    do
    {
        fgets(data,100,stdin);
        data[strlen(data) -1] = '\0';

        token = strtok(data, "#");
        if(strcmp(token, "---")==0)
        {
            break;
        }
        else if (strcmp(token, "student-add")== 0)
        {
            token = strtok(NULL, "#");
            strcpy(id, token);
            strcpy(arrayId, token);
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
            token = strtok(NULL, "#");
            strcpy(dname, token);
            token = strtok(NULL, "#");
            unsigned short capacity = atoi(token);
            token = strtok(NULL, "#");
            if (strcmp(token, "female")==0)
            {
                dorms[j] = create_dorm(dname, capacity, GENDER_FEMALE);
            } 
            else if (strcmp(token, "male")==0)
            {
                dorms[j] = create_dorm(dname, capacity, GENDER_MALE);
            }
            ++j;
            
        }
        else if(strcmp(data, "dorm-print-all-detail")==0)
        {
            print_dorm(dorms,j);
        }
        

        else if(strcmp(data, "assign-student")==0)
        {
            token = strtok(NULL, "#");
            strcpy(aid, token);
            token = strtok(NULL, "#");
            strcpy(adorm, token);
            if(strcmp(students[i].id, aid)==0)
            {
                strcpy(students[i].asrama, adorm);
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
        
    } while (1==1);

    free(students);
    free(dorms);

    return 0;
}

