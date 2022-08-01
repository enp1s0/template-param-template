CXX=g++
CXXFLAGS=-std=c++14

TARGET=temp-param-temp.test

$(TARGET):main.cpp
	$(CXX) $< -o $@ $(CXXFLAGS)
  
clean:
	rm -f $(TARGET)
