CXX=clang++-14
TARGET=test
SDIR=src
ODIR=obj

SRCS=test.cpp demo_binder.cpp inheritance.cpp algo.cpp execution_path_comparison.cpp json_c.cpp touple.cpp timeout_test.cpp vec_insert.cpp pass_smartptr.cpp endian.cpp regex_test.cpp nlohmann_test.cpp llvm-jit.cpp curl_example.cpp task_q.cpp sign_convert.cpp linear_regression.cpp armadillo_test.cpp gnuplot.cpp serial_test.cpp asio_async_handler.cpp permutation.cpp chrono_test.cpp time_zone_test.cpp

CXXFLAGS=$(DEBUG_FLAGS) -std=c++14 -Wall -fPIC

OBJS=$(patsubst %.cpp, $(ODIR)/%.o, $(SRCS))
DEPS=$(patsubst %.cpp, $(ODIR)/%.d, $(SRCS))

lrt:=$(shell echo "int main() {}"|$(CXX) -x c - -lrt 2>&1 ; rm -f a.out)
ifeq ($(lrt),)
  lrtlibs:=-lrt
else
  lrtlibs:=
endif

LIBS= -lstdc++  -pthread -lcurl $(lrtlibs) -larmadillo
LIBS+= $(shell pkg-config --libs json-c)
LIBS+= $(shell llvm-config --ldflags --libs 2>/dev/null || echo "")
LIBS+= -lboost_system -lboost_filesystem -lboost_iostreams
INCFLAGS= -Iinc -I/usr/include
INCFLAGS += $(shell pkg-config --cflags json-c)
INCFLAGS += $(shell llvm-config --cflags 2>/dev/null || echo "")

.PHONY:	$(TARGET) check_deps

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -o $@ $(OBJS) $(LIBS)

check_deps:
	@if ! dpkg -s libjson-c-dev > /dev/null 2>&1 || ! dpkg -s libgnuplot-iostream-dev > /dev/null 2>&1; then \
		echo "Checking system dependencies..."; \
		for dep in libjson-c-dev libgnuplot-iostream-dev; do \
			if ! dpkg -s $$dep > /dev/null 2>&1; then \
				echo "Package $$dep is not installed. Installing..."; \
				sudo apt-get install -y $$dep; \
			fi; \
		done; \
	fi

# Objects generation
$(ODIR)/%.o:    $(SDIR)/%.cpp | check_deps
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c -MMD $< -o $@

# Generating dependencies
$(ODIR)/%.d:    $(SDIR)/%.cpp
	$(CXX) -M $(CXXFLAGS) $(INCFLAGS) -MT $(ODIR)/$*.o $< > $@




clean:
	find ./ -name "*~" -exec rm -rf {} \;
	find ./ -iname "*.[o|d]" -exec rm -rf {} \;
	rm -f $(TARGET)

-include $(DEPS)
