all:
	mkdir -p /usr/include/ptest/
	cp *.hpp /usr/include/ptest/
	cp system /usr/include/
	g++ ptest.cpp -o /usr/bin/ptest

uninstall:
	rm -rf /usr/bin/ptest
	rm -rf /usr/include/ptest/
	rm -rf /usr/include/system
	
