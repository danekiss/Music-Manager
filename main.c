/*******************************************************************************************
* Programmer: Dan Ekiss                                                                    *
* Class: Cpt S 122, Spring 2015, Section 9                                                 *
* PA #2                                                                                    *
* Date: February 9, 2015                                                                   *
* Description: Digital Music Manager					                                   *
*******************************************************************************************/

#include "header.h"

int main()
{
	char menu = '1';
	Node* list = NULL;
	Node* result;


	int sort_option = 1;  

	do
	{
		
		system("cls"); // Print menu
		printf("Digital Music Manager\n\n");
		printf("1. Load\n");
		printf("2. Store\n");
		printf("3. Display\n");
		printf("4. Insert\n");
		printf("5. Delete\n");
		printf("6. Edit\n");
		printf("7. Sort\n");
		printf("8. Rate\n");
		printf("9. Exit\n\n");

		printf("Enter your choice: ");
		scanf("%c", &menu);

		fflush(stdin);
		system("cls");

		if (menu == '1')
		{
			delete_list(list);
			list = load();
			if (list != NULL)
				printf("Loaded successfully.\n");
		}
		else if (menu == '2')
		{
			store(list);
			printf("Saved successfully\n");
		}
		else if (menu == '3')
		{
			show_records(list);
		}
		else if (menu == '4')
		{
			result = read();
			sorted(&list, result, sort_option);
			printf("A new record was added.\n");
		}
		else if (menu == '5')
		{
			remove_record(&list);
		}
		else if (menu == '6')
		{
			result = scan_field(list);
			if (result == NULL) // If NULL, record obviously wasn't found.
				printf("The record you want wasn't found!\n");
			else
				edit(result -> record);
		}
		else if (menu == '7')
		{
			printf("Enter sort option( (1)Artist, (2)Genre, (3)Rating):");
			scanf("%d", &sort_option);
			sort_records(&list, sort_option);

			printf("The list was sorted\n\n");
		}
		else if (menu == '8')
		{
			result = scan_field(list);
			if (result == NULL) // If NULL, record obviously wasn't found.
				printf("The record you chose wasn't found.\n");
			else
				rate(result -> record);
		}
		else if (menu != '9')
		{
			printf("Invalid!\n"); // If not possible menu selection, print invalid
		}


		if (menu != '9')
			system("PAUSE");

	} while (menu != '9');

	store(list);
	delete_list(list);

	return 0;

}
