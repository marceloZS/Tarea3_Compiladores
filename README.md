# Tarea3_Compiladores
Tarea de Programación 3 Análisis Sintáctico, Semántico e Interpretes


El folder imp tiene la implementación del parser, printer, intérprete y typechecker del lenguaje IMP
definido por la siguiente sintaxis:
Program ::= Body
Body ::= VarDecList StatementList
VarDecList ::= (VarDec)*
VarDec ::= “var” Type VarList “;”
Type ::= id
VarList :: id (“,” id)*
StatementList ::= Stm (“;” Stm)* ...
Stm ::= id “=” Exp |
“print” “(“ Exp “)” |
“if” Exp “then” Body [“else” Body] “endif” |
“while” Exp “do” Body “endwhile”
Exp ::= CExp
CExp ::= AExp ((‘<’|’<=’|’==’) AExp)?
AExp ::= Term (( ́+ ́ |  ́- ́) Term)*
Term ::= Factor (( ́* ́| ́/ ́) Factor)*
FExp ::= Factor (“**” FExp”)?
Factor ::= num |  ́( ́ Exp  ́) ́ | id |
“ifexp”  ́( ́ Exp  ́, ́ Exp  ́, ́ Exp  ́) ́
Queremos agregar los siguientes elementos a la gramática:
• Las constantes booleanas true y false. (2 puntos)
• Los operadores and y or. Estos operadores tendrán menor precedencia que el resto de los
operadores y, además, asociarán a la derecha. (4 puntos)
• La sentencia for-do. (4 puntos)
La sentencia for-do permitirá efectuar un numero de iteraciones, con valores asignados a una
variable sobre un rango, determinado por dos expresiones. Por ejemplo, la sentencia
for x : 5, 10 do Body endfor
ejecutará Body para valores de x en 5,6,...,10. Del mismo modo,
for x : 10, 5 do Body endfor
ejecutará Body para valores de x en 10,9,...,5. Notar que los valores que determinan el rango de la
iteración pueden ser expresiones enteras de cualquier tipo e.g.
for x : y, y+10 do Body endfor
