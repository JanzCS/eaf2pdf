executecommand:
	g++ -std=c++17 -lpthread -o eaf2pdf sacgenerator.cpp
clean:
	rm -f eaf2pdf
