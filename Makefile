default: TinySTL_Test.exe
	cmd.exe /C TinySTL_Test.exe
TinySTL_Test.exe: main.c TinySTL.c TinySTL.h
	gcc -o $@ $^ -w
clean: 
	cmd.exe /C del *.o
	cmd.exe /C del *.exe
