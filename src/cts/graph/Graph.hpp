#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <stdexcept>
class Vertex;
class Edge;
class Graph{
	private:
		std::vector<Vertex*> *vertices;
		int num_components;//only used for printing
	public:
		Graph();
		~Graph();	
	private:
		void DFS_for_component_analysis();
		void normalize();//combines multi-edges in one edge, that can occur if a join has more than one predicate 
						//or if more than one selection is applied to a base relation
		Edge* from_to(Vertex* from, Vertex* to);
		void collapse(unsigned int Vertex1,unsigned int Vertex2); //should be performed only on normalized undirected graph!!
		Edge* find_min_edge();	//finds the next edge to collapse for GOO	
		void push_down_selections();	
		
	public:
		void print_connectivity_components();
		void create_new_vertex(int size, std::string name);
		void create_new_edge(std::string beginning, std::string destiny, double weight, std::string edge_name, bool directed=false);
		std::string Greedy_operator_ordering();
		

};



class Vertex{
	friend class Graph;
	private:
		int size;
		std::string name;//must be unique
		std::vector<Edge*> *outgoings;
		int component;//for printing componentwise
	public:
		Vertex(int sizee, std::string namee);
		~Vertex();
		void add_outgoing_edge(Edge* e);	

};


class Edge{
	friend class Graph;
	private:
		int begin_id;//stores the position of the begin_node in the vector of the graph class
		int end_id;
		double weight;
		std::string name_edge;//name of the join condition(or name of the selection, if it is a loop)
	public:
		Edge(int begin,int end, double w, std::string name);
		
};



#endif /* GRAPH_HPP_ */
