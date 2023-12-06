.PHONY := clean all

all:
	@g++ -o hello main.cpp
	@./hello.exe

# timeout /t 3 > nul
clean:
	del *.exe

 