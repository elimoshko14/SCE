typedef int bool;
#define true 1
#define false 0

// singles
struct user * user_ptr = NULL;

// lists
struct user_node * users_list = NULL;
struct proj_node * projects_list = NULL;
struct task_node * tasks_list = NULL;
struct comment_node * comments_list = NULL;
struct category_node * categories_list = NULL;

// array of errors 
char errors[6][10][100] = {
	// projects errors [0]
{ "Not found projects with this id", "Projects is allready exist", "Projects List is empty", "Project status incorrect"   },

	// category errors [1]
{  "Not found category with this id"  },

	// tasks errors [2]
{  "Not found task with this id"  },

	// comments errors [3]
{  "Not found comments with this id"  },

	// user errors [4]
{  "Not found user with this id", "Level of this user is not appropriate"  }, 

	// main errors [5]
{ "This options is disabled" }
};

//global technic functions
int isEmptyFile(FILE *file) {
	long savedOffset = ftell(file);
	fseek(file, 0, SEEK_END);

	if (ftell(file) == 0) {
		return 1;
	}

	fseek(file, savedOffset, SEEK_SET);
	return 0;
}

void clearFile(char fileName[]) {
	FILE * file;
	file = fopen(fileName, "w");
	fclose(file);
}
int checkInt(char str[]) {
	for (int j = 0; j < strlen(str); j++) {
		if (str[j] > '9' || str[j] < '0')
			return 0;
	}
	return 1;
}

int getInt() {
	char inputLine[100] = "\0";
	do { scanf("%s", inputLine); } while (!checkInt(inputLine));
	return atoi(inputLine);
}