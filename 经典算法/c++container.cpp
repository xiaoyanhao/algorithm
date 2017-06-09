#include <iostream>
#include <cstring> 
#include <string>
#include <vector>
#include <complex>
#include <map>
#include <utility> 
#include <list>
#include <algorithm>
#include <deque>
#include <stack>

using namespace std;

int main() {
	pair<string, int> aut("Max", 1);
	complex<double> purei(1, 7); // 虚数 1 + 7i 
	
	
	vector<int> v(n, elem);  //初始化 v 为 n 个 elem 。 
    v.assign(n, elem);	 //将 n 个 elem 的拷贝赋值给 v 。
	v.at(pos);			 //传回pos位置上的数据。也可以用v[pos]。 
	v.front();			 //传回第一个数据。 
	v.back();            //传回最后一个数据，不检查这个数据是否存在。
	v.rbegin();			 //传回一个逆向队列的第一个数据。
	v.rend();			 //传回一个逆向队列的最后一个数据的下一个位置。
	v.begin();			 //传回迭代器中的第一个数据地址。
	v.end();			 //指向迭代器中末端元素的下一个，指向一个不存在元素。
	v.size(); 			 //返回容器中实际数据的个数。
	v.resize(num);		 //重新指定队列的长度。
	v.capacity();		 //返回容器中数据个数。
	v.reserve();		 //保留适当的容量。
	v.empty();			 //判断容器是否为空。空返回true，否则返回false。
	v.clear();			 //移除容器中所有数据。
	v.erase(pos);		 //删除pos位置的数据，传回下一个数据的位置。
	v.erase(beg, end);	 //删除[beg,end）区间的数据，传回下一个数据的位置。
	v.max_size();		 //返回容器中最大数据的数量。
	v.push_back(elem);	 //在尾部加入一个数据。
	v.pop_back();		 //删除最后一个数据。
	v.insert(pos, elem); //在pos位置前插入一个elem拷贝，传回新数据位置。
	v.insert(pos, n, elem); //在pos位置前插入n个elem数据，无返回值。
	v.insert(pos, beg, end); //在pos位置前插入在[beg,end）区间的数据。无返回值。 
	swap(v1, v2);		 //将v1和v2元素互换。 
	
	vector<int>::iterator vv;
	for (vv = v.begin(); vv != v.end(); vv++) {
		cout << *vv << endl;
	} 
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] / v.at(i) << endl;
	}
	
	
	
	getline(cin, st);               //读入一行字符串包括空格，直到换行 
	string st = "The expense of spirit\n", st1("shark"); //直接初始化 
	string st2(st);					//用st字符串初始化st2
	string st3(n, 'c');  			//用n个字符c初始化
	string st4(st, pos, n);			//把字符串st中从pos开始的n个字符赋给st4
	st.at(pos), st[pos];			//传回pos位置上的字符
	char *c = st.c_str();			//返回一个以null终止的c字符串
	char *c = st.data(c);			//返回一个非null终止的c字符数组
	st.capacity();					//返回当前容量（即string中不必增加内存即可存放的元素个数）
	st.max_size();					//返回string对象中可存放的最大字符串的长度
	st.size();						//返回当前字符串的大小
	st.length();					//返回当前字符串的长度
	st.empty();						//当前字符串是否为空
	st.resize(len, 'c');		    //把字符串当前大小置为len，并用字符c填充不足的部分
	st1 += st2, st1.append(s2);		//把字符串st2连接到st1的结尾 
	st1.append(st2, pos, n);		//把字符串st2中从pos开始的n个字符连接到st1的结尾
	st1.append(n, 'c');				//在当前字符串结尾添加n个字符c
	st1.append(st2.begin() + 5, st2.end());  //把迭代器st2.begin() + 5和st2.end()之间的部分连接到当前字符串的结尾
	st1 == st2 ?					//比较两个字符串是否相等
	st1.compare(st2);				//比较当前字符串和st2的大小
	st.substr(pos, n);				//返回pos开始的n个字符组成的字符串
	st1.swap(st2);					//交换st1与st2
	st.find('c', pos);				//从pos开始查找字符c在当前字符串的位置
	st.find(char *c, pos, n); 		//从pos开始查找字符串c中前n个字符在当前串中的位置
	st.find(st2, pos);				//从pos开始查找字符串s在当前串中的位置
	//查找成功时返回所在位置，失败返回  string::npos 的值; find 改成 rfind 表示从pos开始从后往前查找
	st.find_first_of('c', pos);		//从pos开始查找字符c第一次出现的位置
	st.find_first_of(char *c, pos, n);  //从pos开始查找字符串c中前n个字符在当前串中第一次出现的位置
	st.find_first_of(st2, pos);		 //从pos开始查找字符串s在当前串中第一次出现的位置
	//把 find_first_of 改成 find_first_not_of 表示从当前串中查找第一个不在串s中的字符出现的位置 
	//find_last_of 和 find_last_not_of 与前面两个相似，只不过是从后往前查找
	st.replace(p0, n0, char *c);	//删除从p0开始的n0个字符，然后在p0处插入串c
	st.replace(p0, n0, st2);		//删除从p0开始的n0个字符，然后在p0处插入串st2
	st.replace(p0, n0, n, 'c');		//删除p0开始的n0个字符，然后在p0处插入n个字符c
	st.replace(st.begin() + 2, st.end() - 1, st2); //把 [st.begin() + 2, st.end - 1) 之间的部分替换成st2 
	st.replace(st.begin() + 2, st.end() - 1, n, 'c'); //把 [st.begin() + 2, st.end - 1) 之间的部分替换成n个c
	st.replace(st.begin() + 2, st.begin() + 4, st.end() - 4, st.end() - 2) ; // 把[st.begin() + 2, st.begin() + 4) 之间的部分替换成 [st.end() - 4, st.end() - 2)之间的部分
	st.insert(p0, st2, pos, n);		//前4个函数在p0位置插入字符串s中pos开始的前n个字符 
	st.insert(p0, n, 'c');			//此函数在p0处插入n个字符c
	st.erase(pos, n);				//删除pos开始的n个字符，返回修改后的字符串
	st.erase(st.begin(), st.end()); //删除[st.begin()，st.end()）之间的所有字符，返回删除后迭代器的位置
	st.erase(iterator it);			//删除it指向的字符，返回删除后迭代器的位置
	int y = 31520; st = to_string(y); // 只能在类里面实现， 将其他数据类型转换为string	
	
	list<string> s;
	s.push_back(elem);
	s.push_front(elem);
	s.pop_back();
	s.pop_front();
	s.empty();
	s.count(s.begin(), s.end(), elem);  //返回s中elem的个数 
	lsit<string>::iterator ss = find(s.begin(), s.end(), "app"); 
	lsit<string>::iterator ss = search(s.begin(), s.end(), s2.begin(), s2.end()); //如果被发现，search就会返回一个指着序列匹配的第一个字符的iterator。如果没有找到匹配项，search返回s.end()的值。
	s.sort(); 	//排序
	s.insert(s.begin(), elem);
	s.erase(s.begin(), s.end());
	s.remove(char *c);
	 
	list<string>::iterator ss;
	for (ss = s.begin(); ss != s.end(); ss++) {
		cout << *ss << endl;  // list不支持随机存取，不能用s.begin()+2来指向list中的第三个对象 
	}
	
	void PrintIt(string & s) {
		cout << s << endl;
	}
	for_each(s.begin(), s.end(), PrintIt);
	
	
	map<int, string> m; //其中第一个可以称为关键字，每个关键字只能在map中出现一次，第二个可能称为该关键字的值
	m.size();           //map内部所有的数据都是有序的
	m.empty();
	m.clear();
	m.insert(pair<int, stirng>(1, "student_one"));
	m.insert(map<int, string>::value_type(1, "student_one"));
	m[1] = "student_one"; //可以覆盖以前该关键字对应的值
	m.find(1) 			  //找的是关键字，返回数据所在位置的迭代器
	map<int,string>::iterator iter = m.find(1);
	m.erase(iter);
	m.erase(m.begin(), m.end());	//成片删除要注意的是，也是STL的特性，删除区间是一个前闭后开的集合 
	for (iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}
	//如果关键字是一个结构体，涉及到排序就会出现问题，因为它没有小于号操作，insert等函数在编译的时候过不去，下面给出两个方法解决这个问题
	typedef struct tag{
		int id;
		string name;
		bool operator < (tag const &a)const {
			if (id < a.id)
			    return true;
			if (id == a.id)
			    return name.compare(a.name) < 0;
			return false;
		}
	}; 
	
	
	
	
	
	int i = -1;
	const int ic = i;
	const int *pic = &ic;
	const int *const cpic = &ic;
	int *const cpi = &i;
	
	vector<string> svec;
	list<string> slist, slist2;
	string ss("Shark");
	svec.insert(svec.begin(), ss);
	slist.insert(slist.end(), 10, ss);
	string cc("Max");
	list<string>::iterator iter;
	iter = find(slist.begin(), slist.end(), cc);
	slist.insert(iter, cc);
	string sarray[4] = {"quasi", "simba", "frollo", "scar"};
	svec.insert(svec.begin() + svec.size() / 2, sarray + 2, sarray + 4);
	iter = find(slist.begin(), slist.end(), "stringVal");
	slist.insert(iter, svec.begin(), svec.end());
	slist.erase(iter); 
	slist.erase(slist.begin(), slist.end());
	slist.swap(slist2);
	
	return 0;
}
