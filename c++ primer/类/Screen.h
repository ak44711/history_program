class Screen {
public:
	using pos = std::string::size_type;
	Screen() = default;	//因为Screen有另一个构造函数
						//所以本函数是必须的 
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
	char get() const 
		{ return contents[cursor]; }
	inline char get (pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	
	void some_member() const;
	
	Screen &set(char);
	Screen &set(pos, pos, char);
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	
	mutable size_t access_ctr;
}; 
