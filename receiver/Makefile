BUILD_DIR = build
CFLAGS = g++ -std=c++11 -pthread
SOCKET_DIR = ../socket
LOGGER_DIR = ../network

OBJECTS = \
	$(BUILD_DIR)/Receiver.o	\
	$(BUILD_DIR)/Main.o		\
	$(BUILD_DIR)/Socket.o	\
	$(BUILD_DIR)/Logger.o

all: $(BUILD_DIR) receiver.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/Logger.o: $(LOGGER_DIR)/logger.cpp $(LOGGER_DIR)/logger.hpp
	$(CFLAGS) -c $(LOGGER_DIR)/logger.cpp -o $(BUILD_DIR)/Logger.o

$(BUILD_DIR)/Socket.o: $(SOCKET_DIR)/socket.cpp $(SOCKET_DIR)/socket.hpp $(LOGGER_DIR)/logger.hpp
	$(CFLAGS) -c $(SOCKET_DIR)/socket.cpp -o $(BUILD_DIR)/Socket.o

$(BUILD_DIR)/Main.o: main.cpp receiver.hpp $(SOCKET_DIR)/socket.hpp $(LOGGER_DIR)/logger.hpp
	$(CFLAGS) -c main.cpp -o $(BUILD_DIR)/Main.o

$(BUILD_DIR)/Receiver.o: receiver.cpp receiver.hpp $(SOCKET_DIR)/socket.hpp
	$(CFLAGS) -c receiver.cpp -o $(BUILD_DIR)/Receiver.o

receiver.out: $(OBJECTS)
	$(CFLAGS) $(OBJECTS) -o receiver.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o
	rm -rf $(BUILD_DIR) *.out