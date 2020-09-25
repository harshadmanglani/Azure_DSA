#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//1 is a blocked path
//0 is a free path

class Location{
	int x;
	int y;

	public:
	Location()
	{
		this->x = -1;
		this->y = -1;
	}

	Location(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void set(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator == (Location &obj)
	{
		if(this->x == obj.x && this->y == obj.y)
		return true;
		return false;
	}

	int retx(){return this->x;}
	int rety(){return this->y;}
};

// dead_obj is a variable to pass as parent for the first node (source)
Location dead_obj(0,0);
//visited is an array of locations to help in generating the possible_paths for a node avoiding repetition
Location visited[50];
int i = 0;
//check returns if a location is already part of another node's possible queue
bool check(Location obj)
{
	for(int j = 0; j < i; j++)
	if(obj == visited[j])
	return false;
	return true;
}
//insert will insert a new location into the array
bool insert(Location obj)
{
	visited[i] = obj;
	i++;
}

class Node
{
	/// coordinates - x and y location of the node
	/// possible_paths - a queue of locations where the mouse can go next - all 8 directions
	/// dead - a boolean variable which is true if possible_paths is an empty queue
	/// dest - a boolean variable which is true if it is the final destination (trigger handled in class Path)
	/// parent - a location variable to skip adding the parent node into the queue of the current node (thus avoiding a cycle where nodes keep generating each other as possible paths)
	/// arr - the actual maze to determine possible_paths

	Location coordinates;
	queue<Location> possible_paths;
	bool dead;
	bool dest;
	int **arr;
	Location parent;
	public:

	//constructor
	Node(Location cd, int **arr, Location p)
	{
		this->coordinates = cd;
		this->dead = false;
		this->arr = arr;
		this->set_dest_false();
		this->parent.set(p.retx(), p.rety());
		this->generate_queue();
	}

	//determines if (x, y) can be added as node in possible_paths
	void set_path(int x, int y)
	{
		//checking if the path is blocked
		if(arr[x][y] == 0)
		{
			Location obj(x, y);
			//checking that the (x, y) is not the parent and hasn't been visited before
			if(!(obj ==  this->parent) && check(obj))
			{
				possible_paths.push(obj);
				insert(obj);
			}
		}
	}

	//generating the queue by considering all 8 directions
	void generate_queue()
	{
		int x = this->coordinates.retx();
		int y = this->coordinates.rety();
		set_path(x-1, y+1);
		set_path(x, y+1);
		set_path(x+1, y+1);
		set_path(x+1, y);
		set_path(x+1, y-1);
		set_path(x, y-1);
		set_path(x-1, y-1);
		set_path(x-1, y);

		//trigger to assign true to dead if possible_paths is empty
		check_and_set_dead();
	}

	void check_and_set_dead()
	{
		if(possible_paths.empty())
			this->dead = true;
	}

	void print_coordinates()
	{
		cout<<"x: "<<coordinates.retx()<<" y: "<<coordinates.rety();
	}

	bool is_dead()
	{
		return this->dead;
	}

	void print_queue()
	{
		queue<Location> temp(this->possible_paths);
		while(!temp.empty())
		{
			cout<<"x: "<<(temp.front().retx())<<" y: "<<(temp.front().rety())<<" | ";
			temp.pop();
		}
	}

	void set_dest_true()
	{
		this->dest = true;
	}

	void set_dest_false()
	{
		this->dest = false;
	}

	bool is_dest()
	{
		return dest;
	}

	Location ret_front()
	{
		return possible_paths.front();
	}

	void pop_front()
	{
		if(!possible_paths.empty())
			possible_paths.pop();
		check_and_set_dead();
	}

	Location ret_front_and_pop()
	{
		Location temp = this->ret_front();
		this->pop_front();
		return temp;
	}

	Location ret_location()
	{
		return this->coordinates;
	}
};

class Path{

	/// backtrack - a stack to keep track of the nodes walked through till we reach the path
	/// current - the current node we're at, starts with (1, 1)
	/// start and destination - arbitrary locations passed during construction
	/// maze - the actual maze
	stack<Node*> backtrack;
	Node *current;
	Location start;
	Location destination;
	int** maze;
	public:

	//constructor
	Path(int **mz, Location start, Location dest)
	{
		this->maze = mz;
		this->destination = dest;
		this->start = start;
		this->current = new Node(start, mz, dead_obj);
		this->backtrack.push(current);
	}

	//calculates the next node to go to given a node
	Node* calculate_next(Node *node)
	{
		if(node->is_dead())
		return NULL;
		//pop one element from node's generated queue - possible_paths
		Location temp = node->ret_front_and_pop();
		Node *next_node = new Node(temp, maze, node->ret_location());
		if(next_node->ret_location() == this->destination)
			next_node->set_dest_true();
		if(next_node->is_dead() && !next_node->is_dest())
		{
			delete next_node;
			return NULL;
		}

		else
			return next_node;
	}

	void find()
	{
		// cout<<"in\n";
		while(!current->is_dest())
		{

			while(!current->is_dead())
			{
				cout<<"coordinates for current node: "; current->print_coordinates(); cout<<endl;
				cout<<"queue for current node: ";current->print_queue(); cout<<endl;
				Node *temp = calculate_next(current);
				if(temp == NULL)
				continue;
				current = temp;
				backtrack.push(current);
				if(current->is_dest())
				{
					print_path();
					break;
				}
				cout<<endl<<endl;
			}

			if(current->is_dead() && !current->is_dest())
			{
				if(!backtrack.empty())
				{
					backtrack.pop();
					if(!backtrack.empty())
					{
						cout<<"backtracking...\n";
						current = backtrack.top();
					}

					else
						{
							cout<<"Stack empty"<<endl;
							break;
						}
				}
			}
		}
	}

	void print_path()
	{
		stack<Node*> temp = backtrack;
		cout<<"Printing the path..\n";
		while(!temp.empty())
		{
			temp.top()->print_coordinates(); cout<<" <-- ";
			temp.pop();
		}
	}
};

int main()
{
	int r, c;
	r = c = 6;
	int maze[r][c] = {
			{1, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 1, 1},
			{1, 0, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 1},
			{1, 1, 1, 0, 0, 1},
			{1, 1, 1, 1, 1, 1}
			};
	int **mz = new int*[r];
	Location start(1, 1);
	Location dest(4, 4);
	for(int i = 0; i<r; i++)
		mz[i] = new int[c];
	for(int i = 0; i<r; i++)
		for(int j = 0; j < c; j++)
			mz[i][j] = maze[i][j];
	Path obj(mz, start, dest);
	obj.find();
return 0;
}
