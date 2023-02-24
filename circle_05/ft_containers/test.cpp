#if 1 // CREATE A REAL STL EXAMPLE
#include "test_std_stl.hpp"
#else
#include "test_ft_stl.hpp"
#endif

int main(void){
	Tester t(NS);

	t.putTestName("VECTOR");
	t.putMethodName("push_back");
	{
		_vector_int v1;
		for (int i = 0; i < VEC_SIZE; i++)
			v1.push_back(i);
	}
	t.timer();
	{
		_vector_int v1(VEC_SIZE, 0);
		t.putMethodName("pop_back");
		for (int i = 0; i < VEC_SIZE; i++)
			v1.pop_back();
		t.timer();
	}
	t.putMethodName("insert");
	{
		_vector_int v1;
		for (int i = 0; i < VEC_SIZE; i++)
			v1.insert(v1.begin(), i);
	}
	t.timer();
	t.putMethodName("erase");
	{
		_vector_int v1(VEC_SIZE, 0);
		for (int i = 0; i < VEC_SIZE; i++)
			v1.erase(v1.begin());
	}
	t.timer();
	t.putMethodName("swap");
	{
		_vector_int v1(VEC_SIZE, 0);
		_vector_int v2(VEC_SIZE, 0);
		for (int i = 0; i < VEC_SIZE; i++)
			v1.swap(v2);
	}
	t.timer();
	t.putMethodName("clear");
	{
		_vector_int v1(VEC_SIZE, 0);
		for (int i = 0; i < VEC_SIZE; i++)
			v1.clear();
	}
	t.timer();
	t.putMethodName("relational operators");
	{
		_vector_int v1(VEC_SIZE, 0);
		_vector_int v12(VEC_SIZE, 0);
		for (int i = 0; i < VEC_SIZE; i++)
			if (v1 != v12)
				t.exit();
	}
	t.timer();
	{
		_vector_int v1(VEC_SIZE, 0);
		t.putMethodName("iterator");
		{
			_vector_int::iterator it = v1.begin();
			_vector_int::iterator ite = v1.end();
			for (; it != ite; it++)
				*it = 0;
		}
		t.timer();
		t.putMethodName("reverse iterator");
		{
			_vector_int::reverse_iterator it = v1.rbegin();
			_vector_int::reverse_iterator ite = v1.rend();
			for (; it != ite; it++)
				*it = 0;
		}
		t.timer();
	}
	//t.putMethodName("capacity");
	//{}
	//t.timer();
	{
		_vector_int v1(VEC_SIZE, 0);
		t.putMethodName("element access");
		for (int i = 0; i < VEC_SIZE; i++)
			v1[i] = i;
		t.timer();
	}
	//t.putMethodName("modifiers");
	//{}
	//t.timer();

	t.putTestName("STACK");
	t.putMethodName("push");
	{
		_stack_int st1;
		for (int i = 0; i < STACK_SIZE; i++)
			st1.push(i);
		t.timer();
		t.putMethodName("top");
		{
			for (int i = 0; i < STACK_SIZE; i++)
				st1.top();
		}
		t.timer();
		t.putMethodName("pop");
		{
			for (int i = 0; i < STACK_SIZE; i++)
				st1.pop();
		}
		t.timer();
		t.putMethodName("empty");
		if (!st1.empty())
			t.exit();
		t.timer();
	}
	{
		_stack_int st1, st12;
		for (int i = 0; i < STACK_SIZE; i++){
			st1.push(i);
			st12.push(i);
		}
		t.putMethodName("relational operators");
		if (st1 != st12)
			t.exit();
		t.timer();
	}

	t.putTestName("MAP");
	t.putMethodName("insert");
	{
		_map_int mp1, mp2;
		for (int i = 0; i < MAP_SIZE; i++)
			mp1.insert(_pair(i, i));
		t.timer();
		t.putMethodName("find");
		for (int i = 0; i < MAP_SIZE; i++)
			mp1.find(i);
		t.timer();
		t.putMethodName("erase");
		for (int i = 0; i < MAP_SIZE; i++)
			mp1.erase(i);
		t.timer();
	}
	{
		_map_int mp1, mp12, mp13;
		for (int i = 0; i < MAP_SIZE; i++)
		{
			mp1.insert(_pair(i, i));
			mp12.insert(_pair(i, i));
			mp13.insert(_pair(i + 1, i + 1));
		}
		t.putMethodName("relational operators");
		if (mp1 != mp12)
			t.exit();
		if (mp1 > mp13)
			t.exit();
		t.timer();
	}
	{
		_map_int mp1;
		_map_int mp12;
		for (int i = 0; i < MAP_SIZE; i++)
		{
			mp1.insert(_pair(i, i));
			mp12.insert(_pair(i + 1, i + 1));
		}
		t.putMethodName("swap");
		mp1.swap(mp12);
		t.timer();
		t.putMethodName("clear");
		mp1.clear();
		t.timer();
	}

		t.putTestName("MAP");
	t.putMethodName("insert");
	{
		_map_int mp1, mp2;
		for (int i = 0; i < MAP_SIZE; i++)
			mp1.insert(_pair(i, i));
		t.timer();
		t.putMethodName("find");
		for (int i = 0; i < MAP_SIZE; i++)
			mp1.find(i);
		t.timer();
		t.putMethodName("erase");
		for (int i = 0; i < MAP_SIZE; i++)
			mp1.erase(i);
		t.timer();
	}
	{
		_map_int mp1, mp12, mp13;
		for (int i = 0; i < MAP_SIZE; i++)
		{
			mp1.insert(_pair(i, i));
			mp12.insert(_pair(i, i));
			mp13.insert(_pair(i + 1, i + 1));
		}
		t.putMethodName("relational operators");
		if (mp1 != mp12)
			t.exit();
		if (mp1 > mp13)
			t.exit();
		t.timer();
	}
	{
		_map_int mp1;
		_map_int mp12;
		for (int i = 0; i < MAP_SIZE; i++)
		{
			mp1.insert(_pair(i, i));
			mp12.insert(_pair(i + 1, i + 1));
		}
		t.putMethodName("swap");
		mp1.swap(mp12);
		t.timer();
		t.putMethodName("clear");
		mp1.clear();
		t.timer();
	}

	t.putTestName("SET");
	t.putMethodName("insert");
	{
		_set_int s1, s2;
		for (int i = 0; i < MAP_SIZE; i++)
			s1.insert(i);
		t.timer();
		t.putMethodName("find");
		for (int i = 0; i < MAP_SIZE; i++)
			s1.find(i);
		t.timer();
		t.putMethodName("erase");
		for (int i = 0; i < MAP_SIZE; i++)
			s1.erase(i);
		t.timer();
	}
	{
		_set_int s1, s12, s13;
		for (int i = 0; i < MAP_SIZE; i++)
		{
			s1.insert(i);
			s12.insert(i);
			s13.insert(i + 1);
		}
		t.putMethodName("relational operators");
		if (s1 != s12)
			t.exit();
		if (s1 > s13)
			t.exit();
		t.timer();
	}
	{
		_set_int s1;
		_set_int s12;
		for (int i = 0; i < MAP_SIZE; i++)
		{
			s1.insert(i);
			s12.insert(i + 1);
		}
		t.putMethodName("swap");
		s1.swap(s12);
		t.timer();
		t.putMethodName("clear");
		s1.clear();
		t.timer();
	}

	t.putTestName("LEAKS");
	std::cout << GRAY << std::endl;
	system("leaks benchmark");

	return (0);
}

