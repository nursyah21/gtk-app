file=sfml_2.cpp

run: builds
	./app

builds:
	g++-11 ${file} -o app `pkg-config --static --libs sfml-all gl`


# gflw and glad
# gcc ${file}.c `pkg-config --cflags glfw3 gl` `pkg-config  --static --libs glfw3 gl` -o app
# gcc `pkg-config --cflags glfw3 gl` -o app ${file}.c `pkg-config  --static --libs glfw3 gl`
#gcc `pkg-config --cflags gtk4 libmicrohttpd` -o app ${file}.c `pkg-config  --libs gtk4 libmicrohttpd`

clean:
	rm ./app