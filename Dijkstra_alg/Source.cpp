#include <iostream>
#include <limits>
#include <stdio.h>
#include <format>
using namespace std;

//source: https://favtutor.com/blogs/dijkstras-algorithm-cpp


int** dyn_arr_2D(int const&rows);
void populate_arr(int **array_dyn, int const & rows_s);
void output_arr(int** array_dyn, int const& rows_s);
void Dijkstra_Alg(int **graph, int start_point, const int rows);
int min_distance(int* distance_arr, bool* Track_arr, const int& size);


int main() {
	cout << "Enter rows: ";
	int row{};
	cin >> row;
	Dijkstra_Alg(dyn_arr_2D(row), 0, row);

	return 0;
}


int** dyn_arr_2D(int const& rows)
{
	int** graph = new int* [rows];
	for (int i{}; i < rows; i++) {
		graph[i] = new int [rows];
	}
	populate_arr(graph, rows);
	output_arr(graph, rows);

	return graph;
}

void populate_arr(int **array_dyn, int const& rows_s)
{
	int value{};
	for (int i{}; i < rows_s; i++) {
		array_dyn[i] = new int[rows_s];
		for (int j{}; j < rows_s; j++) {
			cout << "input value: "; cin >> value;
			array_dyn[i][j] = value;
		}
	}
	cout << endl;
}

void output_arr(int** array_dyn, int const& rows_s)
{
	for (int i{}; i < rows_s; i++) {
		for (int j{};j< rows_s; j++) {
			cout << array_dyn[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;
}

void Dijkstra_Alg(int** graph, int start_point, const int rows)
{
	
	int* distance = new int[rows];
	bool* Track_set = new bool[rows];

	for (int i{}; i < rows; i++) {
		distance[i] = INT_MAX;
		Track_set[i] = false;
	}

	distance[start_point] = 0;

	for (int i{}; i < rows; i++) {
		int short_path = min_distance(distance, Track_set, rows);
		Track_set[short_path] = true;

		for (int j{}; j < rows; j++) {
			if (!Track_set[j] && graph[short_path][j] && distance[short_path] != 
				INT_MAX && distance[short_path] + graph[short_path][j] < distance[j])
				distance[j] = distance[short_path] + graph[short_path][j];	
		}
	}

	cout << format("{:10}{:10}", "Vertices", "Distance")<<endl;
	for (int a{}; a < rows; a++) {
	cout << format("{:9}{:1}{:7}", static_cast<char>('A' + a),'|',distance[a]) << endl;
	}
}

int min_distance(int* distance_arr, bool* Track_arr, const int& size)
{
	int minimum{ INT_MAX };
	int ind{size};
	
	for (int i{}; i < size; i++) {
		if (Track_arr[i] == false && distance_arr[i] <= minimum) {
			minimum = distance_arr[i];
			ind = i;
		}
	}

	return ind;
}







