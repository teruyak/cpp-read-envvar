CXX = g++
CXXFLAGS = -Wall -g

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)