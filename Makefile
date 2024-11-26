.SILENT:
default:
	gcc -o jameson ./dialog_parser_windows.c

clean:
	del jameson.exe