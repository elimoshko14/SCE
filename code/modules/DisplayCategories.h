void displayCategories() {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", errors[0][2]); return;
	}

	else {
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
		}
	}

	printf("To Back press [0]");
	int t = getInt();
}