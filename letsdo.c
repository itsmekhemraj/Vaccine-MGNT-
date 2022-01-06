#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define no_of_vaccine 100
void menu();
void newRecord();
void holdon();
void vaccineDate();
void search();
void availableFirst();
void availableSecond();
void firstDose();
void secondDose();
int lwr = 11111, upr = 99999, no_of_patients = 0;
int password();

struct record
{
    char name[30], gender, profession[20], address[20], conf, cont;
    int age, bp, random, temperature;
    unsigned long long phone;
};

int main()
{
    int k = 3;
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\tDeveloped By:- Khemraj Shrestha ");
    printf("\t\n\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n Press any key to continue.............  ");
    getch();
start:
    system("cls");
    printf("\n\n\t\t\t\t\t\t*********************************************");
    printf("\n\t\t\t\t\t\t\tEnter User name and Password\n");
    printf("\t\t\t\t\t\t*********************************************\n");
    while (k >= 1)
    {

        int c = password();
        if (c == 1)
        {
            menu();
            break;
        }
        else
            printf("\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only %d times more", k - 1);
        k--;
        if (k < 1)
        {
            for (int i = 59; i >= 0; i--)
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!");
                printf("\n\n\n\n\n\n\t\t\t\t\tTRY AFTER %d SECONDS.....", i);
                Sleep(1000);
            }
            k = 3;
            goto start;
        }
    }
}

int password()
{
    char cname[30], pass[20];
    int ch, i = 0, cap = 0, capt = 0;
    printf("\n\n\n\n\n\t\t\t\t\tUSER NAME:  ");
    fflush(stdin);
    gets(cname);
    printf("\n\t\t\t\t\tPASSWORD:    ");
    while ((ch = getch()) != 13)
    {
        printf("*");
        pass[i] = ch;
        i++;
    }
    pass[i] = '\0';
    srand(time(0));
    cap = (rand() % (upr - lwr + 1)) + lwr;
    printf("\n\n\t\t\t\t AUTO GENERATED NUMBER:->  %d", cap);
    printf("\n\n\n\n\t\tPlease enter the valid auto_generated number :-   ");
    scanf("%d", &capt);
    if ((strcmp(cname, "admin") == 0) && (strcmp(pass, "admin") == 0) && cap == capt)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void menu()
{
run:
    system("cls");
    int n1;
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t\t\t  MENU");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\n\n\n\t\t\t\t\t\t1: Add NEW Record\t\t\t 2: View Vaccine Data");
    printf("\n\n\n\n\t\t\t\t\t\t3: Search   \t\t\t\t 4: Exit");
    printf("\n\n\n\t\t\t\t\t\t\t\t\tChoice:- ");
    scanf("%d", &n1);
    switch (n1)
    {
    case 1:
        newRecord();
        break;
    case 2:
    {
        vaccineDate();
        break;
    }
    case 3:
    {
        search();
        break;
    }
    case 4:
    {
        printf("\n\n\n\n\n\n\t\t\t\t\t\tThank you for giving your valuable time for us. \n\t\t\t\t\t\t\t\t HAVE A GOOD DAY\n\n\n\n\n\n");
        exit(0);
    }
    default:
    {
        printf("\n\t\tWrong choice \n");
        char ch1;
        printf("\n\t\tWanna stay in this page(y/n)?:- ");
        scanf(" %c", &ch1);
        if (ch1 == 'y' || ch1 == 'Y')
        {
            goto run;
        }
    }
    }
}

void newRecord()
{
run2:
    system("cls");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t\t  RECORD INSERTING ZONE");
    printf("\n\t\t\t\t\t\t\t*****************************************\n\n");
    printf("\n\n\n\t\t\t\t\t\t1: First Dose\t\t\t 2: Second Dose");
    printf("\n\n\n\n\t\t\t\t\t\t3: Back");
    int n2;
    printf("\n\n\n\n\t\t\t\t\t\t\t\tChoice:- ");
    scanf("%d", &n2);
    switch (n2)
    {
    case 1:
    {
        firstDose();
        break;
    }
    case 2:
    {
        secondDose();
        break;
    }
    case 3:
    {
        menu();
        break;
    }
    default:
    {
        printf("\n\t\tWrong choice \n");
        char chy;
        printf("\n\t\tWanna stay in this page(y/n)?:- ");
        scanf(" %c", &chy);
        if (chy == 'y' || chy == 'Y')
        {
            goto run2;
        }
        else
        {
            exit(0);
        }
    }
    }
}

