#include <sstream>
#include <iostream>
#include <iostream>

#include "imp.hh"
#include "imp_parser.hh"
#include "imp_printer.hh"
#include "imp_interpreter.hh"
#include "imp_typechecker.hh"


int main(int argc, const char* argv[]) {

  Program *program; 
   
  if (argc != 2) {
    cout << "Incorrect number of arguments" << endl;
    exit(1);
  }

  std::ifstream t(argv[1]);
  std::stringstream buffer;
  buffer << t.rdbuf();
  Scanner scanner(buffer.str());
  
  Parser parser(&scanner);
  program = parser.parse();  // el parser construye la aexp
  
  ImpPrinter printer;
  ImpInterpreter interpreter;
  ImpTypeChecker checker;

  /*
  int resultTrue = interpreter.interpret("print true;");
  if (resultTrue != 1) {
    std::cerr << "Error: expected 1, but got " << resultTrue << " for 'print true;'" << std::endl;
  }

  int resultFalse = interpreter.interpret("print false;");
  if (resultFalse != 0) {
    std::cerr << "Error: expected 0, but got " << resultFalse << " for 'print false;'" << std::endl;
  }
  */
  

  
  printer.print(program);
  
  cout << endl << "Type checking:" << endl;
  checker.typecheck(program);
  
  cout << endl << "Run program:" << endl;
  interpreter.interpret(program);


  delete program;

}
