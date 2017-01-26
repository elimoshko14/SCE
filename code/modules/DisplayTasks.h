void displayTask(int status) {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", i18("Projects List is empty")); 
	}

	else {
		int pId;
		if (tasks_list) {
			task_node *t = NULL;

			if (user_ptr->level == 1) {
				printf("%s\n", i18("Enter ID of exist project:"));
				 pId = getInt();
			}
			else { pId = user_ptr->porj_id; }
			proj *tmpP = findProjById(pId);
			printf("%s\n", i18("All Tasks by project"));
			printf("%s:\n", tmpP->name);
			category_node * tmpC = categories_list;
			while (tmpC) {
				if (tmpC->ptr->proj_id == pId) {
					printf("%s\n", i18("Category :"));
					printf("%s\n", tmpC->ptr->name);
					printf("%s\n", i18("TASKS\n"));
					// tasks print
					t = tasks_list;
					while (t) {
						
						// category filter
						if (t->ptr->category_id == tmpC->ptr->id) {
							// status filter
							if (t->ptr->status == status || t->ptr->status == 1) {
								printTask(t->ptr);
							}
							if (status == -2)
								printTask(t->ptr);
						}
						t = t->next;
					}
				}
				tmpC = tmpC->next;
			}
		}
	}
	printf("%s\n", i18("To Back press [0]"));
	int t = getInt();
}