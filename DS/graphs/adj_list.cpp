#include <iostream>
#include <vector>

using namespace std;


vector <int> adj[10];



int main()
{
		int x, y, nodes, edges;
		cin >> nodes;
		cin >> edges;

		for(int i=0; i<edges; i++)
		{
				cin >> x >> y;
				adj[x].push_back(y); // insert y in adj list of x
		}

		for(int i=1; i<=nodes; i++)
		{
				cout << "Adj nodes to node " << i << " are ";
				for(auto x: adj[i])
						cout << x << " ";
				cout << endl;
		}

		return 0;

}
