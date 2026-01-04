CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -I.
TARGET = yans
SRC = main.cpp MAC.cpp IP.cpp
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

c:
	rm -rf $(OBJ) $(TARGET)

r:
	./$(TARGET)

b: $(TARGET)
