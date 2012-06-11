// Main() //-----------------------------

//#include "ListA.h" // ADT list operations
//#include "MovieType.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class MovieType
{
	private:
		string title;
	public:
		MovieType();
		MovieType(string title);
		void display();
		int compareKeys(MovieType *other);
		//static bool readOneMovieFromFile(ifstream& moviesFile);
		static MovieType* readOneMovieFromFile(ifstream& moviesFile);

};
class SortedMovieList
{
	private:
		static const int MAXSIZE = 50;
		MovieType *movies[MAXSIZE];
		int count;
		int findInsertPosition(MovieType *movie);
	public:
		SortedMovieList();
		void insert(MovieType *movie);
		void displayMovies();
		void readAllMoviesFromFile(ifstream& moviesFile);
};
int main()
{
  ifstream moviesFile ("C:\\Documents and Settings\\Administrator\\My Documents\\Visual Studio 2010\\Projects\\proj3\\titles.txt");
  SortedMovieList movieList;
  movieList.readAllMoviesFromFile(moviesFile);
  movieList.displayMovies();
  system("pause");
}  // end main

//MovieType stuff
MovieType::MovieType()
:title("")
{}

MovieType::MovieType(string aTitle)
{
	title=aTitle;
}

void MovieType::display()
{
	cout << "Title: " << title << endl;
}

int MovieType::compareKeys(MovieType *other)
{
	return title.compare(other->title);
}

MovieType* MovieType::readOneMovieFromFile(ifstream& moviesFile)
{
	string line;
	getline (moviesFile,line);
    if (line == "***")
		return NULL;
	MovieType *movie = new MovieType(line);
	return movie;
}


//SortedMovieList stuff
SortedMovieList::SortedMovieList()
{
	count = 0;
}

int SortedMovieList::findInsertPosition(MovieType *movie)
{
	for (int i = 0; i < count; i++)
	{
		if (movie->compareKeys(movies[i]) < 0)
		{
			return i;
		}
	}
	return count;
}

void SortedMovieList::insert(MovieType *movie)
{
	int insertPosition = findInsertPosition(movie);
	for (int i = count; i > insertPosition; i--)
	{
		movies[i] = movies[i-1];
	}
	movies[insertPosition] = movie;
	count++;
}


void SortedMovieList::displayMovies()
{
	for (int i = 0; i < count; i++)
	{
		movies[i]->display();
	}
}

void SortedMovieList::readAllMoviesFromFile(ifstream& moviesFile)
{
	string title;
	MovieType *movie;
	if (moviesFile.is_open())
	{
		while ( moviesFile.good())// && movie = MovieType.readOneMovieFromFile(moviesFile))
		{
			
			insert(movie);
		}
		moviesFile.close();
	}
	else cout << "Unable to open file"; 
}
