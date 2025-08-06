CXX = g++
CXXFLAGS = -std=c++20 -g
SRCS = main.cpp producer.cpp consumer.cpp mediator.cpp facade.cpp
TARGET = app
OBJS = $(SRCS:.cpp=.o) 

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

clean:
	rm -f $(TARGET) $(OBJS)
