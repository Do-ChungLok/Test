TARGET = monitor
SOURCES = monitor.cpp

OBJECTS = $(SOURCES:.cpp=.o)

##################################

default : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) -c -o ${CXXFLAGS} $@ $<

clean:
	rm -rf $(OBJECTS) $(TARGET)
