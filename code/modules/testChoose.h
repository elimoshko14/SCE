void testChoose(int ch) {

	int i = 1;
	
	if (i == ch){ unitTestLogin();   }i++;
	if (i == ch) { unitTestGetDbs(); }i++;
	if (i == ch){  management_category();   }i++;
	if (i == ch){  management_tasks();  }i++;
	if (i == ch){  menageComments();  }i++;

	if (i == ch){  displayProjects();   }i++;
	if (i == ch){  displayWorkers();  }i++;
	if (i == ch){  displayManagers();   }i++;
	
	if (i == ch){  displayCategories();   }i++;
	
	if (i == ch){  displayTask(-2);   }i++;
	if (i == ch){  displayTask(-1);   }i++;
	if (i == ch){  displayTask(0);  }i++;
	
	if (i == ch){  displayCommentsByTask();  }i++;
	if (i == ch){ displayCommentsByUser();  }i++;
	
	if (i == ch){  displayUsersbyProject();   }i++;
	
	if (i == ch){ copyTask();   }i++;
	if (i == ch) { CopyProj(); }i++;
	if (i == ch) { dinamicLangSwitch(); }i++;
	if (i == ch){  printf("\n\n Bye Bye \n\n"); exit(0);  }
}