void management_category() {
	while (1) {
		int i = 0;
		printf("-----------------------------------\n\n");
		printf("[%d] Add new category:\n", ++i);
		printf("[%d] Edit category:\n", ++i);
		printf("[%d] Delete category:\n", ++i);
		printf("[%d] Back to Menu\n", ++i);
		printf("-----------------------------------\n\n");

		printf("Make your choise: ");
		int x = getInt();

		// add
		if (x == 1) {
			int id, pId, cost;
			char name[256];
			system("cls");
			printf("Enter ID of exist project: ");
			pId = getInt();

			// if project is not exist arise error
			if (findProjById(pId) == NULL)
				printf("%s\n", errors[0][0]);

			else {
				printf("Enter unique id of new category: ");
				id = getInt();
				printf("Enter name of new category: ");
					getchar();  gets(name);
					addCat(id, name, pId, "-1");				
			}
		}

		// update
		else if (x == 2) {
			// it is possible update all fields except ID
			system("cls");

			// if categories exist
			if (categories_list) {
				printf("Enter ID of exist project: ");
				int pId = getInt();
				proj *tmpP = findProjById(pId);
				
				printf("All Categories by project %s:\n", tmpP->name);
				category_node * t = categories_list;
				while (t) {
					if (t->ptr->proj_id == pId)
						printCat(t->ptr);
					t = t->next;
				}
				printf("Enter id of category which need to update\n");
				int id = getInt();
				category * tmp = findCatById(id);

				// if found category update it
				if (tmp != NULL) {
						system("cls");
							char newName[256];
							printf("Enter New name: ");
							getchar(); gets(newName);
							UpdateCat(tmp->id, newName, tmp->proj_id, tmp->comment_arr); 
				}
					
				// not found category
				else {
					printf("%s\n", errors[1][0]);
				}
			}
			// arise error
			else {
				printf("%s\n", errors[1][2]);
			}
		}

		// delete
		else if (x == 3) {
			// if category exist
			if (categories_list) {
				printf("Enter ID of exist project: ");
				int pId = getInt();
				proj *tmpP = findProjById(pId);

				printf("All Categories by project %s:\n", tmpP->name);
				category_node * t = categories_list;
				while (t) {
					if (t->ptr->proj_id == pId)
						printCat(t->ptr);
					t = t->next;
				}
				printf("Enter id of category which need to delete\n");
				int id = getInt();
				if (findCatById(id) == NULL)
					printf("%s\n", errors[1][0]);
				
				else {
					// delete current category
					unSetCat(id);
				}
			}
		}

		// back to main menu
		else if (x == 4) {
			return;
		}

		// if choise is wrong back 
		else { return;  }
	}
}