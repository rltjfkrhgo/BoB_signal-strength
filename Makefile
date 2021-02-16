CC=g++
CFLAGS=-c
LDFLAGS=-lpcap
SOURCES=mac.cpp SignalStrength.cpp SignalStrengthMain.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=signal-strength

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)