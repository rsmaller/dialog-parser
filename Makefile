.SILENT:
default:
	gcc -Wall -Wextra -Wpedantic -Werror -Wcast-qual -Wconversion -std=c11 -o jameson .\dialog_parser.c

clean:
	del jameson.exe