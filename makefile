CXX=clang++
TARGET=test
<<<<<<< HEAD
SDIR=src
ODIR=obj

SRCS=test.cpp demo_binder.cpp inheritance.cpp algo.cpp execution_path_comparison.cpp example_json.cpp touple.cpp timeout_test.cpp vec_insert.cpp pass_smartptr.cpp endian.cpp regex_test.cpp json_test.cpp curl_example.cpp llvm-jit.cpp task_q.cpp sign_convert.cpp linear_regression.cpp

CXXFLAGS = -std=c++14 -Wall -fPIC

OBJS=$(patsubst %.cpp, $(ODIR)/%.o, $(SRCS))
DEPS=$(patsubst %.cpp, $(ODIR)/%.d, $(SRCS))

=======
SRCS=test.cpp demo_binder.cpp inheritance.cpp algo.cpp execution_path_comparison.cpp example_json.cpp touple.cpp timeout_test.cpp vec_insert.cpp pass_smartptr.cpp endian.cpp regex_test.cpp json_test.cpp curl_example.cpp armadillo_test.cpp

CXXFLAGS=$(DEBUG_FLAGS) -std=c++14 -Wall -fPIC
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
DEPS=$(patsubst %.cpp,%.d,$(SRCS))
>>>>>>> master
lrt:=$(shell echo "int main() {}"|clang -x c - -lrt 2>&1)
ifeq ($(lrt),)
  lrtlibs:=-lrt
else
  lrtlibs:=
endif

<<<<<<< HEAD
LIBS= -lstdc++  -pthread -lcurl $(lrtlibs)
LIBS+= $(shell pkg-config --libs json-c)
LIBS+= -lLLVM -L/usr/local/opt/llvm/lib
INCFLAGS= -I. -Iinc -I/usr/include
INCFLAGS += $(shell pkg-config --cflags json-c)
INCFLAGS +=  -I/usr/local/opt/llvm/include
=======
LIBS    = -lstdc++  -pthread -ljson-c -lcurl $(lrtlibs) -larmadillo
INCFLAGS = -I./json/include -I/usr/include
.PHONY:	clean $(TARGET)
>>>>>>> master

.PHONY:	clean $(TARGET)
# Objects generation
$(ODIR)/%.o:    $(SDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c -MMD $< -o $@

# Generating dependencies
$(ODIR)/%.d:    $(SDIR)/%.cpp
	$(CXX) -M $(CXXFLAGS) $(INCFLAGS) $< > $@


$(TARGET): $(ODIR)/test.o $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

clean:
	find ./ -name "*~" -exec rm -rf {} \;
	find ./ -iname "*.[o|d]" -exec rm -rf {} \;

-include $(DEPS)
