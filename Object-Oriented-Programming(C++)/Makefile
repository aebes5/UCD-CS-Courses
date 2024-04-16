all: NumberGuessingGame

CXX = clang++
override CXXFLAGS += -g -Wno-everything

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

NumberGuessingGame: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

NumberGuessingGame-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f NumberGuessingGame NumberGuessingGame-debug