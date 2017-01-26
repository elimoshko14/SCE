void displayCommentsByTask() {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", i18("Projects List is empty"));
	}

	else {
		if (comments_list) {
			comment_node *t = NULL;
			user *tmpU = NULL;
			int pId, tId;

			// by user level
			// director all project
			// manager and worker only current project
			if (user_ptr->level == 1) {
				printf("%s: ",i18("Enter ID of exist project"));
				 pId = getInt();
			}

			else { pId = user_ptr->porj_id; }
			proj *tmpP = findProjById(pId);

			// for worker only his task
			// for manager and director all tasks
			if (user_ptr->level == 3) { tId = user_ptr->task_id;  
			}
			else {
				printf("%s: ",i18("Enter ID of exist task"));
				tId = getInt();
			}
			task *tmpT = findTaskById(tId);

			printf("%s %s, %s ::%s:: \n",i18("All Comments from project"), tmpP->name, i18("to task"), tmpT->title);
					// comments print
					t = comments_list;
					while (t) {
						// task filter
						if (t->ptr->task_id == tmpT->id) {
							printComment(t->ptr);
							tmpU = findUserById(t->ptr->user_id);
							if (tmpU)
								printf("%s ::%s::",i18("Author"), tmpU->name);
							printf("\n\n");
						}
						t = t->next;
			}
		}
	}

	printf("%s [0]", i18("To Back press"));
	int t = getInt();
}


void displayCommentsByUser() {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", i18("Projects List is empty"));
	}

	else {
		int pId;
		if (comments_list) {
			
			comment_node *t = NULL;
			task *tmpT = NULL;

			if (user_ptr->level == 1) {
				printf("%s: ", i18("Enter ID of exist project"));
				pId = getInt();
			}
			else { pId = user_ptr->porj_id; }
			proj *tmpP = findProjById(pId);

			printf("%s: ",i18("Enter ID of exist user"));
			int uId = getInt();
			user *tmpU = findUserById(uId);

			printf("%s %s, %s, ::%s:: \n",i18("All Comments from project"), tmpP->name,
				i18("by User"), tmpU->name);
			// comments print
			t = comments_list;
			while (t) {
				// user filter
				if (t->ptr->user_id == tmpU->id) {
					printComment(t->ptr);
					tmpT = findTaskById(t->ptr->task_id);
					if (tmpT)
						printf("%s [%s]", i18("In Task"), tmpT->title);
					printf("\n\n");
				}
				t = t->next;
			}
		}
	}

	printf("%s [0]", i18("To Back press"));
	int t = getInt();
}