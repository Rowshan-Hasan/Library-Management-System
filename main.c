//Header file list
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>

// prototype function
void heading();
void welcome_Message();
void password();
void add_book();
void book_list();
void delete_all();
void delete_book();
void issue_book();
void issue_list();
void help();
void exit_program();

// structure for books
struct books
{
    int id;
    char bookName[50];
    char authorName[50];
    int copies;
    char shelf;
    char date[12];
} b;

//structure for student information
struct student
{
    int id;
    char sName[50];
    char sDepartment[50];
    int sID;
    char bookName[50];
    char date[12];
} s;


//file create
FILE *fp;
int d = 3;   // d variable used for 3 times password

int main()
{
    //calling functions
    heading();
    welcome_Message();
    password();
    int ch;

    while(1)
    {
        system("cls");
        system("color F");
        printf(" \n\n\t\t =======================================");
        printf("\n \t\t                Main Menu               \n");
        printf(" \t\t =======================================\n");

        printf("\n \t\t 1.Add Book\n");
        printf("\n \t\t 2.Books List\n");
        printf("\n \t\t 3.Delete Book\n");
        printf("\n \t\t 4.Delete All Book Entry\n");
        printf("\n \t\t 5.Issue Book\n");
        printf("\n \t\t 6.Issued Book List\n");
        printf("\n \t\t 7.Help\n");
        printf("\n \t\t 0.Exit\n\n");

        printf(" \t\t =======================================\n");
        printf("\n\n\n \t\t Enter your choice: ");
        scanf("%d", &ch);

        //switch case allows user to choose from 0-7
        switch(ch)
        {
        case 0:
            exit_program();

        case 1:
            add_book();
            break;

        case 2:
            book_list();
            break;

        case 3:
            delete_book();
            break;

        case 4:
            delete_all();
            break;

        case 5:
            issue_book();
            break;

        case 6:
            issue_list();
            break;

        case 7:
            help();
            break;

        default:
            printf("\n\n \t\t Invalid Choice...\n");
            printf(" \t\t Try Again...\n");

        }
        printf("\n\t\t Press Any Key To Continue...");
        getch();
    }

    return 0;
}

//function for designing
void heading()
{
    system("cls");
    system("color F");
    printf("\n\n\t\t\t\t||-------------------------------------------------------||\n");
    printf("\t\t\t\t||.--.    .-._                        .----.             ||\n");
    printf("\t\t\t\t|||==|____| | |___            .---.___|""""    |_____.--.___ ||\n");
    printf("\t\t\t\t|||  |====|C| |CSE|_          |+++|=-=|_  _|-=+=-|==|---|||\n");
    printf("\t\t\t\t|||==|    |H| |   | \          |   |   |_\/ _|MATHS|  | ^ |||\n");
    printf("\t\t\t\t|||  |    |E| |   |\ \   ----   |   |=-=|_/\ _|-=+=-|  | ^ |||\n");
    printf("\t\t\t\t|||  |    |M| |   |_\ \_| || |  |   |   |    |ICT 1|  | ^ |||\n");
    printf("\t\t\t\t|||==|====| | |CSE|  \ \| '' |  |+++|=-=|""""    |-=+=-|==|---|||\n");
    printf("\t\t\t\t||`--^----'-^-^---'---`-' ""------^---^----^-----^--^---^  ||\n");
    printf("\t\t\t\t||-------------------------------------------------------||\n");
    printf("\t\t\t\t||              Book is your greatest friend             ||\n");
    printf("\t\t\t\t||-------------------------------------------------------||\n");
    printf("\n\n\n");

}

// function for welcome message
void welcome_Message()
{
    printf("\n\n");
    printf("\n\t\t\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**- \n");
    printf("\n\t\t\t\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n\t\t\t\t  =                    WELCOME                       =");
    printf("\n\t\t\t\t  =                      TO                          =");
    printf("\n\t\t\t\t  =           East West University LIBRARY           =");
    printf("\n\t\t\t\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n\t\t\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**- \n");
    printf("\n\n\t\t\t\t\tEnter Enter Key to continue.....");

    fflush(stdin);
    getchar();
}

