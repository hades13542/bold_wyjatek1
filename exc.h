
#include <cstdio>
#include <iostream>
#include <stdexcept>

namespace exc{


	class bexc
	{
	public:
		bexc(std::string tekst, int line):_name(tekst),_line(line){}
		inline std::string message() const{return _name;}
		inline int codeline() const{return _line;}
	private:
		std::string _name;
		int _line;
	};

	void handler(std::string tekst,int line){
	try{
		throw;
	}
	catch(std::runtime_error& a){
		std::cout<<"... wyjatek podstawowy:"<<a.what()<<"\n";
		throw bexc(tekst,line);
	}
	catch(bexc& a){
		std::cout<<"... wyjatek bexc:"<<a.message()<<" "<<a.codeline()<<"\n";
		throw bexc(tekst,line);
		}
	}
};