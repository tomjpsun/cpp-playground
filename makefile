CXX=clang++-3.9
TARGET=test
SRCS=test.cpp demo_binder.cpp inheritance.cpp
CXXFLAGS=$(DEBUG_FLAGS) -std=c++11 -Wall -fPIC
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
DEPS=$(patsubst %.cpp,%.d,$(SRCS))
LIBS    =-lrt -lstdc++  -pthread
INCFLAGS = -I./ -I/usr/include
.PHONY:	clean $(TARGET)

# Objects generation
%.o:	%.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -MMD -c $< -o $@

%.d: 	%.cpp
	$(CXX) -M $(CXXFLAGS) $(INCFLAGS) $< > $@

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

clean:
	rm $(TARGET) *.o *.d

-include $(DEPS)
