linux_logger: linux_logger.cpp
	g++ -o linux linux_logger.cpp -lncurses 

windows_logger: windows_logger.cpp
	g++ windows_logger.cpp -o windows

windows: windows_logger
	./windows

linux: linux_logger
	./linux
