#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_SIZE 64

int main(int argc, char *argv[]) {
	const char monitor[] = "DP-1";
	const float brightness = 0.0;	// max
	char cmd[CMD_SIZE]; 
	sprintf(cmd, "xrandr --output %s --brightness %f", monitor, brightness);
	int status;

	status = system(cmd);

	if (status == 0)
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;

}

