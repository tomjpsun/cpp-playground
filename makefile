CXX=clang++
TARGET=test
SDIR=src
ODIR=obj

SRCS=test.cpp demo_binder.cpp inheritance.cpp algo.cpp execution_path_comparison.cpp json_c.cpp touple.cpp timeout_test.cpp vec_insert.cpp pass_smartptr.cpp endian.cpp regex_test.cpp nlohmann_test.cpp curl_example.cpp llvm-jit.cpp task_q.cpp sign_convert.cpp linear_regression.cpp armadillo_test.cpp gnuplot.cpp

CXXFLAGS=$(DEBUG_FLAGS) -std=c++14 -Wall -fPIC

OBJS=$(patsubst %.cpp, $(ODIR)/%.o, $(SRCS))
DEPS=$(patsubst %.cpp, $(ODIR)/%.d, $(SRCS))

lrt:=$(shell echo "int main() {}"|clang -x c - -lrt 2>&1 ; rm a.out)
ifeq ($(lrt),)
  lrtlibs:=-lrt
else
  lrtlibs:=
endif

LIBS= -lstdc++  -pthread -lcurl $(lrtlibs) -larmadillo
LIBS+= $(shell pkg-config --libs json-c)
LIBS+= -lLLVM -L/usr/local/opt/llvm/lib
LIBS+= -lboost_system -lboost_filesystem -lboost_iostreams
INCFLAGS= -Iinc -I/usr/include
INCFLAGS += $(shell pkg-config --cflags json-c)
INCFLAGS +=  -I/usr/local/opt/llvm/include

.PHONY:	clean $(TARGET)
# Objects generation
$(ODIR)/%.o:    $(SDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c -MMD $< -o $@

# Generating dependencies
$(ODIR)/%.d:    $(SDIR)/%.cpp
	$(CXX) -M $(CXXFLAGS) $(INCFLAGS) $< > $@


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	find ./ -name "*~" -exec rm -rf {} \;
	find ./ -iname "*.[o|d]" -exec rm -rf {} \;
	rm $(TARGET)

-include $(DEPS)
