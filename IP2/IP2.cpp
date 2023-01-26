#include <iostream>
#include <string>


using namespace std;

class IPAddress
{
public:
	IPAddress(short int node1, short int node2, short int node3, short int node4) : node1(node1), node2(node2), node3(node3), node4(node4)
	{
	}

	IPAddress( const IPAddress& unit ) {
		this->node1 = unit.node1;
		this->node2 = unit.node2;
		this->node3 = unit.node3;
		this->node4 = unit.node4;
	}

	void virtual print() {
		cout << node1 << "." << node2 << "." << node3 << "." << node4 << "- Unknown\n";
	}

protected:
	short int node1, node2, node3, node4;
};


class IPAddressChecked : public IPAddress
{
public:
	IPAddressChecked(short int node1, short int node2, short int node3, short int node4) : IPAddress(node1, node2, node3, node4)
	{
		if (node1 >= 0 && node1 <= 255 && node2 >= 0 && node2 <= 255 && node3 >= 0 && node3 <= 255 && node4 >= 0 && node4 <= 255)
		{
			valid = true;
		}
		else
		{
			valid = false;
		}
	}
	IPAddressChecked(const IPAddressChecked& unit) : IPAddress( IPAddress(unit.node1, unit.node2, unit.node3, unit.node4) )
	{
		this->valid = unit.valid;
	}

	void print() override {
		cout << node1 << "." << node2 << "." << node3 << "." << node4 << " - ";
		valid? cout << "right\n" : cout << "Wrong\n";
	}

private:
	bool valid;

};


int main()
{
	short int node1, node2, node3, node4;
	cout << "write your first ip (192 168 0 1) ->\n";
	cin >> node1; cin >> node2; cin >> node3; cin >> node4;
	IPAddress u1(node1, node2, node3, node4);

	cout << "write your second ip (192 168 0 1) ->\n";
	cin >> node1; cin >> node2; cin >> node3; cin >> node4;
	IPAddressChecked u2(node1, node2, node3, node4);

	cout << "write your third ip (192 168 0 1) ->\n";
	cin >> node1; cin >> node2; cin >> node3; cin >> node4;
	IPAddressChecked u3(node1, node2, node3, node4);
	cout << "\nResult:\n";
	u1.print();
	u2.print();
	u3.print();
}
