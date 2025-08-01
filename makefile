CXX = g++

ifeq ($(OS), Windows_NT)
	RM := del /Q
	EXEC_EXT := .exe

else
	RM := rm -f
	EXEC_EXT := 

endif


TARGET = pril-editor$(EXEC_EXT)

SRCS = App.cpp Frame.cpp 

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -std=c++17 `wx-config --cxxflags`
LDFLAGS = `wx-config --libs`

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

App.o: App.h Frame.h
Frame.o: Frame.h

clean:
	$(RM) $(OBJS)

run:
	make all && make clean && ./pril-editor

.PHONY: all clean


