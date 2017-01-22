void displayTask(int status) {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", errors[0][2]); return;
	}

	else {
		int pId;
		if (tasks_list) {
			task_node *t = NULL;

			if (user_ptr->level == 1) {
				printf("Enter ID of exist project: ");
				 pId = getInt();
			}
			else { pId = user_ptr->porj_id; }
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

	printf("To Back press [0]");
	int t = getInt();
}