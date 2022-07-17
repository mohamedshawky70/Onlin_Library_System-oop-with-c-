#include <bits/stdc++.h>
#define ll  long long
#define ld  long double
#define sz   size 
#define el   endl 
using namespace std;

class User                   //////////////////calss User////////////////////
{
private:
	string name;
	int age;
	int id;
	string password;
	string email;
public:
	static int count;   //static class member
	User()              //empty constructor
	{
		name = "";
		age = 0;
		password = "";
		email = "";
		count++;
		id = count;
	}
	User(string name, int age, string password, string email) //pramatrize constructor
	{
		this->name = name;
		this->age = age;
		this->password = password;
		this->email = email;
	}
	void set_name(string name) //setter
	{
		this->name = name;    //this pointer
	}
	string get_name()const  //getter
	{
		return name;
	}
	void set_age(int age)
	{
		this->age = age;
	}
	int get_age()const
	{
		return age;
	}
	void set_id(int id)
	{
		this->id = id;
	}
	int get_id()const
	{
		return id;
	}
	void set_password(string password)
	{
		this->password = password;
	}
	string get_password()const
	{
		return password;
	}
	void set_email(string email)
	{
		this->email = email;
	}
	string get_email()const
	{
		return email;
	}
	User(const User& user) //copy constructor
	{
		name = user.name;
		age = user.age;
		id = user.id;
		password = user.password;
		email = user.email;
	}
	bool operator==(const User& user) //operator overloading binary(==)
	{
		return(name == user.name);
	}
	void display_info()
	{
		cout << "****************************************" << el;
		cout << "Name :" << name << el;
		cout << "Age  :" << age << el;
		cout << "Id   :" << id << el;
		cout << "Email:" << email << el;
		cout << "Password:" << password << el;
		cout << "****************************************" << el;

	}
	friend istream& operator>>(istream& input, User& user) //cin>>
	{
		int R = -1,RR=-1,d=0,s=0,l=0,u=0,ss=0;
		bool ok = false;
		cout << "Name(Triple):";
		cin.ignore();
        getline(input, user.name);
		cout << "Age :";
		input >> user.age;
		while (R == -1)
		{
			cout << "Gmail(In Formula ****@gmail.com) :";
			input >> user.email;
			try                                       //exception handling
			{
				for (int i = 0; i <user.email.size(); i++)
				{
					if (user.email.substr(i,10) == "@gmail.com")ok = true;
				}
				if (!ok)throw exception();
				R = 0;
			}
			catch (exception e)
			{
				cout << e.what()<<el;
			}
		}
		while (RR == -1)
		{
			cout << "Password(strong: At Least One UpperCase Litter , One LowerCase Litter , One Digit And One Symbole) :";
			input >> user.password;
			for (int i = 0; i < user.password.size(); i++)
			{
				if (isdigit(user.password[i]))d++;
				else if (isupper(user.password[i]))u++;
				else if (islower(user.password[i]))l++;
				else s++; //symbol
			}
			try
			{
				if (d == 0 || s == 0 || u==0 || l==0)throw exception();
				RR = 0;
				cout << "Good , Strong password" << el;
			}
			catch (exception)
			{
				ss = 0;
				cout << "Weak Password Try Again Ya Norm" << el;
			}
		}
		return input;
	}
	friend ostream& operator<<(ostream& output, User user) //cout<<
	{
		int x;
		cout << "======================================" << el;
		cout << "Your Name :";
		output << user.name<<el;
		user.name.clear();
		cout << "Your Age :";
		output << user.age << el;
		cout << "Your Gmail :";
		output << user.email << el;
		cout << "Your Id :";
		output << user.id << el;
		cout << "Your password :***********"<<el;
		cout << "You Wanna See Your Password ?" << el;
		cout << "1: YES" << el;
		cout << "2: NO" << el;
		cin >> x;
		if (x == 1)output << user.password << el;
		cout << "======================================" << el;
		return output;
	}
};
int User::count = 0;
class Book                    //////////////////////class Book//////////////////
{
private:
	string title;
	string isbn;
	string category;
	int id; 
    double numRate;
	double sumRate;
	double averageRating;
	User auther;
public:
	static int count;
	Book()
	{
		title = "";
		isbn = "";
		category = "";
		averageRating = 0.0;
		numRate = 0.0;
		sumRate = 0.0;
		count++;
		id = count;
		User auther;
	}
	Book(string title, string isbn, string category)
	{
		this->title = title;
		this->isbn = isbn;
		this->category = category;
		averageRating = 0.0;
		numRate = 0.0;
		sumRate = 0.0;
		count++;
		id = count;
		User auther;
	}
	Book(const Book& booke)
	{
		title = booke.title;
		isbn = booke.isbn;
		category = booke.category;
		averageRating = booke.averageRating;
		auther = booke.auther;
		numRate = booke.numRate;
		sumRate = booke.sumRate;
		id = booke.id;
	}
	void set_title(string title)
	{
		this->title = title;
	}
	string get_title()const
	{
		return title;
	}
	void set_isbn(string isbn)
	{
		this->isbn=isbn;
	}
	string get_isbn()const
	{
		return isbn;
	}
	void set_category(string category)
	{
		this->category = category;
	}
	string get_category()const
	{
		return category;
	}
	void set_averageRating(double averageRatin)
	{
		this->averageRating = averageRatin;
	}
	double get_averageRating()const
	{
		return averageRating;
	}
	void set_id(int id)
	{
		this->id = id;
	}
	int get_id()
	{
		return id;
	}
	void set_auther(const User&user)
	{
		auther = user;
	}
	User get_auther()const
	{
		return auther;
	}
	void rateBooke(double rating)
	{
		numRate++;
		sumRate += rating;
		averageRating = sumRate / numRate;	
	}
	bool operator==(const Book& booke)
	{
		return(title == booke.title && isbn == booke.isbn && category == booke.category && auther == booke.auther && averageRating == booke.averageRating);
	}
	friend istream& operator>>(istream&input, Book&booke)
	{
		cout << "Title :";
		input >> booke.title;
		cout << "Isbn :";
		input >> booke.isbn;
		cout << "Category :";
		input >> booke.category;

		return input;
	}
	friend ostream& operator<<(ostream&output, Book&booke)
	{
		cout << "========================================" << el;
		cout << "Title :";
		output << booke.title << el;
		cout << "Isbn :";
		output << booke.isbn << el;
		cout << "Category :";
		output << booke.category << el;
		cout << "averageRating :";
		output << booke.averageRating << el;
		cout<< "Id :";
		output << booke.id << el;
		if (booke.auther.get_name() != "")
		{
			cout << "Auther :";
			output << booke.auther << el;
		}
		return output;
		cout << "========================================" << el;
	}
};
	int Book::count = 0;
