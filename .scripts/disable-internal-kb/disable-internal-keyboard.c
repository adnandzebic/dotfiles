#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define BUFSIZE 128

FILE *popen(const char *command, const char *mode);
int pclose(FILE *stream);

int main(int argc, char *argv[]) {
	const char keyboard[] = "AT Translated Set 2 keyboard";
	const char cmd[] = "xinput list";
	char *line = (char*)malloc(BUFSIZE);
	int status;
	FILE *fp;

	if ((fp = popen(cmd, "r")) == NULL) {
		perror("popen");
		exit(EXIT_FAILURE);
	}

	while ((fgets(line, BUFSIZE, fp)) != NULL) {
		if (strstr(line, keyboard) != NULL) {
			char disable_kb_command[16];
			char *ret;
			int id;

			ret = strstr(line, "id=");
			sscanf(ret, "id=%d", &id);
			sprintf(disable_kb_command, "xinput float %d", id);
			status = system(disable_kb_command);

			if (status == -1) {
				printf("Error while running command \"%s\"\n", disable_kb_command);
				free(line);
				exit(EXIT_FAILURE);
			} else {
				exit(EXIT_SUCCESS);
				free(line);
			}
		}
	}

	free(line);

	status = pclose(fp);
	if (status) {
		printf("Error while running command \"%s\"", cmd);
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}

