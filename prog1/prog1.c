#include <stdio.h>

struct Student
{
    int id;
    char name[20];
    float marks;
};

void displayRecord(int m)
{
    FILE *fp;
    struct Student s;

    fp = fopen("student.dat", "rb");

    if(fp == NULL)
    {
        printf("File not found.\n");
        return;
    }

    fseek(fp, (m - 1) * sizeof(struct Student), SEEK_SET);

    if(fread(&s, sizeof(struct Student), 1, fp))
    {
        printf("\nRecord %d Details:\n", m);
        printf("ID = %d\n", s.id);
        printf("Name = %s\n", s.name);
        printf("Marks = %.2f\n", s.marks);
    }
    else
    {
        printf("Invalid record number.\n");
    }

    fclose(fp);
}

void deleteRecord(int delId)
{
    FILE *fp, *temp;
    struct Student s;
    int found = 0;

    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if(fp == NULL || temp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    while(fread(&s, sizeof(struct Student), 1, fp))
    {
        if(s.id != delId)
        {
            fwrite(&s, sizeof(struct Student), 1, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if(found)
        printf("Record deleted successfully.\n");
    else
        printf("Record not found.\n");
}

int main()
{
    FILE *fp;
    struct Student s;
    int n, i, m, delId;

    fp = fopen("student.dat", "wb");

    if(fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("Enter number of records: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter ID, Name, Marks: ");
        scanf("%d %s %f", &s.id, s.name, &s.marks);

        fwrite(&s, sizeof(struct Student), 1, fp);
    }

    fclose(fp);

    printf("\nEnter record number to display: ");
    scanf("%d", &m);

    displayRecord(m);

    printf("\nEnter ID to delete: ");
    scanf("%d", &delId);

    deleteRecord(delId);

    return 0;
}