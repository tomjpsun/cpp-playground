CXX=clang++
TARGET=test
SRCS=test.cpp demo_binder.cpp inheritance.cpp algo.cpp execution_path_comparison.cpp example_json.cpp touple.cpp timeout_test.cpp vec_insert.cpp pass_smartptr.cpp endian.cpp regex_test.cpp json_test.cpp curl_example.cpp
CXXFLAGS=$(DEBUG_FLAGS) -std=c++14 -Wall -fPIC
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
DEPS=$(patsubst %.cpp,%.d,$(SRCS))
lrt:=$(shell echo "int main() {}"|clang -x c - -lrt 2>&1)
ifeq ($(lrt),)
  lrtlibs:=-lrt
else
  lrtlibs:=
endif

LIBS    = -lstdc++  -pthread -ljson-c -lcurl $(lrtlibs)
INCFLAGS = -I. -I/usr/include
.PHONY:	clean $(TARGET)

# Objects generation
%.o:	%.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -MMD -c $< -o $@

%.d: 	%.cpp
	$(CXX) -M $(CXXFLAGS) $(INCFLAGS) $< > $@

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

clean:
	rm $(TARGET) *.o *.d *~

-include $(DEPS)
