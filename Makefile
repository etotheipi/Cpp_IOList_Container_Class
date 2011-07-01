COMPILER = g++ 
COMPILER_OPTS = -c -g -Wall
#COMPILER_OPTS = -c -march=k8 -O2 -pipe -fomit-frame-pointer


LINKER = g++ 

#INCLUDE_OPTS += -I/usr/include/poker-eval/ -I/usr/include/
#LIBRARY_OPTS += -L/usr/local/lib/ -L/usr/lib/ -lpoker-eval -lsqlite3 
#SOCKET_EXTRA = -I/usr/local/include/Sockets/ -lSockets -lpthread -lssl -lcrypto -MD `Sockets-config`


testIO.out : IOList.o testIO.o
	$(LINKER) IOList.o testIO.o -o testIO.out $(INCLUDE_OPTS) $(LIBRARY_OPTS) 


#**************************************************************************
# Rules for performing the compilation of each individual object file.

IOList.o: IOList.h IOList.cpp
	$(COMPILER) $(COMPILER_OPTS) $(INCLUDE_OPTS) IOList.cpp

testIO.o: testIO.cpp
	$(COMPILER) $(COMPILER_OPTS) $(INCLUDE_OPTS) testIO.cpp


##########################################################################
# And now we have created all the individual object files specified with 
# the macro "OBJS". 
#************************************************************************


clean:
	-rm *.o *.out 


