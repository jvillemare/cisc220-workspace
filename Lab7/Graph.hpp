/*
 * Graph.hpp
 *
 *  Created on: Dec 3, 2019
 *      Author: jvillemarette
 */

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Graph {

	int **adjMatrix;
	int numOfVerts;
	int start;
	string *dataArr;

	//BinHeap priorityQueue();

	bool *visited;
	int *distances;
	int *prev;

public:

	Graph(int n, int first, string vertexnames[]);
	void dijkstra();
	void setDistances(int lv);
	int minDistance();
	void printAdjMat();
	void printInfoSoFar();
	void printPath(int end);
	void genGraph();

};
#endif /* GRAPH_HPP_ */
