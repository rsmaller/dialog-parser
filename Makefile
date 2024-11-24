.SILENT:
default:
	echo Please specify "windows" or "unix" make option.

windows:
	gcc -o jameson ./dialog_parser_windows.c

unix:
	gcc -o jameson ./dialog_parser_unix.c

clean:
	-rm -f jameson.exe jameson