class UserList                     /////////////////////UserList/////////////////
{
private:
	User *arrUsers; //pointer to object
	//vector<User*>arrUsers;
	int capacity;
	int userCount;
public:
	UserList()
	{
		capacity = 0;
		userCount = 0;
	}
	UserList(int capacity)
	{
		this->capacity = capacity;
		arrUsers= new User[capacity]; //call empty constuctor of User number of time cabacity
		userCount=0;
	}
	void addUser(const User& user)
	{
		try
		{
			if (userCount >= capacity)throw exception();
			arrUsers[userCount] = user;
			arrUsers[userCount].set_id(userCount+1);
			userCount++;
		}
		catch (exception)
		{
			cout << "The library cannot carry more than :"<<capacity<<" users" << el;
		}
	}
	User* searchUser(string name)
	{
		for (int i = 0; i < userCount; i++)   
		{
			if (arrUsers[i].get_name() == name)return&arrUsers[i]; //(&)return pointer so should come address
		}
		return nullptr;
	}
	User* searchUser(int id)
	{
		for (int i = 0; i < userCount; i++)
		{
			if (arrUsers[i].get_id() == id)return&arrUsers[i]; 
		}
		return nullptr;
		
	}
	void deleteUser(int id)
	{
		for (int i = 0; i < userCount; i++)
		{
			if (arrUsers[i].get_id() == id)
			{
				while (i<userCount-1)
				{
					arrUsers[i] = arrUsers[i + 1];
					arrUsers[i].set_id(i+1);
					i++;
				}
				userCount--;
				capacity--;
				break;
			}
		}
	}
	friend ostream& operator<<(ostream& output, UserList& userListe)
	{
		for (int i = 0; i < userListe.userCount; i++)
		{
			output << userListe.arrUsers[i] << " ";
		}
		return output;
	}
	~UserList() //distructor
	{
		delete []arrUsers;
	}
};
class BookList           ////////////////////class BookList/////////////////////
{
private:
	Book* arrbooks;
	int capacity;
	int booksCount;
public:
	BookList()
	{
		capacity = 0;
		booksCount = 0;
	}
	BookList(int capacity)
	{
		this->capacity = capacity;
		arrbooks = new Book[capacity];
		booksCount=0;
	}
	void addBook(const Book& book)
	{
		try
		{
			if (booksCount >= capacity)throw exception();
			arrbooks[booksCount] = book;
			arrbooks[booksCount].set_id(booksCount+1);
			booksCount++;	
		}
		catch(exception)
		{
			cout << "The library cannot carry more than :"<<capacity<<" books" << el;
		}
	}
	Book*searchBook(string name)
	{
		for (int i = 0; i < booksCount; i++)
		{
			if (arrbooks[i].get_title() == name)return&arrbooks[i];
		}
		return nullptr;
	}
    Book*searchBook(int id)
	{
		for (int i = 0; i < booksCount; i++)
		{
			if (arrbooks[i].get_id()==id)return&arrbooks[i];
		}
		return nullptr;
	}
	void deleteBook(int id)
	{
		for (int i = 0; i < booksCount; i++)
		{
			if (arrbooks[i].get_id() == id)
			{
				while (i<booksCount-1)
				{
					arrbooks[i] = arrbooks[i + 1];
					arrbooks[i].set_id(i + 1);
					i++;
				}
				capacity--;
				booksCount--;
				break;
			}
		}
	}
	Book getMaxRateBook()
	{
		double maxRate = -0.1;
		int idx=0;
		for (int i = 0; i < booksCount; i++)
		{
			if (arrbooks[i].get_averageRating() > maxRate)
			{
				maxRate = arrbooks[i].get_averageRating();
				idx = i;
			}
		}
		return arrbooks[idx];
	}
	void getBooksByTheSameAuthor(const User& user)
	{
		bool ok = true;
		for (int i = 0; i < booksCount; i++)
		{
			if (arrbooks[i].get_auther() == user)//operator overloading;
			{
				cout << arrbooks[i]<<" ";
				ok = false;
			}
		}
		if (ok)cout << "This auther don't have any books" << el;
	}
	Book&operator[](int pos)
	{
		int RRRR = -1;
		while (RRRR)
		{
			try
			{
				if (pos<0 || pos>booksCount)throw exception();
				RRRR = 0;
				return arrbooks[pos];
			}
			catch (exception)
			{
				cout << "Position not founded" << el;
			}

		}
	}
	friend ostream& operator<<(ostream& output, BookList& bookList)
	{
		for (int i = 0; i < bookList.booksCount; i++)
		{
			output << bookList.arrbooks[i] << " ";
		}
		return output;
	}
	~BookList()
	{
		delete[]arrbooks;
	}

};
void mainMinue()
{
	cout << "select one of the following choices :"<<el;
	cout << "1: Books Minue" << el;
	cout << "2: User Minue" << el;
	cout << "3: Exit" << el;
}
void bookMinue()
{
	cout << "        *BOOKS MINUE*" << el;
	cout << "What do you want?" << el;
	cout << "1: Creat a book ans add it to the list" << el;
	cout << "2: Search for a book" << el;
	cout << "3: Delete book by id" << el;
	cout << "4: Display all books" << el;
	cout << "5: Get the book with highest rating" << el;
	cout << "6: Get all books of a user" << el;
	cout << "7: Back to the main minue" << el;
}
User ub;
BookList* BP;
Book b;
int numBooks,cntb=1,rb;
void creatBook()
{
	cout << "How many books will be add" << el;
	cin >> numBooks;
	BP = new BookList(numBooks);     //to use pointer
	while (numBooks--)
	{
		cout << "Enter book " << cntb << " information" << el;
		cin >> b;
		cout << "If you wanna add auther to the book enter (yes)or(no)if you don't" << el;
		string sa;
		cin >> sa;
		if (sa == "yes")
		{
			cout << "information about auther" << el;
			cin >> ub;
			b.set_auther(ub);
		}
		cout << "Rate of the book form 1 to 5:";
		int RRRRR = -1;
		while (RRRRR == -1)
		{
			try
			{
				cin >> rb;
				if (rb < 1 || rb>5)throw exception();
				RRRRR = 0; 
				b.rateBooke(rb);
				BP->addBook(b);
				cntb++;
			}
			catch (exception e)
			{
				cout << e.what();
			}
		}
		
	}
}
int sb,bid;
void searchBook()
{
	cout << "select one of the following choices :" << el;
	cout << "1: search by title" << el;
	cout << "2: search by id" << el;
	string ssb;
	cin >> sb;
	Book *bb;
	if (sb == 1)
	{
		cout << "Enter book's title" << el;
		cin >> ssb;
		bb = BP->searchBook(ssb); //return object to pointer so (*bb)
		if (bb == nullptr)cout << "Book not founded" << el;
		else cout << *bb;
		
	}
	else if (sb == 2)
	{
		cout << "Enter book's id" << el;
		cin >> bid;
		bb = BP->searchBook(bid);
		if (bb == nullptr)cout << "Book not founded" << el;
		else cout << *bb;
		
	}
}
void deleteBook()
{
	cout << "Enter book's id" << el;
	cin >> bid;
	if (BP->searchBook(bid) != nullptr)
	{
		BP->deleteBook(bid);
		cout << "The book deleted" << el;
	}
	else cout << "Book not founded" << el;
}
void displayBook()
{
	if (BP->searchBook(1) != nullptr)cout << *BP;
	else cout << "The library is empty" << el;
}
void bookHighestRating()
{
	 b=BP->getMaxRateBook();
	 cout << b;
}
void getAllBookOfAuther()
{
	string sa;
	cout << "Enter the name of auther" << el;
	cin.ignore();
	getline(cin, sa);
	ub.set_name(sa);
	BP->getBooksByTheSameAuthor(ub);
}
void userMinue()
{
	cout << "      *USERS MENU*" << el;
	cout << "What do you want?" << el;
	cout << "1- Create a user and add it to the list " << el;
	cout << "2- Search for a user " << el;
	cout << "3- Delete user by id " << el;
	cout << "4- Display all users " << el;
	cout << "5- Back to the main minue" << el;
}
UserList *UP;
int numUser,cntu=1;
void creatUser()
{
	cout << "How many user will be added :";                
	cin >> numUser;
	UP = new UserList(numUser);
	UserList U(numUser);
	User uu;
	while (numUser--)
	{
		cout << "Enter user "<<cntu<<" information :";
		cin >> uu;
		UP->addUser(uu);
		cntu++;
	}
	

}
void searchUser()
{
	cout << "select one of the following choices :" << el;
	cout << "1: search by name" << el;
	cout << "2: search by id" << el;
	int su;
	cin >> su;
	int i;
	string ss;
	User *uuu;
	if (su == 1)
	{
		
		cout << "Enter user's name" << el;
		cin.ignore();
		getline(cin, ss);
		uuu=UP->searchUser(ss);
		if (uuu == nullptr)cout << "Name not founded" << el;
		else cout << *uuu;
	}
	else if (su == 2)
	{
		cout << "Enter user's id" << el;
		cin >> i;
		uuu=UP->searchUser(i);
		if (uuu == nullptr)cout << "id not founded" << el;
		else cout << *uuu;
      
	}
}
void deleteUser()
{
	int did;
	cout << "Enter user's id" << el;
	cin >> did;
	UP->deleteUser(did);
}
void displayAllUsers()
{
	cout << *UP;
}
int main() {         /////////////////////main////////////////////////////

	mainMinue();
	while (true)
	{
		int n;
		cin >> n;
		if (n == 1)
		{
			while (true)
			{
				bookMinue();
				cin >> n;
				if (n == 1)creatBook();
				else if (n == 2)searchBook();
				else if (n == 3)deleteBook();
				else if (n == 4)displayBook();
				else if (n == 5)bookHighestRating();
				else if (n == 6)getAllBookOfAuther();
				else if (n == 7)
				{
					mainMinue();
					break;
				}
			}
		}
		else if (n == 2)
		{
			while (true)
			{
				userMinue();
				cin >> n;
				if (n == 1)creatUser();
				else if (n == 2)searchUser();
				else if (n == 3)deleteUser();
				else if (n == 4)displayAllUsers();
				else if (n == 5)
				{
					mainMinue();
					break;
				}
			}
		}
		else if (n == 3)return 0;
	}
	return 0;
}
                                //الحمد لله