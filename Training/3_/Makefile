TARGET = 3_11
SOURCES = 3_11.cpp

OBJECTS = $(SOURCES:.cpp=.o)

##################################

default : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) -c -o ${CXXFLAGS} $@ $<

clean:
	rm -rf $(OBJECTS) $(TARGET)
