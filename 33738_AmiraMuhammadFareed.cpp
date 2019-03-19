
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int n = 0 ,sizeh;
	

class MyHeap {

public:
	vector<int> heap;

	int parent(int node) 
	{
	return node == 0 ? -1 : (node - 1) / 2;
	}
	
	int left(int node) 
	{
		int p = 2 * node + 1;

		return p >= heap.size() ? -1 : p;
	}

	int right(int node) 
	{
		int p = 2 * node + 2;

		return p >= heap.size() ? -1 : p;
	}



	void reheapUp(int in)
	{ 
		if (in == 0 || heap[parent(in)] >= heap[in]) // stop when parent is smaller
			return;

		swap(heap[in], heap[parent(in)]);
		n++;
		reheapUp(parent(in));
	}
	
	void reheapDown(int in) 
	{
	int maxin =in ;

	int selChild = left(in);

	if (selChild == -1) // no children
		return;

	int rightChild = right(in);

	if (rightChild != -1 && heap[rightChild] > heap[selChild] && rightChild < sizeh ) // is right smaller than left?
		selChild = rightChild;

	if(heap[selChild] >heap[maxin] && selChild < sizeh)
		maxin =selChild;

	if(in != maxin )
	{
		swap(heap[in], heap[maxin]);
		n++;
		reheapDown(maxin);
	}
}


	void push(int key)
	{
		heap.push_back(key);
	}

	void buildHeap()
	{
		for(int i=(heap.size()/2)-1 ; i>=0 ;i-- )
		{
			reheapDown(i);
		}
	}

	void HeapSort()
	{
		buildHeap();
		int sizee= heap.size()-1;
		for(unsigned int i=0 ;i<heap.size()-1 ;i++ )
		{
			swap(heap[0] ,heap[sizee]);
			n++;
			sizee--;
			sizeh--;
			reheapDown(0);
		}
	}
};


int main() {
	MyHeap h;
	int number ;
	string b ;
	ifstream ip ("unsorted.txt");
	ofstream op ("output.txt");
	cout.rdbuf(op.rdbuf());

	while(ip.good())
		{
			getline(ip,b,'\n');
			number = stoi(b) ;
			h.push(number);
		}

	sizeh= h.heap.size();
	h.reheapUp(sizeh-1);
	h.HeapSort();

	for(unsigned int i=0 ;i<h.heap.size();i++)
		{
			cout<<h.heap[i]<<"\n" ;
		}

	cout<< n <<endl;
	return 0;

}
