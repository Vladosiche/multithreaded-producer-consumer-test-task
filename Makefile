CXX = g++
CXXFLAGS = -std=c++14 -g
SRCS = main.cpp producer.cpp consumer.cpp
TARGET = app

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f *.o $(TARGET)
