.SILENT:
default:
	gcc -o jameson ./dialog_parser.c

clean:
	del jameson.exe