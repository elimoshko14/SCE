void displayTask(int status) {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", errors[0][2]); return;
	}

	else {
		if (tasks_list) {
			task_node *t = NULL;

			printf("Enter ID of exist project: ");
			int pId = getInt();
			proj *tmpP = findProjById(pId);

			printf("All Tasks by project %s:\n", tmpP->name);
			category_node * tmpC = categories_list;
			while (tmpC) {
				if (tmpC->ptr->proj_id == pId) {
					printf("Category : %s\n", tmpC->ptr->name);
					printf("TASKS\n\n");
					// tasks print
					t = tasks_list;
					while (t) {
						
						// category filter
						if (t->ptr->category_id == tmpC->ptr->id) {
							// status filter
							if (t->ptr->status == status) {
								printTask(t->ptr);
							}
						}
						t = t->next;
					}
				}
				tmpC = tmpC->next;
			}
		}
	}

	printf("To Back press [0]");
	int t = getInt();
}