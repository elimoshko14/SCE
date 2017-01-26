void displayCategories() {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", i18("Projects List is empty")); 
	}

	else {
		int pId;
		if (categories_list) {
			if (user_ptr->level == 1) {
				printf("%s", i18("Enter ID of exist project:"));
				pId = getInt();
			}
			else { pId = user_ptr->porj_id; }
			proj *tmpP = findProjById(pId);

			printf("%s %s:\n", i18("All Categories by project"), tmpP->name);
			category_node * t = categories_list;
			while (t) {
				if (t->ptr->proj_id == pId)
					printCat(t->ptr);
				t = t->next;
			}
		}
	}

	printf("%s [0]",i18("To Back press"));
	int t = getInt();
}