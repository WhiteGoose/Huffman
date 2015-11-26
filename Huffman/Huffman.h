#include<iostream>
//using namespace std;

class Nodes
{
public: int NodeVal;
		Nodes* NodeLeft;
		Nodes* NodeRight;
		Nodes* NodePrev;
	
public: int SetLeft(Nodes*);
		int SetRight(Nodes*);
		int SetPrev(Nodes*);
		int PrintND();
		 
};

int Nodes::SetLeft(Nodes* ND)
{
	this->NodeLeft = ND;
	return 1;
}

int Nodes::SetRight(Nodes* ND)
{
	this->NodeRight = ND;
	return 1;
}

int Nodes::SetPrev(Nodes* ND)
{
	this->NodePrev = ND;
	return 1;
}


void TopSmallestNodes(Nodes* Nodelist, int NodeLength, int* &Smallest);
int huffmanBuild(int IntArray[], int Length);

int huffmanBuild(int IntArray[] , int Length)
{
	Nodes* NodeList = new Nodes[2*Length-1];
	for (int i = 0; i < Length; i++)
	{
		NodeList[i].NodeVal = IntArray[i];
		NodeList[i].NodeLeft = NULL;
		NodeList[i].NodeRight = NULL;
		NodeList[i].NodePrev = NULL; 
	}
	int CurTopListLeng = Length; // Nodes Count with pre=null
	int CurNodeListLength = Length; // Nodes Count
	while (CurTopListLeng > 1)
	{
		
			int* Smallest;
			int X[2] = { -1, -1 };
			Smallest = X;
			
			TopSmallestNodes(NodeList, CurNodeListLength, Smallest);


			NodeList[CurNodeListLength].NodeVal = NodeList[Smallest[0]].NodeVal + NodeList[Smallest[1]].NodeVal;
			NodeList[Smallest[0]].NodePrev = &NodeList[CurNodeListLength];
			NodeList[Smallest[1]].NodePrev = &NodeList[CurNodeListLength];

			NodeList[CurNodeListLength].NodeLeft = &NodeList[Smallest[0]];
			NodeList[CurNodeListLength].NodeRight = &NodeList[Smallest[1]];
			NodeList[CurNodeListLength].NodePrev = NULL;

		//	std::cout << CurNodeListLength << " " << NodeList[CurNodeListLength].NodeVal<<" "<<Smallest[0] << " "<<Smallest[1] << std::endl;

			CurTopListLeng--;
			CurNodeListLength++;
	
	}
	// NodeDisplay(&NodeList[CurNodeListLength-1]);
	return 1;
}


void TopSmallestNodes(Nodes* Nodelist, int NodeLength, int* &Smallest)
{
	
	for (int i = 0; i < NodeLength; i++)
	{
		if (Nodelist[i].NodePrev == NULL)
		{
			if (Smallest[0] == -1 || Nodelist[i].NodeVal < Nodelist[Smallest[0]].NodeVal)
			{
				Smallest[1] = Smallest[0];
				Smallest[0] = i;
			}
			else if (Smallest[1] == -1 || Nodelist[i].NodeVal < Nodelist[Smallest[1]].NodeVal)
			{
				Smallest[1] = i;
			}
			std::cout << Nodelist[i].NodeVal << " ";
		}
	}
	std::cout << std::endl;
}