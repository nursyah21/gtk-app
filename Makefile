file="gui2"

run: build
	./app

build:
	gcc `pkg-config --cflags gtk4 libmicrohttpd` -o app ${file}.c `pkg-config  --libs gtk4 libmicrohttpd`

clean:
	rm ./app