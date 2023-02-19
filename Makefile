file="server"

build:
	gcc `pkg-config --cflags gtk4 libmicrohttpd` -o app ${file}.c `pkg-config  --libs gtk4 libmicrohttpd`