// password function
// password is 2022160
void password()
{
    char ch;
    char pwd1[30];
    char pwd2[30] = {"2022160"};
    int i = 0;

    printf("\n \t\tEnter Password: ");
    while ((ch = _getch()) != 13)
    {
        pwd1[i] = ch;
        i++;
        printf("*");
    }
    pwd1[i] = '\0';
    printf(" \n");

    if (strcmp(pwd2,pwd1)==0)
    {
        printf("\n \t\tPassword Matched");
        printf("\n \t\tWelcome to the East West Library Management\n");
        printf("\n \t\tPress Enter key to continue...");
    }
    else
    {
        if (d==1)
        {
            printf("\n\n \t\t\t     ********Program Terminated********\a\n");
            exit(0);
        }
        d--;
        printf("\n \t\tIncorrect Password!%d times left\a\n",d);
        printf("\n \t\tPress Enter To Try Again...");

        fflush(stdin);
        getchar();
        printf("\n\n");
        password();
    }
    fflush(stdin);
    getchar();

}

// function for adding books
void add_book()
{
    system("cls");

    fp = fopen("books.txt", "ab");    // text file but binaty append

    printf(" \n\n\t\t ========================================");
    printf("\n \t\t                Add Book               \n");
    printf(" \t\t ========================================\n");

    printf(" \n\t\t Enter book id: ");
    scanf("%d", &b.id);

    printf("\n\n\t\t ==> Enter book name: ");
    fflush(stdin);
    gets(b.bookName);

    printf("\n\t\t ==> Enter author name: ");
    fflush(stdin);
    gets(b.authorName);

    printf("\n\t\t ==> Enter Book Copies:  ");
    fflush(stdin);
    scanf("%d", &b.copies);

    printf("\n\t\t ==> Enter Shelf NO: ");
    fflush(stdin);
    scanf("%d", &b.shelf);

    printf(" \t\t ========================================\n\n");
    printf(" \n\t\t Book Added Successfully !\n");

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
}

// function for seeing book list
void book_list()
{
    system("cls");
    system("color F");
    int count=0;
    printf("\n\n\t\t                    ************* View Book *************\n\n");

    //prints the view book list
    printf("\t  --------------------------------------------------------------------------------------------------\n");
    printf("\t\t%-15s %-20s %-20s %-20s %-20s \n", "Book id", "Book Name", "Author", "Copies", "Shelf No");
    printf("\t  --------------------------------------------------------------------------------------------------\n");

    fp = fopen("books.txt", "rb");
    while(fread(&b, sizeof(b), 1, fp) == 1)
    {
        printf("\t\t%-15d %-20s %-20s %-20d %-20d \n", b.id, b.bookName, b.authorName, b.copies, b.shelf);
        count = count + b.copies;
    }
    printf("\t  --------------------------------------------------------------------------------------------------\n");
    printf("\tTotal Books in the Library = %d\n\n",count);

    fclose(fp);

}

//function for deleting a single book entry
void delete_book()
{
    int id, count=0;
    system("cls");
    printf(" \n\n\t\t =================================================");
    printf("\n \t\t                Delete Book               \n");
    printf(" \n\t\t =================================================\n\n");

    printf(" \n\t\t Enter Book id to remove: ");
    scanf("%d", &id);

    FILE *ftemp;

    fp = fopen("books.txt", "rb");
    ftemp = fopen("temp.txt", "wb");  // binary file  (file name - temp.txt)

    while(fread(&b, sizeof(b), 1, fp) == 1)
    {
        if(id == b.id)
        {
            count=1;
        }
        else
        {
            fwrite(&b, sizeof(b), 1, ftemp);
        }
    }

    if(count==1)
    {
        printf(" \n\t\t Book name: %s\n",b.bookName);
        printf(" \t\t Author name: %s\n",b.authorName);
        printf(" \t\t Copies: %d\n",b.copies);
        printf(" \t\t Shelf No: %d",b.shelf);

        printf("\n\n\t\t Book ID no: %d has been deleted successfully\n", id);
    }
    else
    {
        printf("\n\t\t Book ID is not found !\n");

    }
    printf(" \n\t\t =================================================\n\n");
    fclose(fp);
    fclose(ftemp);

    remove("books.txt");
    rename("temp.txt", "books.txt");

}

//function for deleting all book list
void delete_all()
{
    char choice;
    system("cls");
    int n;
    int only_book = 0;
    int both = 1;

    printf(" \n\t\t =====================================================\n");
    printf(" \t\t                   Delete All Book               \n");
    printf(" \t\t =====================================================\n\n");

    printf(" \t\t Do you want to delete only Book list ?\n \t\t Choice = 0\n\n");
    printf(" \t\t Do you want to delete both Book list and Issue List ?\n \t\t Choice = 1\n");

    printf(" \n\t\t -----------------------------------------------------\n\n");
    printf(" \n\t\t Enter your Choice: ");
    scanf("%d", &n);

    if(n==only_book)
    {
        remove("./books.txt");
        remove("./temp.txt");
        printf(" \n\t\t Book list has been deleted ! \n");
    }
    else if(n==both)
    {
        remove("./books.txt");
        remove("./issue.txt");
        remove("./temp.txt");
        printf(" \n\t\t All book entry has been deleted ! \n");
    }

    printf(" \n\t\t =====================================================\n\n");

}

