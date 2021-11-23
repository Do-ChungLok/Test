

source_files = $(wildcard *.cpp)


all: $(source_files:.cpp=)


$(source_files:.cpp=) : % : %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $^

clean:
	@echo "  REMOVE all object files"; rm -f $(source_files:.cpp=.o) $(source_files:.cpp=)
