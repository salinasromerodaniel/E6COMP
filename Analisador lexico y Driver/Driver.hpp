#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include "Sym.hpp"
#include "TypeTab.hpp"
#include "SymTab.hpp"
#include "Quad.hpp"

struct Expresion{
    std::string dir;
    int tipo;
};

struct Numero{
    std::string val;
    int tipo;
};
class Driver
{
private:
    TypeTab tablaTipos;
    std::vector<Quad> codigo_intermedio;
    std::vector<SymTab> tablaSimbolos;//Pila de tablas de símbolos
    std::stack<std::string> pilaEtiques;
    std::stack<int> pilaDirecciones;
    std::stack<int> pilaTemporales;
    std::map<std::string, std::string> tablaCadenas;
    std::map<std::string, Numero> tablaConstantes;
    int tipoRetorno;
    bool tieneRetorno;
    int dir;
    int numEtiquetas;
    int numTemporales;
    int constanteFloat;
    //Generador de codigo final

public:
    Driver();
    ~Driver();
    // Funciones para tabla de tipos
    //int agregar_tipo(string nombre, int tam_bytes, SymTab *tipo_base);
    //
    //void agregar_simbolo(std::string id, int tipo, std::string categoria);
    //void agregar_simbolo(std::string id, int tipo, std::vector<int> args);

    string nuevaEtiqueta();
    string nuevaEtiqueta(int lab);
    string nuevaTemporal();
    

    void asignacion(std::string id, Expresion e);
    Expresion disyuncion(Expresion e1, Expresion e2);
    Expresion conjuncion(Expresion e1, Expresion e2);
    Expresion igualdad(Expresion e1, Expresion e2);
    Expresion distinto(Expresion e1, Expresion e2);
    Expresion mayor_que(Expresion e1, Expresion e2);
    Expresion menor_que(Expresion e1, Expresion e2);
    Expresion mayor_o_igual(Expresion e1, Expresion e2);
    Expresion menor_o_igual(Expresion e1, Expresion e2);
    Expresion suma(Expresion e1, Expresion e2);
    Expresion resta(Expresion e1, Expresion e2);
    Expresion multiplicacion(Expresion e1, Expresion e2);    
    Expresion division(Expresion e1, Expresion e2);    
    Expresion negacion(Expresion e1);
    Expresion identificador(std::string id);
    Expresion numero(std::string val, int tipo);

    std::string ampliar(std::string dir, int t1, int t2);
    std::string reducir(std::string dir, int t1, int t2);
    int maximo(int t1, int t2);
    int minimo(int t1, int t2);
    bool compatibles(int t1, int t2);

    void error_semantico(std::string mensaje);
    void gen_imprimir(string val);
    void gen_lectura(string dir);
    void gen_label(string label);
    void gen_goto(string label);
    void gen_if(string var, string ltrue);
};


#endif // !__DRIVER_HPP__
