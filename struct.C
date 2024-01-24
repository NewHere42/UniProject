#include <stdio.h>
#include <string.h>

struct student
{
    int marks;
    int id;
    char name[10];
}s[10];


void insert();
void display( struct student * );
void seek();
void descendingOrder(int *, int []);





int main()
{
    int choice;

  
    do
    {
        printf("1. Insert student record\n");
        printf("2. Seek a student's record\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            seek();
        default:
            break;
        
        
        }


    } while (choice != 3);
    return 0;
}


void insert()
{
   
    FILE *fp;
    
    int n, i, a[10];

    printf("Enter size of array\n");
    scanf("%d", &n);

     fp = fopen("record.dat", "wb");
      for (i = 0; i < n; i++)
    {
        printf("\t\t\t\tStudent %d's record\n", i);
        printf("Enter student %d's marks\n", i);
        scanf("%d", &s[i].marks);
         a[i] = s[i].marks;

        printf("Enter student %d's id\n", i);
        scanf("%d", &s[i].id);

        printf("Enter student %d's name\n", i);
        scanf("%s", &s[i].name);

        
        fwrite(&s[i],  sizeof(struct student), 1,fp);
     
    }
    descendingOrder(&n, a );
   
    

 


    fclose(fp);

}
 void seek()
    {
        int i, searchId;
        FILE *fp;
        

        fp = fopen("record.dat", "rb+");

        printf("Enter id of student you wanna search\n");
        scanf("%d", &searchId);
        

        
        
        for(i=0; i< 10; i++)
        {
            if(s[i].id == searchId)
            {
                display(&s[i]);
            }
        }
        

        fclose(fp);
    }
void display( struct student *s)
    {
        printf("Student's marks: %d\n", s->marks);
        

        printf("Student's id: %d\n", s->id);
       

        printf("Student's name: %s\n", s->name);
     
    }

void descendingOrder(int * sizeOfArray, int a[])
{
    int i, j, temp;
    for ( i = 0; i < *sizeOfArray; i++)
    {
        for ( j = 1; j < *sizeOfArray; j++)
        {
            if(a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        
    }

    for ( i = 0; i < *sizeOfArray ; i++)
    {
        printf_s("Value %d at I:%d\n", a[i], i);
    }
}