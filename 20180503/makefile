target : test.c ./output/mecLink.o
	gcc test.c ./output/mecLink.o -o test
./output/mecLink.o : ./include/mecLink.h ./resource/mecLink.c
	gcc ./resource/mecLink.c -c -o ./output/mecLink.o
	
