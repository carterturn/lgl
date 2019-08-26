CC = gcc
CPP = g++
TEST_SRC_1 = test1.cpp
TEST_SRC_2 = test2.cpp

#The core includes used by almost all files
CORE_INC = lgl_object.h
CORE_SRC = lgl_object.cpp

#Everything else
INC = 
SRC = 

EXE_1 = test_1
EXE_2 = test_2
CFLAGS = -I/usr/include/freetype2/ -lGL -lglfw -lftgl -lGLU

build: $(SRC) $(BUTTON_SRC) $(CORE_SRC) $(INC) $(CORE_INC) $(BUTTON_INC)
	$(CPP) -c -fPIC $(CORE_SRC) $(CFLAGS)
	$(CPP) -c -fPIC $(BUTTON_SRC) $(CFLAGS)
	$(CPP) -c -fPIC $(SRC) $(CFLAGS)
	$(CPP) -shared -Wl,-soname,liblgl.so -o liblgl.so *.o
test: $(SRC) $(BUTTON_SRC) $(TEST_SRC_1) $(TEST_SRC_2) $(CORE_SRC) $(INC) $(CORE_INC) $(BUTTON_INC)
	$(CPP) -o $(EXE_1) $(TEST_SRC_1) $(BUTTON_SRC) $(SRC) $(CORE_SRC) $(CFLAGS) -I.
	$(CPP) -o $(EXE_2) $(TEST_SRC_2) $(BUTTON_SRC) $(SRC) $(CORE_SRC) $(CFLAGS) -I.
install:
	[ -d /usr/include/lgl ] || mkdir /usr/include/lgl
	cp -f *.h /usr/include/lgl/
	cp -f liblgl.so /usr/lib/
	chmod a+r -R /usr/include/lgl
	chmod a+r /usr/lib/liblgl.so
uninstall:
	[ -d /usr/include/lgl ] && rm -f /usr/include/lgl/*.h
	[ -d /usr/include/lgl/* ] && rmdir /usr/include/lgl
	rm -f /usr/lib/liblgl.so
clean:
	for file in $$(ls *.o); do rm $$file; done
	for file in $$(ls *.so); do rm $$file; done
	for file in $$(ls *.gch); do rm $$file; done
	if [ -e $(EXE_1) ]; then rm $(EXE_1); fi
	if [ -e $(EXE_2) ]; then rm $(EXE_2); fi
rebuild: clean build
