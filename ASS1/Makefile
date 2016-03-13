# All Targets
all: cyber

# Tool invocations
# Executable "main" depends on the files main.o and run.o.


cyber: bin/main.o bin/CyberPC.o bin/CyberWorm.o bin/CyberDNS.o bin/CyberExpert.o
	@echo 'Building target: cyber'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/cyber bin/main.o bin/CyberPC.o bin/CyberWorm.o bin/CyberDNS.o bin/CyberExpert.o 
	@echo 'Building PC'
	@echo 'Finished building target: cyber'
	@echo ' '


# Depends on the source and header files
bin/CyberPC.o: src/CyberPC.cpp include/CyberPC.h
	g++ -g -Wall -c -Linclude -o bin/CyberPC.o src/CyberPC.cpp

# Depends on the source and header files 
bin/CyberWorm.o: src/CyberWorm.cpp include/CyberWorm.h
	g++ -g -Wall -c -Linclude -o bin/CyberWorm.o src/CyberWorm.cpp

	# Depends on the source and header files 
bin/CyberDNS.o: src/CyberDNS.cpp include/CyberDNS.h
	g++ -g -Wall -c -Linclude -o bin/CyberDNS.o src/CyberDNS.cpp

	# Depends on the source and header files 
bin/CyberExpert.o: src/CyberExpert.cpp include/CyberExpert.h
	g++ -g -Wall -c -Linclude -o bin/CyberExpert.o src/CyberExpert.cpp

	# Depends on the source and header files 
bin/main.o: src/main.cpp
	g++ -g -Wall -c -Linclude -o bin/main.o src/main.cpp
	
	

#Clean the build directory
clean: 
	rm -f bin/*