OBJ=src/main.o

CC:=i686-w64-mingw32-gcc

msvbvm60.dll: ${OBJ}
	${CC} -shared -o msvbvm60.dll ${LDFLAGS} ${OBJ} src/msvbvm60.def

.PHONY: clean
clean:
	rm -f ${OBJ} msvbvm60.dll
