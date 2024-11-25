.SILENT:
default:
	gcc -o jameson ./dialog_parser_windows.c

clean:
	-rm -f jameson.exe jameson