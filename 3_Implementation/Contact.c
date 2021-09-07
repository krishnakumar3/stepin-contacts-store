
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
#include <direct.h>
struct contact

{

    long int phone;

    char name[30], add[30], email[25];

} list;

char query[30], name[30];

FILE *fp, *ft;

int i, n, case_n, l, found;
//Functions
void Add_Contact()
{
    system("cls");

    fp = fopen("contact.dll", "a");

    for (;;)

    {
        fflush(stdin);

        printf("To exit enter blank space in the name input\nName (Use identical):");

        scanf("%[^\n]", &list.name);

        if (stricmp(list.name, "") == 0 || stricmp(list.name, " ") == 0)

            break;

        fflush(stdin);

        printf("Phone:");

        scanf("%ld", &list.phone);

        fflush(stdin);

        printf("address:");

        scanf("%[^\n]", &list.add);

        fflush(stdin);

        printf("email address:");

        gets(list.email);

        printf("\n");

        fwrite(&list, sizeof(list), 1, fp);
    }

    fclose(fp);

    /* *********************list of contacts*************************  */
}
void function2()
{
    system("cls");

    printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");

    for (i = 97; i <= 122; i = i + 1)

    {

        fp = fopen("contact.dll", "r");

        fflush(stdin);

        found = 0;

        while (fread(&list, sizeof(list), 1, fp) == 1)

        {

            if (list.name[0] == i || list.name[0] == i - 32)

            {

                printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n", list.name,

                       list.phone, list.add, list.email);

                found++;
            }
        }

        if (found != 0)

        {
            printf("=========================================================== [%c]-(%d)\n\n", i - 32, found);

            getch();
        }

        fclose(fp);
    }

    /* *******************search contacts**********************  */
}
void function3()
{
    system("cls");

    do

    {

        found = 0;

        printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");

        fflush(stdin);

        scanf("%[^\n]", &query);

        l = strlen(query);

        fp = fopen("contact.dll", "r");

        system("cls");

        printf("\n\n..::Search result for '%s' \n===================================================\n", query);

        while (fread(&list, sizeof(list), 1, fp) == 1)

        {

            for (i = 0; i <= l; i++)

                name[i] = list.name[i];

            name[l] = '\0';

            if (stricmp(name, query) == 0)

            {

                printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n", list.name, list.phone, list.add, list.email);

                found++;

                if (found % 4 == 0)

                {

                    printf("..::Press any key to continue...");

                    getch();
                }
            }
        }

        if (found == 0)

            printf("\n..::No match found!");

        else

            printf("\n..::%d match(s) found!", found);

        fclose(fp);

        printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

        scanf("%d", &case_n);

    } while (case_n == 1);

    /* *********************edit contacts************************/
}
void function4()
{
    system("cls");

    fp = fopen("contact.dll", "r");

    ft = fopen("temp.dat", "w");

    fflush(stdin);

    printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");

    scanf("%[^\n]", name);

    while (fread(&list, sizeof(list), 1, fp) == 1)

    {

        if (stricmp(name, list.name) != 0)

            fwrite(&list, sizeof(list), 1, ft);
    }

    fflush(stdin);

    printf("\n\n..::Editing '%s'\n\n", name);

    printf("..::Name(Use identical):");

    scanf("%[^\n]", &list.name);

    fflush(stdin);

    printf("..::Phone:");

    scanf("%ld", &list.phone);

    fflush(stdin);

    printf("..::address:");

    scanf("%[^\n]", &list.add);

    fflush(stdin);

    printf("..::email address:");

    gets(list.email);

    printf("\n");

    fwrite(&list, sizeof(list), 1, ft);

    fclose(fp);

    fclose(ft);

    remove("contact.dll");

    rename("temp.dat", "contact.dll");

    /* ********************delete contacts**********************/
}
void function5()
{
    system("cls");

    fflush(stdin);

    printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

    scanf("%[^\n]", &name);

    fp = fopen("contact.dll", "r");

    ft = fopen("temp.dat", "w");

    while (fread(&list, sizeof(list), 1, fp) != 0)

        if (stricmp(name, list.name) != 0)

            fwrite(&list, sizeof(list), 1, ft);

    fclose(fp);

    fclose(ft);

    remove("contact.dll");

    rename("temp.dat", "contact.dll");
}

int main()

{

a:

    system("cls"); /* ************Main menu ***********************  */

    printf("\n\t *** Contact Management System ***");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add Contact\n\t\t[2] List of Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d", &case_n);

    switch (case_n)

    {

    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

    case 1:

        Add_Contact();
        break;

    case 2:
        function2();
        break;

    case 3:
        function3();
        break;

    case 4:
        function4();
        break;

    case 5:

        function5();
        break;

    default:

        printf("Invalid choice");

        break;
    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d", &case_n);

    switch (case_n)

    {

    case 1:

        goto a;

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;
    }

    return 0;
}