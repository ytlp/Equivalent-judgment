obj = main.o createInput.cpp execute.cpp compare.cpp
target = main
CC = g++

$(target): $(obj)
	$(CC) $(obj) -o $(target)
        
%.o: %.cc
	$(CC) -c $< -o $@ -g

clean: 
	rm *.o main
