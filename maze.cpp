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
	{x = -1; y = -1;}
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
	public:
	Node(int x, int y, int **arr)
	{
		this->coordinates.set(x, y);
		dead = false;
		this->next = NULL;
		this->generate_queue(arr);
		if(x==3 && y==3)
		dest = true;
//		Location coordinates(x, y);
	}

	void set_coordinates(int x, int y)
	{
		coordinates.set(x, y);
	}

	void generate_queue(int **arr)
	{
		int x = this->coordinates.retx();
		int y = this->coordinates.rety();
		if(arr[x-1][y+1] == 0)
		{
		Location obj(x-1, y+1);
		possible_paths.push(obj);
		}

		if(arr[x][y+1] == 0)
		{
		Location obj(x, y+1);
		possible_paths.push(obj);
		}

		if(arr[x+1][y+1] == 0)
		{
		Location obj(x+1, y+1);
		possible_paths.push(obj);
		}

		if(arr[x+1][y] == 0)
		{
		Location obj(x+1, y);
		possible_paths.push(obj);
		}

		if(arr[x+1][y-1] == 0)
		{
		Location obj(x+1, y-1);
		possible_paths.push(obj);
		}

		if(arr[x][y-1] == 0)
		{
		Location obj(x, y-1);
		possible_paths.push(obj);
		}

		if(arr[x-1][y-1] == 0)
		{
		Location obj(x-1, y-1);
		possible_paths.push(obj);
		}

		if(arr[x-1][y] == 0)
		{
		Location obj(x-1, y);
		possible_paths.push(obj);
		}
		if(possible_paths.empty())
		dead = true;
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

	Location ret_front(){ return possible_paths.front();}
	void pop_front() { if(!possible_paths.empty()){possible_paths.pop();if(possible_paths.empty())this->dead = true;}}
	Location ret_front_and_pop(){Location temp = this->ret_front(); this->pop_front(); return temp;}
};

class Path{
	stack<Node*> backtrack;
	Node *head;
	Location destination;
	int** maze;

	public:
	Path(int **mz)
	{
		this->maze = mz;
		destination.set(3,3);
		head = new Node(1, 1, mz);
		backtrack.push(head);
	}

	Node* calculate_next(Node *node)
	{
		Location temp = node->ret_front();
		Node *next_node = new Node(temp.retx(), temp.rety(), maze);
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
		Node *first = calculate_next();
		if(first!=NULL)
		{
		cout<<"first node: \t"; head->print_coordinates(); cout<<endl;
		cout<<"second node: \t";first->print_coordinates();cout<<endl;
		}
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
