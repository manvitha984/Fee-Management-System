#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct link
{
    char name[100];
    char fathername[100];
    char mothersname[100];
    char rollnumber[100];
    char section[100];
    int clgfee;
    int busfee;
    int paidfee;
    int totalfee;
    int remainingfee;
    int scholarshipamount;
    struct link *next;
};

struct link *start;

void create(struct link *);
void display(struct link *);
void scholarshiprec(struct link *);
void remainingfee(struct link *);
void section(struct link *);

int main()
{
    int c;
    struct link *node;
    node = (struct link *)malloc(sizeof(struct link));
    start = node;
    if (node == NULL)
    {
        printf("No info\n");
        return 1;
    }
    else
    {
        printf("Press 1 to create\n");
        printf("Press 2 to print the student name with due fee\n");
        printf("Press 3 to print students names receiving scholarship amount\n");
        printf("Press 4 to print the student names belonging to csd section\n");
        printf("Press 5 for exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        int ch = 1;
        while (ch)
        {
            switch (c)
            {
            case 1:
                create(start);
                display(start);
                break;
            case 2:
                remainingfee(start);
                break;
            case 3:
                scholarshiprec(start);
                break;
            case 4:
                section(start);
                break;
            case 5:
                ch = 0;
                break;
            default:
                printf("Wrong choice. Try again.\n");
                break;
            }
            if (ch)
            {
                printf("Press 1 to create\n");
                printf("Press 2 to print the student name with due fee\n");
                printf("Press 3 to print students names receiving scholarship amount\n");
                printf("Press 4 to print the student names belonging to csd section\n");
                printf("Press 5 for exit\n");
                printf("Enter your choice: ");
                scanf("%d", &c);
            }
        }
    }

    return 0;
}

void create(struct link *node)
{
    char ch;
    printf("Enter name: ");
    scanf(" %[^\n]", node->name);

    printf("Enter father's name: ");
    scanf(" %[^\n]", node->fathername);

    printf("Enter mother's name: ");
    scanf(" %[^\n]", node->mothersname);

    printf("Enter roll number: ");
    scanf(" %[^\n]", node->rollnumber);

    printf("Enter section: ");
    scanf(" %[^\n]", node->section);

    printf("Enter college fee: ");
    scanf("%d", &node->clgfee);

    printf("Enter bus fee: ");
    scanf("%d", &node->busfee);

    printf("Enter paid fee: ");
    scanf("%d", &node->paidfee);

    node->totalfee = node->clgfee + node->busfee;
    node->remainingfee = node->totalfee - node->paidfee;

    printf("Enter scholarship amount: ");
    scanf("%d", &node->scholarshipamount);

    node->next = NULL;

    printf("Enter 'n' to stop or any other character to continue: ");
    scanf(" %c", &ch);
    while (ch != 'n')
    {
        node->next = (struct link *)malloc(sizeof(struct link));
        node = node->next;

        printf("Enter name: ");
        scanf(" %[^\n]", node->name);

        printf("Enter father's name: ");
        scanf(" %[^\n]", node->fathername);

        printf("Enter mother's name: ");
        scanf(" %[^\n]", node->mothersname);

        printf("Enter roll number: ");
        scanf(" %[^\n]", node->rollnumber);

        printf("Enter section: ");
        scanf(" %[^\n]", node->section);

        printf("Enter college fee: ");
        scanf("%d", &node->clgfee);

        printf("Enter bus fee: ");
        scanf("%d", &node->busfee);

        printf("Enter paid fee: ");
        scanf("%d", &node->paidfee);

        node->totalfee = node->clgfee + node->busfee;
        node->remainingfee = node->totalfee - node->paidfee;

        printf("Enter scholarship amount: ");
        scanf("%d", &node->scholarshipamount);

        node->next = NULL;

        printf("Enter 'n' to stop or any other character to continue: ");
        scanf(" %c", &ch);
    }
}

void display(struct link *node)
{
    printf("--------------------student details-----------------\n");
    while (node != NULL)
    {
        printf("Name of the student: %s\n", node->name);
        printf("Father's name: %s\n", node->fathername);
        printf("Mother's name: %s\n", node->mothersname);
        printf("Roll number: %s\n", node->rollnumber);
        printf("Section: %s\n", node->section);
        printf("College fee: %d\n", node->clgfee);
        printf("Bus fee: %d\n", node->busfee);
        printf("Fees paid by the student: %d\n", node->paidfee);
        printf("Remaining fee to be paid: %d\n", node->remainingfee);
        printf("Scholarship amount received by the student: %d\n", node->scholarshipamount);
        printf("------------------------------------\n");
        node = node->next;
    }
}

void remainingfee(struct link *node)
{
    printf("--------students with due fee--------------------\n");
    while (node != NULL)
    {
        if (node->remainingfee > 0)
        {
            printf("Name: %s, Remaining Fee: %d\n", node->name, node->remainingfee);
        }
        node = node->next;
    }
}

void scholarshiprec(struct link *node)
{
    printf("--------------students who received scholarship-------------\n");
    while (node != NULL)
    {
        if (node->scholarshipamount > 0)
        {
            printf("Name: %s, Scholarship Amount: %d\n", node->name, node->scholarshipamount);
        }
        node = node->next;
    }
}

void section(struct link *node)
{
    printf("------------students belonging to csd section----------------\n");
    while(node != NULL)
    {
        if(strcmp(node->section, "csd") == 0)
        {
            printf("Name: %s\n", node->name);
        }
        node = node->next;
    }
}