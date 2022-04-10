OBJ=src/main.o
TEST_OBJ=tests/main.o

CC:=i686-w64-mingw32-gcc
CFLAGS=-I ./include

msvbvm60.dll: ${OBJ}
	${CC} -shared -o msvbvm60.dll ${LDFLAGS} ${OBJ} src/msvbvm60.def

tests.exe: msvbvm60.dll ${TEST_OBJ}
	${CC} -o tests.exe ${LDFLAGS} ${TEST_OBJ}

.PHONY: clean
clean:
	rm -f ${OBJ} ${TEST_OBJ} tests.exe msvbvm60.dll
