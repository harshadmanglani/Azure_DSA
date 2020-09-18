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
	int retx(){return this->x;}
	int rety(){return this->y;}
};

class Node{
	Location coordinates;
	queue<Location> possible_paths;
	bool dead;
	bool dest;
	Node *next;
	int **arr;
	public:
	Node(Location cd, int **arr)
	{
		this->coordinates = cd;
		this->dead = false;
		this->next = NULL;
		this->arr = arr;
	}

	void set_path(int x, int y)
	{
		if(arr[x][y] == 0)
		{
			Location obj(x, y);
			possible_paths.push(obj);
		}
	}

	void generate_queue(int **arr)
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
		if(!possible_paths.empty()){possible_paths.pop();
		check_and_set_dead();
	}

	Location ret_front_and_pop()
	{
		Location temp = this->ret_front();
		this->pop_front();
		return temp;
	}
};

class Path{
	stack<Node*> backtrack;
	Node *head;
	Location destination;
	int** maze;
	Location start;
	public:
	Path(int **mz, Location start, Location dest)
	{
		this->maze = mz;
		this->destination = dest;
		this->start = start
		this->head = new Node(start, mz);
		this->backtrack.push(head);
	}

	Node* calculate_next(Node *node)
	{
		Location temp = node->ret_front();
		Node *next_node = new Node(temp, maze);
		if(next_node->is_dead())
		{
			delete next_node;
			return NULL;
		}

		else
			return next_node;
	}

	void find()
	{

	}

};

int main()
{
	int maze[5][5] = {1,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,1,1,1,1};
	int **mz = new int*[5];
	for(int i = 0; i<5; i++)
		mz[i] = new int[5];
	for(int i = 0; i<5; i++)
		for(int j = 0; j < 5; j++)
			mz[i][j] = maze[i][j];
	Path obj(mz);
	obj.find();
return 0;
}
