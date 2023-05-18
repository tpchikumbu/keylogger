linux_logger: linux_logger.cpp
	g++ linux_logger.cpp -o linux

windows_logger: windows_logger.cpp
	g++ windows_logger.cpp -o windows

windows: windows_logger
	./windows

linux: linux_logger
	./linux
