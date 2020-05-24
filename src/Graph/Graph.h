/*
 * Graph.h
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <list>
#include <limits.h>
using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

const int INT_INFINITY = INT_MAX;


/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
template <class T> 
class Vertex {
	T info;

	bool visited;
	bool processing;
	int indegree;
	int x;
	int y;
	double dist;

public:
    bool hidden;
    vector<Vertex<T>* > in;
    size_t posAtVec;
	vector<Edge<T>  > adj;
    Vertex(T in);
	friend class Graph<T>;

	void addEdge(Vertex<T> *dest, double w);
	bool removeEdgeTo(Vertex<T> *d);

	T getInfo() const;
	void setInfo(T info);
	int getDist() const;
	int getIndegree() const;
	bool operator<(const Vertex<T> vertex);
	Vertex* path;
	vector<Edge<T>  > getAdj() const;

};
template <class T>
vector<Edge<T> > Vertex<T>::getAdj() const{
    return adj;
}

template <class T>
struct vertex_greater_than {
    bool operator()(Vertex<T> * a, Vertex<T> * b) const {
        return a->getDist() > b->getDist();
    }
};

template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
    d->indegree--;
    for (auto i = adj.begin(); i != adj.end(); i++){
        if (i->dest = d) {
            for (typename vector<Vertex<T>* >::iterator vit = i->dest->in.begin(); vit != i->dest->in.end(); vit++) {//remove from the "in"
                if ((*vit) == this) {
                    i->dest->in.erase(vit);
                    adj.erase(i);
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}


template <class T>
Vertex<T>::Vertex(T in): info(in), visited(false), processing(false), indegree(0), dist(0) {
	path = NULL;
}

template <class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	Edge<T> edgeD(dest,w);
    edgeD.dest->in.push_back(this);
    adj.push_back(edgeD);
}


template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
int Vertex<T>::getDist() const {
	return this->dist;
}


template <class T>
void Vertex<T>::setInfo(T info) {
	this->info = info;
}

template <class T>
int Vertex<T>::getIndegree() const {
	return this->indegree;
}


/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
template <class T>
class Edge {
	Vertex<T> * dest;

public:
	double weight;
	Edge(Vertex<T> *d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;
    Vertex<T>* getNode();
    vector<Vertex<T> *> hidden;
    static Edge<T> mergeEdges(Edge<T> left, Edge<T> right, Vertex<T> * removedVertex);
};

template<class T>
Edge<T> Edge<T>::mergeEdges(Edge<T> left, Edge<T> right, Vertex<T> * removedVertex) {
    Edge<T> res = Edge<T>(right.dest, left.weight + right.weight);
    for (auto v : left.hidden)
        res.hidden.push_back(v);
    res.hidden.push_back(removedVertex);
    for (auto v : right.hidden)
        res.hidden.push_back(v);
    return res;
}

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w){}

template <class T>
Vertex<T>* Edge<T>::getNode() {
    return this->dest;
}





/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;
	void dfs(Vertex<T> *v, vector<T> &res) const;
	int numCycles;
	void dfsVisit(Vertex<T> *v);
	void dfsVisit();
	void getPathTo(Vertex<T> *origin, list<T> &res);

public:

    int ** W;   //weight
    int ** P;   //path


	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	vector<T> dfs() const;
	vector<T> bfs(Vertex<T> *v) const;
	vector<Vertex<T> * > getVertexSet() const;
	int getNumVertex() const;
    Vertex<T> * operator()(int n);
	Vertex<T>* getVertex(const T &v) const;
	void resetIndegrees();
	vector<Vertex<T>*> getSources() const;
    bool connectivity();
	int getNumCycles();
	vector<T> getPath(const T &origin, const T &dest);
	void dijkstraShortestPath(const T &s);
	void floydWarshallShortestPath();
	int edgeCost(int vOrigIndex, int vDestIndex);
    vector<Vertex<T> * > getfloydWarshallPath(const T &origin, const T &dest);
	void getfloydWarshallPathAux(int index1, int index2, vector<Vertex<T> * >  &res );
    Graph<T> * preProcessGraph();
    bool addVertexPointer(Vertex<T> * in);

	
	int getWeight(const T &source, const T &dest);
};

template<class T>
inline bool Graph<T>::addVertexPointer(Vertex<T> * in) {
    typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
    typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
    for (; it != ite; it++)
        if ((*it)->info == in->info) return false;
    in->posAtVec = vertexSet.size();
    vertexSet.push_back(in);
    return true;
}

template<class T>
Graph<T> * Graph<T>::preProcessGraph() {
    Graph<T> * resultGraph = new Graph<T>;
    for (auto v : vertexSet)
        v->hidden = false;

    int countRedundant = 0;
    int countRedundantNotFixed = 0;
    for (auto v : vertexSet) {
        if (v->adj.size() == 1 && v->in.size() == 1) {
            countRedundantNotFixed++;
            Edge<T> enter = Edge<T>(nullptr, 0);
            bool found = false;

            typename vector<Edge<T>>::iterator eit;

            for (eit = v->in[0]->adj.begin(); eit != v->in[0]->adj.end(); eit++) {
                if (eit->dest == v) {
                    found = true;
                    enter = (*eit);
                    break;
                }
            }
            if (found) {
                Edge<T> sum = Edge<T>::mergeEdges(enter, v->adj[0], v);
                v->in[0]->adj.erase(eit);
                v->in[0]->adj.push_back(sum);
                for (auto i = v->adj[0].dest->in.begin(); i != v->adj[0].dest->in.end(); i++) {
                    if ((*i)->getInfo() == v->getInfo()) {
                        v->adj[0].dest->in.erase(i);
                        countRedundant++;
                        break;
                    }
                }
                v->adj[0].dest->in.push_back(v->in[0]);
                v->hidden = true;
            }
        }
    }
    for (auto v : vertexSet)
        if (!v->hidden) {
            if(v->adj.size() > 0)
                resultGraph->addVertexPointer(v);
        }

    cout << "End PreProcessing Graph(" << countRedundant << " Redundant Nodes, "<< countRedundantNotFixed  <<" Found)" << endl;
    return resultGraph;
}

template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}
template <class T>
vector<Vertex<T> * > Graph<T>::getVertexSet() const {
	return vertexSet;
}

template <class T>
int Graph<T>::getNumCycles() {
	numCycles = 0;
	dfsVisit();
	return this->numCycles;
}


template <class T>
bool Graph<T>::addVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite= vertexSet.end();
	for (; it!=ite; it++)
		if ((*it)->info == in) return false;
	Vertex<T> *v1 = new Vertex<T>(in);
    v1->posAtVec = vertexSet.size();
	vertexSet.push_back(v1);
	return true;
}

template <class T>
bool Graph<T>::removeVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite= vertexSet.end();
	for (; it!=ite; it++) {
		if ((*it)->info == in) {
			Vertex<T> * v= *it;
			vertexSet.erase(it);
			typename vector<Vertex<T>*>::iterator it1= vertexSet.begin();
			typename vector<Vertex<T>*>::iterator it1e= vertexSet.end();
			for (; it1!=it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}

			typename vector<Edge<T> >::iterator itAdj= v->adj.begin();
			typename vector<Edge<T> >::iterator itAdje= v->adj.end();
			for (; itAdj!=itAdje; itAdj++) {
				itAdj->dest->indegree--;
			}
			delete v;
			return true;
		}
	}
	return false;
}

template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	typename vector<Vertex<T>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite= vertexSet.end();
	int found=0;
	Vertex<T> *vS, *vD;
	while (found!=2 && it!=ite ) {
		if ( (*it)->info == sourc )
			{ vS=*it; found++;}
		if ( (*it)->info == dest )
			{ vD=*it; found++;}
		it ++;
	}
	if (found!=2) return false;
	vD->indegree++;
	vS->addEdge(vD,w);

	return true;
}


template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	typename vector<Vertex<T>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite= vertexSet.end();
	int found=0;
	Vertex<T> *vS, *vD;
	while (found!=2 && it!=ite ) {
		if ( (*it)->info == sourc )
			{ vS=*it; found++;}
		if ( (*it)->info == dest )
			{ vD=*it; found++;}
		it ++;
	}
	if (found!=2)
		return false;

	vD->indegree--;

	return vS->removeEdgeTo(vD);
}

template <class T>
vector<T> Graph<T>::dfs() const {
	typename vector<Vertex<T>*>::const_iterator it= vertexSet.begin();
	typename vector<Vertex<T>*>::const_iterator ite= vertexSet.end();
	for (; it !=ite; it++)
		(*it)->visited=false;
	vector<T> res;
	it=vertexSet.begin();
	for (; it !=ite; it++)
	    if ( (*it)->visited==false )
	    	dfs(*it,res);
	return res;
}

template <class T>
void Graph<T>::dfs(Vertex<T> *v,vector<T> &res) const {
	v->visited = true;
	res.push_back(v->info);
	typename vector<Edge<T> >::iterator it= (v->adj).begin();
	typename vector<Edge<T> >::iterator ite= (v->adj).end();
	for (; it !=ite; it++)
	    if ( it->dest->visited == false ){
	    	dfs(it->dest, res);
	    }
}

template <class T>
vector<T> Graph<T>::bfs(Vertex<T> *v) const {
	vector<T> res;
	queue<Vertex<T> *> q;
	q.push(v);
	v->visited = true;
	while (!q.empty()) {
		Vertex<T> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		typename vector<Edge<T> >::iterator it=v1->adj.begin();
		typename vector<Edge<T> >::iterator ite=v1->adj.end();
		for (; it!=ite; it++) {
			Vertex<T> *d = it->dest;
			if (d->visited==false) {
				d->visited=true;
				q.push(d);
			}
		}
	}
	return res;
}
template <class T>
bool Graph<T>::connectivity() {
    vector<T> vecDfs1 = dfs();

    Graph<T> Gr;

    for (int i = 0; i < getNumVertex(); i++) {
        for (size_t j = 0; j < vertexSet.at(i)->adj.size(); j++) {
            Gr.addVertex(vertexSet.at(i)->adj.at(j).getNode()->getInfo());
            Gr.addVertex(vertexSet.at(i)->getInfo());
            Gr.addEdge(vertexSet.at(i)->adj.at(j).dest->info,
                       vertexSet.at(i)->info, vertexSet.at(i)->adj.at(j).weight);
        }
    }

    vector<T>  vecDfs2 = Gr.dfs();

    if ((int)  vecDfs1.size() != getNumVertex()
        || (int)  vecDfs2.size() != getNumVertex()) {
        return false;
    } else
        return true;
}

template <class T>
Vertex<T>* Graph<T>::getVertex(const T &v) const {
	for(unsigned int i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == v) return vertexSet[i];
	return NULL;
}

template<class T>
void Graph<T>::resetIndegrees() {

	for(unsigned int i = 0; i < vertexSet.size(); i++) vertexSet[i]->indegree = 0;


	for(unsigned int i = 0; i < vertexSet.size(); i++) {

		for(unsigned int j = 0; j < vertexSet[i]->adj.size(); j++) {
			vertexSet[i]->adj[j].dest->indegree++;
		}
	}
}


template<class T>
vector<Vertex<T>*> Graph<T>::getSources() const {
	vector< Vertex<T>* > buffer;
	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		if( vertexSet[i]->indegree == 0 ) buffer.push_back( vertexSet[i] );
	}
	return buffer;
}


template <class T>
void Graph<T>::dfsVisit() {
	typename vector<Vertex<T>*>::const_iterator it= vertexSet.begin();
	typename vector<Vertex<T>*>::const_iterator ite= vertexSet.end();
	for (; it !=ite; it++)
		(*it)->visited=false;
	it=vertexSet.begin();
	for (; it !=ite; it++)
	    if ( (*it)->visited==false )
	    	dfsVisit(*it);
}

template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v) {
	v->processing = true;
	v->visited = true;
	typename vector<Edge<T> >::iterator it= (v->adj).begin();
	typename vector<Edge<T> >::iterator ite= (v->adj).end();
	for (; it !=ite; it++) {
		if ( it->dest->processing == true) numCycles++;
	    if ( it->dest->visited == false ){
	    	dfsVisit(it->dest);
	    }
	}
	v->processing = false;
}


template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest){

	list<T> buffer;
	Vertex<T>* v = getVertex(dest);

	buffer.push_front(v->info);
	while ( v->path != NULL &&  v->path->info != origin) {
		v = v->path;
		buffer.push_front(v->info);
	}
	if( v->path != NULL )
		buffer.push_front(v->path->info);


	vector<T> res;
	while( !buffer.empty() ) {
		res.push_back( buffer.front() );
		buffer.pop_front();
	}
	return res;
}

template<class T>
vector<Vertex<T> * > Graph<T>::getfloydWarshallPath(const T &origin, const T &dest){

	int originIndex = -1, destinationIndex = -1;

	for(unsigned int i = 0; i < vertexSet.size(); i++)
	{
		if(vertexSet[i]->info == origin)
			originIndex = i;
		if(vertexSet[i]->info == dest)
			destinationIndex = i;

		if(originIndex != -1 && destinationIndex != -1)
			break;
	}


    vector<Vertex<T> * > res;

	
	if(W[originIndex][destinationIndex] == INT_INFINITY)
		return res;

	res.push_back(vertexSet[originIndex]);

	if(P[originIndex][destinationIndex] != -1)
	{
		int intermedIndex = P[originIndex][destinationIndex];

		getfloydWarshallPathAux(originIndex, intermedIndex, res);

		res.push_back(vertexSet[intermedIndex]);

		getfloydWarshallPathAux(intermedIndex,destinationIndex, res);
	}

	res.push_back(vertexSet[destinationIndex]);

	return res;
}



template<class T>
void Graph<T>::getfloydWarshallPathAux(int index1, int index2, vector<Vertex<T> * >  &res)
{
	if(P[index1][index2] != -1)
	{
		getfloydWarshallPathAux(index1, P[index1][index2], res);
		res.push_back(vertexSet[P[index1][index2]]);

		getfloydWarshallPathAux(P[index1][index2],index2, res);
	}
}



template<class T>
void Graph<T>::dijkstraShortestPath(const T &s) {

	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->processing = false;
	}

	Vertex<T>* v = getVertex(s);
	v->dist = 0;

	vector< Vertex<T>* > pq;
	pq.push_back(v);

	make_heap(pq.begin(), pq.end());


	while( !pq.empty() ) {

		v = pq.front();
		pop_heap(pq.begin(), pq.end());
		pq.pop_back();

		for(unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;

			if(v->dist + v->adj[i].weight < w->dist ) {

				w->dist = v->dist + v->adj[i].weight;
				w->path = v;

				if(!w->processing)
				{
					w->processing = true;
					pq.push_back(w);
				}

				make_heap (pq.begin(),pq.end(),vertex_greater_than<T>());
			}
		}
	}
}

template<class T>
int Graph<T>::edgeCost(int vOrigIndex, int vDestIndex)
{
	if(vertexSet[vOrigIndex] == vertexSet[vDestIndex])
		return 0;

	for(unsigned int i = 0; i < vertexSet[vOrigIndex]->adj.size(); i++)
	{
		if(vertexSet[vOrigIndex]->adj[i].dest == vertexSet[vDestIndex])
			return vertexSet[vOrigIndex]->adj[i].weight;
	}

	return INT_INFINITY;
}





template<class T>
void Graph<T>::floydWarshallShortestPath() {

	W = new int * [vertexSet.size()];
	P = new int * [vertexSet.size()];
	for(unsigned int i = 0; i < vertexSet.size(); i++)
	{
		W[i] = new int[vertexSet.size()];
		P[i] = new int[vertexSet.size()];
		for(unsigned int j = 0; j < vertexSet.size(); j++)
		{
			W[i][j] = edgeCost(i,j);
			P[i][j] = -1;
		}
	}


	for(unsigned int k = 0; k < vertexSet.size(); k++)
		for(unsigned int i = 0; i < vertexSet.size(); i++)
			for(unsigned int j = 0; j < vertexSet.size(); j++)
			{
				if(W[i][k] == INT_INFINITY || W[k][j] == INT_INFINITY)
					continue;

				int val = min ( W[i][j], W[i][k]+W[k][j] );
				if(val != W[i][j])
				{
					W[i][j] = val;
					P[i][j] = k;
				}
			}

}

template<class T>
int Graph<T>::getWeight(const T &source, const T &dest) {
	int s=0,d=0;

	for(unsigned int i=0; i<vertexSet.size(); i++) {
		if(vertexSet[i]->getInfo() == getVertex(source)->getInfo())
			s=i;
		else if(vertexSet[i]->getInfo() == getVertex(dest)->getInfo())
			d=i;
	}

	return edgeCost(s,d);
}


template<class T>
inline Vertex<T>* Graph<T>::operator()(int n) {
    return vertexSet[n];
}




#endif /*GRAPH_H_ */