void firstDose()
{
    FILE *fpt;
    fpt = fopen("hold.txt", "r");
    if (fpt == NULL)
    {
        holdon();
    }
    else
    {
        fscanf(fpt, "%d", &no_of_patients);
        if (no_of_vaccine > no_of_patients)
        {
            holdon();
        }
        else
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\t\t\t\t(Sorry! Vaccine is finished. We will let you know after the vaccine will arrived.)\n\n\n");
            exit(0);
        }
    }
    fclose(fpt);
}

void holdon()
{
    system("cls");
    FILE *fp;
    fp = fopen("record.txt", "a");
    if (fp == NULL)
    {
        printf("\n\t\tError opening the file");
        exit(0);
    }
    else
    {
        system("cls");
        struct record rec;
        printf("\n\t\t\t\t\t\t\t*****************************************\n");
        printf("\t\t\t\t\t\t\t\t  FIRST DOSE VACCINE");
        printf("\n\t\t\t\t\t\t\t*****************************************\n\n");
        fflush(stdin);
        printf("\n\t\t Enter your name :-  ");
        gets(rec.name);
        fflush(stdin);
        printf("\n\t\t Enter your gender (M|F) :-  ");
        scanf("%c", &rec.gender);
        fflush(stdin);
        printf("\n\t\t Enter your age:- ");
        scanf("%d", &rec.age);
        fflush(stdin);
        printf("\n\t\t Enter your profession :-  ");
        gets(rec.profession);
        fflush(stdin);
        printf("\n\t\t Enter your diastolic blood pressure(B.P) :-  ");
        scanf("%d", &rec.bp);
        fflush(stdin);
        printf("\n\t\t Enter your Body temperature (Fahrenheit):-  ");
        scanf("%d", &rec.temperature);
        fflush(stdin);
        printf("\n\t\t Enter your permanent address :-  ");
        gets(rec.address);
        fflush(stdin);
        printf("\n\t\t Enter your Mobile number:- ");
        scanf("%llu", &rec.phone);
        fflush(stdin);
        srand(time(0));
        rec.random = (rand() % (upr - lwr + 1)) + lwr;
        printf("\n\n\n\t\t\t\t\t\t\t Your unique number:- %d", rec.random);
        printf("\n\t\t\t\t\t (YOU HAVE TO REMEMBER YOUR UNIQUE NUMBER FOR SECOND DOSE)");
        fflush(stdin);
        rec.conf = '.';
        fwrite(&rec, sizeof(rec), 1, fp);
        fclose(fp);

        FILE *fp;
        char chu;
        no_of_patients=0;
        fp = fopen("record.txt", "r");
        if (fp == NULL)
        {
            printf("\n\t\tError opening the file");
            exit(0);
        }
        chu = fgetc(fp);
        while (!feof(fp))
        {
            chu = fgetc(fp);
            if (chu == '.')
            {
                
                no_of_patients++;
            }
        }
        fclose(fp);

        FILE *fpt;
        fpt = fopen("hold.txt", "w");
        fprintf(fpt, "%d", no_of_patients);
        fclose(fpt);

        printf("\t\n\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n Press any key to continue...  ");
        getch();
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t%s! Your first dose is done. \n\n\t\t\t\t\t\t\t\t (PLEASE COME AFTER 30 DAYS FOR SECOND DOSE) \n\n\n\n\n\n\n\n", rec.name);
        printf("\t\n\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n Press any key to return HOMEPAGE.............  ");
        getch();
        menu();
    }
}

void secondDose()
{
    int chkt = 0;
    time_t tim;
    time(&tim);
    FILE *fp;
    fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t\tError opening file");
        exit(1);
    }
    struct record rec;
    int no_tally, count = 0;
    system("cls");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t\t  SECOND DOSE VACCINE");
    printf("\n\t\t\t\t\t\t\t*****************************************\n\n");
    printf("\n\n\n\t\t\t\t\t\t\tEnter your unique number:- ");
    scanf("%d", &no_tally);
    while (fread(&rec, sizeof(rec), 1, fp) == 1)
    {
        if (no_tally == rec.random)
        {

            chkt++;
            count = 1;
            system("cls");
            printf("\n\n\n\t\t\t\t\tHello! %s", rec.name);
            printf("\n\n\n\n\t\t\t\t\t\t\tCONGRATULATION! You have taken both dose of vaccine.\n\n\t\t\t\t\t\t\t\t\t STAY HOME STAY SAFE\n");
            printf("\n\n\n\n\n\t\t\t\t\t\t\t\tDate:- %s", ctime(&tim));
        }
    }
    if (!count)
    {
        printf("\n\n\n\t\t\t(Either your have entered mistake UNIQUE number or You have to take your first dose in order to take second dose)");
    }
    fclose(fp);

    if (chkt != 0)
    {
        struct record rec;
        FILE *fp;
        fp = fopen("record.txt", "a");
        rec.cont = '+';
        fwrite(&rec, sizeof(rec), 1, fp);
        fclose(fp);
    }
    
    printf("\t\n\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n Press any key to return HOMEPAGE.............  ");
    getch();
    menu();
}

