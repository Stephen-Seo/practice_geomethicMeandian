COMMON_FLAGS = -Wall -Wextra -Wpedantic

ifdef DEBUG
	CXXFLAGS = $(COMMON_FLAGS) -g -O0
else
	CXXFLAGS = $(COMMON_FLAGS) -O3 -DNDEBUG
endif

all: GeothmeticMeandian

GeothmeticMeandian: src/main.o
	$(CXX) $(CXXFLAGS) -o GeothmeticMeandian $^

.PHONY:

clean:
	rm -f GeothmeticMeandian
	rm -f src/*.o
