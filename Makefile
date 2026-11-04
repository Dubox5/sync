CC      = gcc
CFLAGS  = -Wall -pthread
TARGET  = sync_car
SRCS    = sync_car-runner.c sync_car.c

all: $(TARGET)

$(TARGET): $(SRCS) sync_car.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
