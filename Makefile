file="server"

build:
	gcc `pkg-config --cflags gtk4 libmicrohttpd` -o ${file} ${file}.c `pkg-config  --libs gtk4 libmicrohttpd`