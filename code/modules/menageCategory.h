void management_category() {
	while (1) {
		int i = 0;
		printf("-----------------------------------\n\n");
		printf("[%d] %s\n", ++i,i18("Add new category:"));
		printf("[%d] %s\n", ++i,i18("Edit category:"));
		printf("[%d] %s\n", ++i,i18("Delete category:"));
		printf("[%d] %s\n", ++i,i18("Back to Menu"));
		printf("-----------------------------------\n\n");

		printf("%s ",i18("Make your choise:"));
		int x = getInt();

		// add
		if (x == 1) {
			int id, pId;
			char name[256];
			
			if (user_ptr->level == 1) {
				printf("%s ",i18("Enter ID of exist project:"));
				pId = getInt();
			}
			else {
				pId = user_ptr->porj_id;
			}
			// if project is not exist arise error
			if (findProjById(pId) == NULL)
				printf("%s\n", i18("Not found projects with this id"));

			else {
				id = ++unique_category_key;
				if (findCatById(id) != NULL)
					printf("%s\n", i18("Category is allready exist"));
				else {
					printf("%s ",i18("Enter name of new category:"));

 					getchar();  gets_s(name,256);
					addCat(id, name, pId, "-1");
				}
			}
		}

		// update
		else if (x == 2) {
			int pId;
			// it is possible update all fields except ID
			

			// if categories exist
			if (categories_list) {
				if (user_ptr->level == 1) {
					printf("%s",i18("Enter ID of exist project: "));
					pId = getInt();
				}
				else {
					pId = user_ptr->porj_id;
				}
				proj *tmpP = findProjById(pId);
				if (!tmpP)break;
				printf("%s %s:\n",i18("All Categories by project"), tmpP->name);
				category_node * t = categories_list;
				while (t) {
					if (t->ptr->proj_id == pId)
						printCat(t->ptr);
					t = t->next;
				}
				printf("%s\n",i18("Enter id of category which need to update"));
				int id = getInt();
				category * tmp = findCatById(id);
				// if found category update it
				if (tmp != NULL) {
						
							char newName[256];
							printf("%s ",i18("Enter New name:"));
							getchar(); gets_s(newName,256);
							UpdateCat(tmp->id, newName, tmp->proj_id, tmp->comment_arr); 
				}
					
				// not found category
				else {
					printf("%s\n", i18("Not found category with this id"));
				}
			}
			// arise error
			else {
				printf("%s\n", i18("Categories List is empty"));
			}
		}

		// delete
		else if (x == 3) {
			int pId;
			// if category exist
			if (categories_list) {
				if (user_ptr->level == 1) {
					printf("%s ",i18("Enter ID of exist project:"));
					pId = getInt();
				}
				else {
					pId = user_ptr->porj_id;
				}
				proj *tmpP = findProjById(pId);
				if (!tmpP)break;
				printf("%s %s:\n",i18("All Categories by project"), tmpP->name);
				category_node * t = categories_list;
				while (t) {
					if (t->ptr->proj_id == pId)
						printCat(t->ptr);
					t = t->next;
				}
				printf("%s\n",i18("Enter id of category which need to delete"));
				int id = getInt();
				if (findCatById(id) == NULL)
					printf("%s\n", i18("Not found category with this id"));
				
				else {
					printf("%s\n",i18("Warning! Deleting a Category will delete all it's tasks"));
					printf("%s\n",i18("Are you sure? [1 / 0]"));
					int checker = getInt();
					if (checker == 1)
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