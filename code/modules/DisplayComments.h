void displayCommentsByTask() {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", errors[0][2]); return;
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
				printf("Enter ID of exist project: ");
				 pId = getInt();
			}

			else { pId = user_ptr->porj_id; }
			proj *tmpP = findProjById(pId);

			// for worker only his task
			// for manager and director all tasks
			if (user_ptr->level == 3) { tId = user_ptr->task_id;  }
			else {
				printf("Enter ID of exist task: ");
				tId = getInt();
			}
			task *tmpT = findTaskById(tId);

			printf("All Comments from project %s, to task ::%s:: \n", tmpP->name, tmpT->title);
					// comments print
					t = comments_list;
					while (t) {
						// task filter
						if (t->ptr->task_id == tmpT->id) {
							printComment(t->ptr);
							tmpU = findUserById(t->ptr->user_id);
							if (tmpU)
								printf("Author ::%s::", tmpU->name);
							printf("\n\n");
						}
						t = t->next;
			}
		}
	}

	printf("To Back press [0]");
	int t = getInt();
}


void displayCommentsByUser() {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", errors[0][2]); return;
	}

	else {
		if (comments_list) {
			comment_node *t = NULL;
			task *tmpT = NULL;

			printf("Enter ID of exist project: ");
			int pId = getInt();
			proj *tmpP = findProjById(pId);

			printf("Enter ID of exist user: ");
			int uId = getInt();
			user *tmpU = findUserById(uId);

			printf("All Comments from project %s, by User ::%s:: \n", tmpP->name, tmpU->name);
			// comments print
			t = comments_list;
			while (t) {
				// user filter
				if (t->ptr->user_id == tmpU->id) {
					printComment(t->ptr);
					tmpT = findTaskById(t->ptr->task_id);
					if (tmpT)
						printf("In Task [%s]", tmpT->title);
					printf("\n\n");
				}
				t = t->next;
			}
		}
	}

	printf("To Back press [0]");
	int t = getInt();
}