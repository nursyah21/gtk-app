build:
	gcc `pkg-config --cflags gtk4` -o hello-world hello-world.c `pkg-config  --libs gtk4`