void search()
{
    FILE *fp;
    fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t\tError opening file");
        exit(1);
    }
    int counter = 0;
    struct record rec;
    char pt_name[25], cht;
    int pt_age;
    system("cls");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t\t\t  SEARCH");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\n\n\n\t\t\t\t\t\t\tEnter name of patient:- ");
    fflush(stdin);
    gets(pt_name);
    printf("\n\n\t\t\t\t\t\t\tAge:- ");
    fflush(stdin);
    scanf("%d", &pt_age);
    while (fread(&rec, sizeof(rec), 1, fp) == 1)
    {
        if (((strcmp(pt_name, rec.name)) == 0) && (pt_age == rec.age))
        {
            counter = 1;
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t\t\t\tName=>   %s\n", rec.name);
            printf("\n\t\t\t\t\t\t\tGender=>   %c\n", rec.gender);
            printf("\n\t\t\t\t\t\t\tAge=>   %d\n", rec.age);
            printf("\n\t\t\t\t\t\t\tProfession=>   %s\n", rec.profession);
            printf("\n\t\t\t\t\t\t\tBlood Pressure=>   %d\n", rec.bp);
            printf("\n\t\t\t\t\t\t\tBody Temperature=>   %d\n", rec.temperature);
            printf("\n\t\t\t\t\t\t\tPermanent Address=>   %s\n", rec.address);
            printf("\n\t\t\t\t\t\t\tPhone Number=>   %llu\n", rec.phone);
        }
    }
    if (!counter)
    {
        printf("\n\n\n\t\t\t\t\t\t(This person is not vaccoinated from this hospital)");
    }
    fclose(fp);
    printf("\t\n\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n Press any key to return HOMEPAGE.............  ");
    getch();
    menu();
}

void vaccineDate()
{
run:
    system("cls");
    int n2;
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t\t  VACCINE STATISTICS");
    printf("\n\t\t\t\t\t\t\t*****************************************\n\n");
    printf("\n\n\n\t\t\t\t\t\t1: 1st Dose\t\t\t 2: 2nd Dose");
    printf("\n\n\n\n\t\t\t\t\t\t3: Back");
    printf("\n\n\n\t\t\t\t\t\t\t\t\tChoice:- ");
    scanf("%d", &n2);
    switch (n2)
    {
    case 1:
    {
        availableFirst();
        break;
    }
    case 2:
    {
        availableSecond();
        break;
    }
    case 3:
    {
        menu();
        break;
    }
    default:
    {
        printf("\n\t\tWrong choice \n");
        char ch;
        printf("\n\t\tWanna stay in this page(y/n)?:- ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y')
            goto run;
        else
            exit(0);
    }
    }
}

void availableFirst()
{
    struct record rec;
    FILE *fp;
    char ch;
    fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t\tError opening the file");
        exit(0);
    }
    ch = fgetc(fp);
    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (ch == '.')
        {
            no_of_patients++;
        }
    }
    system("cls");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t\t   1st DOSE DONE");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\n\n\n\n\t\t\t\t\t\tNumber of people who got first dose:- %d", no_of_patients);
    fclose(fp);
}

void availableSecond()
{
    FILE *fp;
    char cht;
    int rem_vaccine = 0, no_of_patients2 = 0;
    fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t\tError opening the file");
        exit(0);
    }
    cht = fgetc(fp);
    while (!feof(fp))
    {
        cht = fgetc(fp);
        if (cht == '+')
        {
            no_of_patients2++;
        }
    }
    rem_vaccine = no_of_vaccine - no_of_patients2;
    system("cls");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t\t   2nd DOSE DONE");
    printf("\n\t\t\t\t\t\t\t*****************************************\n");
    printf("\n\n\n\n\t\t\t\t\t\tNumber of people who got both vaccine:- %d", no_of_patients2);
    printf("\n\n\t\t\t\t\t\tAvailable number of vaccine are:- %d \n\n\n\n\n\n", rem_vaccine);
    fclose(fp);
    printf("\t\n\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n Press any key to return HOMEPAGE.............  ");
    getch();
    menu();
}