#include"List.h"
int main(){
	cout << "Create and fill first list:\nAdd to tail:\n";
	List<int> list1,list2,list3;
	list1.AddToTail(4);
	list1.Show();
	list1.AddToTail(10);
	list1.Show();
	list1.AddToTail(4);
	list1.Show();
	cout << "\nAdd to head:\n";
	list1.AddToHead(7);
	list1.Show();
	list1.AddToHead(0);
	list1.Show();
	list1.AddToHead(13);
	list1.Show();
	cout << "\nAdd in position:\n";
	list1.Add(3, 3);
	list1.Show();
	list1.Add(1,7);
	list1.Show();
	list1.Add(100, list1.GetCount() / 2);
	list1.Show();
	//cout << "\nSecond list = first list.\n";
	//list2 =list1;
	//cout << "\nDelete from head:\n";
	//list1.DeleteHead();
	//list1.Show();
	//cout << "\nDelete from tail:\n";
	//list1.Show();
	//cout << "\nDelete from position:\n";
	//list1.Delete(5);
	//list1.Show();
	//list1.Delete(2);
	//list1.Show();
	//cout << "\nSeconst list:\n";
	//list2.Show();;
	//cout << "\nList 1 * List 2:\n";
	//list3 = list1*list2;
	//list3.Show();
	//cout << "\nList 1 + List 2:\n";
	//list3 = list1 + list2;
	//list3.Show();
	//cout << "\nReverse first list:\n";
	//list3 = -list1;
	//list3.Show();
	//cout << "\nReverse second list:\n";
	//list3 = -list2;
	//list3.Show();
	return 0;
}