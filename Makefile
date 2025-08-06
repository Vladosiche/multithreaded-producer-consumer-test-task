CXX = g++
CXXFLAGS = -std=c++20 -g
SRCS = main.cpp producer.cpp consumer.cpp mediator.cpp facade.cpp
TARGET = app
OBJS = $(SRCS:.cpp=.o) 

all: $(TARGET)

%.o: %.cpp
	$(CXX) -c -o $@ $< 
	
$(TARGET):
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)



clean:
	rm -f $(TARGET)
