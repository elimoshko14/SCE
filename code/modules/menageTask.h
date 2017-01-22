void management_tasks() {
	while (1) {
		int i = 0;
		printf("-----------------------------------\n\n");
		printf("[%d] Add new task:\n", ++i);
		printf("[%d] Edit task:\n", ++i);
		printf("[%d] Delete task:\n", ++i);
		printf("[%d] Back to Menu\n", ++i);
		printf("-----------------------------------\n\n");

		printf("Make your choise: ");
		int x = getInt();

		// add
		if (x == 1) {
			int id, pId, cId, cost;
			char title[256];
			char tags[256];
			char due[256];

			system("cls");
			if (user_ptr->level == 1) {
				printf("Enter ID of exist project: ");
				pId = getInt();
			}
			else { pId = user_ptr->porj_id; }

			// if project is not exist arise error
			if (findProjById(pId) == NULL)
				printf("%s\n", errors[0][0]);

			else {
				printf("Enter ID of exist category: ");
				cId = getInt();
				if (findCatById(cId) == NULL)
					printf("%s\n", errors[1][0]);
				else {
					id = ++unique_task_key;
					printf("Enter title of new task: ");
					getchar();  gets_s(title,256);
					printf("Enter cost of new task: ");
					cost = getInt();
					printf("Enter tags for new task: ");
					getchar();  gets_s(tags,256);
					printf("Enter due of new task in format(d/m/y): ");
					getchar();  gets_s(due,256);

					printf("Enter id of user which will do this task: ");
					int uId = getInt();
					user *tmpU;				
					tmpU = findUserById(uId);
					if ((tmpU != NULL) && (tmpU->task_id == 0) && (tmpU->level == 3)) {
						addTask(id, title, uId, cId, cost, 0, tags, due, "-1");
						updateUser(tmpU->id, tmpU->name, tmpU->lang, tmpU->password, tmpU->level, tmpU->porj_id, id, tmpU->salery, tmpU->online, tmpU->coments);
					}
					else
						addTask(id, title, 0, cId, cost, 0, tags, due, "-1");
				}
			}
		}

		// update
		else if (x == 2) {
			int pId, cId, newCost, newStatus;
			char newTitle[256];
			char newTags[256];
			char newDue[256];

			// it is possible update all fields except ID's
			system("cls");

			// if categories exist
			if (categories_list) {
				if (user_ptr->level == 1) {
					printf("Enter ID of exist project: ");
					pId = getInt();
				}
				else { pId = user_ptr->porj_id; }
				proj *tmpP = findProjById(pId);
				
				printf("Enter ID of exist category: ");
				cId = getInt();
				category *tmpC = findCatById(cId);


				printf("All Tasks by project %s in category %s:\n", tmpP->name, tmpC->name);
				task_node * t = tasks_list;
				while (t) {
					if (t->ptr->category_id == cId)
						printTask(t->ptr);
					t = t->next;
				}
				printf("Enter id of task which need to update\n");
				int id = getInt();

				task * tmp = findTaskById(id);

				// if found task update it
				if (tmp != NULL) {
					while (1) {
						system("cls");
						i = 0;
						printf("\n Update task %s\n----------------------\n", tmp->title);
						printf("[%d] Change Title:\n", ++i);
						printf("[%d] Change Cost:\n", ++i);
						printf("[%d] Change Due:\n", ++i);
						printf("[%d] Change Status\n", ++i);
						printf("[%d] Change Tags\n", ++i);
						printf("[%d] Change Task Category\n", ++i);
						printf("[%d] Change Task User\n", ++i);
						printf("[%d] Back to previous menu\n", ++i);
						int a = getInt();


						if (a == 1) {
							printf("Enter New title: ");
							getchar(); gets_s(newTitle,256);
							updateTask(tmp->id, newTitle, tmp->user_id, tmp->category_id, tmp->cost, tmp->status, tmp->tags, tmp->due, tmp->comments); 
						}

						else if (a == 2) {
							printf("Enter New cost: ");
							newCost = getInt();
							updateTask(tmp->id, tmp->title, tmp->user_id, tmp->category_id, newCost, tmp->status, tmp->tags, tmp->due, tmp->comments);
						}
						else if (a == 3) {
							printf("Enter New password: ");
							getchar(); gets_s(newDue, 256);
							updateTask(tmp->id, tmp->title, tmp->user_id, tmp->category_id, tmp->cost, tmp->status, tmp->tags, newDue, tmp->comments);
						}

						else if (a == 4) {
							printf("Enter New status (0 or 1): ");
							newStatus = getInt();
							updateTask(tmp->id, tmp->title, tmp->user_id, tmp->category_id, tmp->cost, newStatus, tmp->tags, tmp->due, tmp->comments);
						}

						else if (a == 5) {
							printf("Enter New tags: ");
							getchar(); gets_s(newTags,256);
							updateTask(tmp->id, tmp->title, tmp->user_id, tmp->category_id, tmp->cost, tmp->status, newTags, tmp->due, tmp->comments);
						}

						else if (a == 6) {  
							printf("Enter id of exist category: ");
							cId = getInt();
							tmpC = findCatById(cId);
							if (tmpC == NULL)
								printf("%s\n", errors[1][0]);
							else 
								updateTask(tmp->id, tmp->title, tmp->user_id, cId, tmp->cost, tmp->status, tmp->tags, tmp->due, tmp->comments);
						}
						else if (a == 7) {
							printf("Enter id of exist user: ");
							int uId = getInt();
							user *tmpU = findUserById(uId);
							if (tmpU == NULL)
								printf("%s\n", errors[4][0]);
							else
							{
								updateTask(tmp->id, tmp->title, uId, tmp->category_id, tmp->cost, tmp->status, tmp->tags, tmp->due, tmp->comments);
								updateUser(tmpU->id, tmpU->name, tmpU->lang, tmpU->password, tmpU->level, tmpU->porj_id,tmp->id , tmpU->salery, tmpU->online, tmpU->coments);
							}
						}
						else if (a == 8) { break; }

						else { break; }
					}
				}
					
				// not found task
				else {
					printf("%s\n", errors[2][0]);
				}
			}
			// no categoryies no tasks
			else {
				printf("%s\n", errors[1][2]);
			}
		}

		// delete
		else if (x == 3) {
			int pId;
			// if task exist
			if (tasks_list) {
				if (user_ptr->level == 1) {
					printf("Enter ID of exist project: ");
					pId = getInt();
				}
				else { pId = user_ptr->porj_id; }
				proj *tmpP = findProjById(pId);

				printf("Enter ID of exist category: ");
				int cId = getInt();
				category *tmpC = findCatById(cId);


				printf("All Tasks by project %s in category %s:\n", tmpP->name, tmpC->name);
				task_node * t = tasks_list;
				while (t) {
					if (t->ptr->category_id == cId)
						printTask(t->ptr);
					t = t->next;
				}
				
				printf("Enter id of task which need to delete\n");
				int id = getInt();
				if (findTaskById(id) == NULL)
					printf("%s\n", errors[2][0]);
				else {
					// delete current task
					unSetTask(id);
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