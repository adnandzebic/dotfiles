#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 128

int cycleNodes(void);
int getCurNode(char* node);
FILE *popen(const char *command, const char *mode);
int pclose(FILE *stream);

int main(int argc, char *argv[]) {
	for (;;) {
		int status = 0;
		char goBackToOriginalNode[32];
		char *curNode = (char*)malloc(BUFSIZE);
		status = getCurNode(curNode);

		if (status) {
			printf("Error while running command 'bspc query -N -n .focused");
			exit(EXIT_FAILURE);
		}

		sprintf(goBackToOriginalNode, "bspc node %s -f", curNode);
		free(curNode);

		status = cycleNodes();

		if (status) {
			printf("Error while running command 'bspc query -N");
			exit(EXIT_FAILURE);
		}

		status = system(goBackToOriginalNode);

		if (status) {
			printf("Error while running command %s\n", goBackToOriginalNode);
			exit(EXIT_FAILURE);
		}
		sleep(60);
	}

	return EXIT_SUCCESS;
}

int cycleNodes (void) {
	const char cmd[] = "bspc query -N";
	char *line = (char*)malloc(BUFSIZE);
	int status;
	FILE *fp;

	if ((fp = popen(cmd, "r")) == NULL) {
		perror("popen");
		return -1;
	}

	while ((fgets(line, BUFSIZE, fp)) != NULL) {
		char select_node_command[32];
		line[strcspn(line, "\n")] = 0;		// remove trailing new line
		sprintf(select_node_command, "bspc node %s -f", line);
		status = system(select_node_command);
	}

	free(line);

	status = pclose(fp);
	if (status) {
		printf("Error while running command \"%s\"", cmd);
		return -1;
	}

	return 0;
}

int getCurNode (char* node) {
	const char cmd[] = "bspc query -N -n .focused";
	char *line = (char*)malloc(BUFSIZE);
	int status;
	FILE *fp;

	if ((fp = popen(cmd, "r")) == NULL) {
		perror("popen");
		return -1;
	}

	while ((fgets(line, BUFSIZE, fp)) != NULL) {
		line[strcspn(line, "\n")] = 0;		// remove trailing new line
		strcpy(node, line);
	}

	free(line);

	status = pclose(fp);
	if (status) {
		printf("Error while running command \"%s\"", cmd);
		return -1;
	}

	return 0;
}