//function for issuing books to the students
void issue_book()
{
    char my_date[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(my_date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(s.date, my_date);
    int f=0;

    system("cls");
    printf(" \n\n\t\t ========================================\n");
    printf(" \t\t                Issue Book               \n");
    printf(" \t\t ========================================\n");

    printf("\n \t\t Enter Book id to issue: ");
    scanf("%d", &s.id);

    //Check if we have book of given id
    fp = fopen("books.txt", "rb");

    while(fread(&b, sizeof(b), 1, fp) == 1)
    {
        if(b.id == s.id)
        {
            strcpy(s.bookName, b.bookName);
            f=1;
            break;
        }
    }

    if(f==0)
    {
        printf("\n \t\t Book ID not found.....!\n");
        printf(" \t\t Please try again...\n\n");
        printf(" \t\t ========================================\n");
        return;
    }

    fp = fopen("issue.txt", "ab");

    printf(" \n\t\t Enter Student Name: ");
    fflush(stdin);
    gets(s.sName);

    printf(" \n\t\t Enter Student Department: ");
    fflush(stdin);
    gets(s.sDepartment);

    printf(" \n\t\t Enter Student ID: ");
    scanf("%d", &s.sID);
    printf(" \t\t ========================================\n\n\n\n\n");

    printf(" \t\t ========================================\n");
    printf(" \t\t            Confirmation Slip            \n");
    printf(" \t\t ========================================\n\n");
    printf(" \t\t Issued Book Name    : %s", s.bookName);
    printf(" \n\t\t Issued To          : %s", s.sName);
    printf(" \n\t\t Student ID         : %d", s.sID);
    printf(" \n\t\t Issue Date         : %s", s.date);
    printf(" \n\t\t ========================================\n\n");

    printf(" \t\t Book Issued Successfully !\n\n");

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}

// function for viewing the issue list
void issue_list()
{
    system("cls");
    printf("\n\n\t\t\t\t\t\t************* Issue List *************\n\n");
    printf("\n--------------------------------------------------------------------------------------------------------------------\n");
    printf("%-10s %-30s %-20s %-20s %-20s %s\n", "S.id", "Name", "Department", "ID", "Book Name", "Date");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");

    fp = fopen("issue.txt", "rb");
    while(fread(&s, sizeof(s), 1, fp) == 1)
    {

        printf("%-10d %-30s %-20s %-20d %-20s %s\n", s.id, s.sName, s.sDepartment, s.sID, s.bookName, s.date);

    }
    printf("\n------------------------------------------------------------------------------------------------------------------\n\n");

    fclose(fp);
}

//function help contains the basic contact information
void help()
{
    system("cls");
    printf(" \t\t ==================================================\n");
    printf(" \t\t                 Help !                 \n");
    printf(" \t\t ==================================================\n");

    printf(" \n\t\t Hotline Number            :  09666775577\n");
    printf(" \n\t\t Librarian, Head of Library:  Ext. 235\n");
    printf(" \n\t\t Circulation & Information :  Ext. 210\n");
    printf(" \n\t\t Purchase Suggestion       :  Ext. 265\n");
    printf(" \n\t\t Online Services/Website   :  Ext. 353\n");
    printf(" \n\t\t Circulation & Information :  Ext. 210\n");
    printf(" \n\t\t Email Address             :  library@ewubd.edu\n");
    printf(" \n\t\t Website                   :  http://lib.ewubd.edu/\n");
    printf(" \n\t\t ==================================================\n\n");

    printf("\n \t\t\t\t Thank You !\n");

    fflush(stdin);
    void main_menu();
}

// function that closes the library management program
void exit_program()
{
    system("cls");
    int i;
    printf("\n\n\n\t\tThank You for Visiting the Library Management .....\n\n");

    printf("\n\t\t The program is closing in 3...2...1...\n\n");

    // for loop for auto exit after running empty loop from (1 - 1000000000)
    for(i=1; i<1e9; i++)
    {

    }
    exit(0);
}
