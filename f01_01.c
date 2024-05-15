// 12S23032 - Seprian Martinus Siagian
// 12S23037 - Oracle Tio Panjaitan

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv) 
{
    struct student_t *students = malloc(12 * sizeof(struct student_t));
    struct dorm_t *dorms = malloc(12 * sizeof(struct dorm_t));
    char data[100];
    char id[12];
    char name[40];
    char year[5];
    const char div[2] = "#";
    char dname[40];
    // unsigned short capacity;
    char *token;
    char aid[40];
    char adorm[40];
    char arrayId[255];
    int j = 0;
    int n = 0;
    int i = 0;
    char left[40];
    
    do
    {
        data[0] = '\0';
        int k = 0;
        while (1==1)
        {
            char i = getchar();
            if (i == '\n')
            {
                break;
            }
            if (i == '\r')
            {
                continue;
            }
            data[k] = i;
            data[++k] = '\0';
        }

        token = strtok(data, div);
        if(strcmp(token, "---")==0)
        {
            break;
        }
        else if (strcmp(token, "student-add")== 0)
        {
            // token = strtok(data, div);
            token = strtok(NULL, div);
            strcpy(id, token);
            strcpy(arrayId, token);
            token = strtok(NULL, div);
            strcpy(name, token);
            token = strtok(NULL, div);
            strcpy(year, token);
            token = strtok(NULL, div);
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
            token = strtok(NULL, div);
            strcpy(dname, token);
            token = strtok(NULL, div);
            unsigned short capacity = atoi(token);
            token = strtok(NULL, div);
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
            token = strtok(NULL, div);
            strcpy(aid, token);
            token = strtok(NULL, div);
            strcpy(adorm, token);
            // printf("%s\n", students[0].id);
            // printf("%s\n",aid);
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
            token = strtok(NULL, div);
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

