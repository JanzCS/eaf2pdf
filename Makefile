executecommand:
	g++ -std=c++17 -pthread -o eaf2pdf sacgenerator.cpp
clean:
	rm -f eaf2pdf
