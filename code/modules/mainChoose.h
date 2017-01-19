void mainChoose(int ch) {

	switch (ch) {
	case 1: { management_projets();  break; }
	case 2: { displayProjects();  break; }
	case 3: {  management_category();  break; }
	case 4: {  displayCategories();  break; }
	case 5: {  management_tasks(); break; }
	case 6: {  displayTask(1);  break; }
	case 7: {  displayTask(0); break; }
	case 8: {  break; }
	case 9: {  break; }
	case 10: {  break; }
	case 11: {  break; }
	case 12: {  break; }
	case 13: {  break; }
	case 14: {  break; }
	case 15: {  break; }
	case 16: {  break; }
	case 17: {  printf("\n\n Bye Bye \n\n"); exit(0); break; }


	default: break;
	}
}