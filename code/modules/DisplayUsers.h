void displayUsersbyProject() {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", i18("Projects List is empty")); return;
	}

	else {
		int pId;
		if (users_list) {
			if (user_ptr->level == 1) {
				printf("%s",i18("Enter ID of exist project: "));
				 pId = getInt();
			}
			else { pId = user_ptr->porj_id; }
			proj *tmpP = findProjById(pId);

			printf("%s %s:\n",i18("All Users in project"), tmpP->name);
			user_node * t = users_list;
			while (t) {
				if (t->ptr->porj_id == pId)
					printUser(t->ptr);
				t = t->next;
			}
		}
	}

	printf("%s",i18("To Back press [0]"));
	int t = getInt();
}

void displayWorkers() {
	int pId;
		system("cls");
		if (projects_list == NULL) {
			printf("%s\n", i18("Projects List is empty")); return;
		}

		else {
			if (users_list) {
				if (user_ptr->level == 1) {
					user_node * tmp = users_list;
					while (tmp != NULL) {
						if (tmp->ptr->level == 3)
							printUser(tmp->ptr);
						tmp = tmp->next;
					}
				}
				else {
					pId = user_ptr->porj_id;
					proj *tmpP = findProjById(pId);

					printf("%s %s:\n",i18("All Workers in project"), tmpP->name);
					user_node * t = users_list;
					while (t) {
						if (t->ptr->porj_id == pId)
							if (t->ptr->level == 3)
								printUser(t->ptr);
						t = t->next;
					}
				}
			}
		}

		printf("%s",i18("To Back press [0]"));
		int t = getInt();
}

void displayManagers() {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", i18("Projects List is empty")); return;
	}

	else {
		if (users_list) {
			user_node * tmp = users_list;
			while (tmp != NULL) {
				if (tmp->ptr->level == 2)
					printUser(tmp->ptr);
				tmp = tmp->next;
			}
			
		}
	}

	printf("%s", i18("To Back press [0]"));
	int t = getInt();
}