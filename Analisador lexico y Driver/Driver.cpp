#include "Driver.hpp"
#include <sstream>
#include <string>

Expresion Driver::disyuncion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        gen_code(e1.dir,e2.dir,"||",e.dir)
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::conjuncion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        gen_code(e1.dir,e2.dir,"&&",e.dir)
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::igualdad(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        gen_code(e1.dir,e2.dir,"==",e.dir)
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::distinto(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        gen_code(e1.dir,e2.dir,"!=",e.dir)
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::mayor_que(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        gen_code(e1.dir,e2.dir,">",e.dir)
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::menor_que(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        gen_code(e1.dir,e2.dir,"<",e.dir)
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::mayor_o_igual(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        gen_code(e1.dir,e2.dir,">=",e.dir)
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::menor_o_igual_que(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        gen_code(e1.dir,e2.dir,"<=",e.dir)
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::suma(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = maximo(e1.tipo,e2.tipo); // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(e.tipo!=-1){
        std::string alfa1 = ampliar(e1.dir,e1.tipo,e.tipo);
        std::string alfa2 = ampliar(e2.dir,e2.tipo,e.tipo);
        gen_code(e.dir,alfa1,"+",alfa2);
    else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::resta(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = maximo(e1.tipo,e2.tipo); // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(e.tipo!=-1){
        std::string alfa1 = ampliar(e1.dir,e1.tipo,e.tipo);
        std::string alfa2 = ampliar(e2.dir,e2.tipo,e.tipo);
        gen_code(e.dir,alfa1,"-",alfa2);
    else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::multiplicacion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = maximo(e1.tipo,e2.tipo); // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(e.tipo!=-1){
        std::string alfa1 = ampliar(e1.dir,e1.tipo,e.tipo);
        std::string alfa2 = ampliar(e2.dir,e2.tipo,e.tipo);
        gen_code(e.dir,alfa1,"*",alfa2);
    else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::division(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = maximo(e1.tipo,e2.tipo); // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(e.tipo!=-1){
        std::string alfa1 = ampliar(e1.dir,e1.tipo,e.tipo);
        std::string alfa2 = ampliar(e2.dir,e2.tipo,e.tipo);
        gen_code(e.dir,alfa1,"/",alfa2);
    else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::negacion(Expresion e1){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    genCode(e.dir, "", "!", e1.dir);
}

bool Driver::compatibles(int t1, int t2){
    std::string nombre = tt.getNombre(t1);
    std::string nombre2 = tt.getNombre(t2);
    if(nombre =="struct" && nombre2=="struct"){
        //Validar la equivalencia de los campos de los tipos
        //estructurados
    }
    if(t1==t2) return true;
    if(t1 ==1 || t2 == 2) return true;
    if(t1 ==2 || t2 == 3) return true;
    if(t1 ==3 || t2 == 4) return true;
    return false;
    
}

string Driver::ampliar(std::string dir, int t1, int t2)
{
    std::string temp;
    if(t1==t2) return dir;
    else if((t1==1 && t2==2)){
        temp = nuevaTemporal();
        gen_code(dir,"","(int)",temp);
        //???
        return temp;
    }else if(t1==2 && t2==3){
        temp = nuevaTemporal();
        gen_code(dir,"","(float)",temp);
        //??
    }else if(t1==3 && t2==4){
        temp = nuevaTemporal();
        gen_code(dir,"","(double)",temp);
        //??
    } else return "";
}

std::string Driver::reducir(std::string dir, int t1, int t2)
{
    string temp;
    if(t1==t2) return dir;
    else if((t1==2 && t2==1)){
        temp = nuevaTemporal();
        gen_code(dir,"","(char)",temp);
        //??
        return temp;
    }else if(t1==3 && t2==2){
        temp = nuevaTemporal();
        gen_code(dir,"","(int)",temp);
        //??
    }else if(t1==4 && t2==3){
        temp = nuevaTemporal();
        gen_code(dir,"","(float)",temp);
        //??
    } else return "";
}

int Driver::maximo(int t1, int t2)
{
    if(t1==t2) return t1;
    else if(t1==1 && t2==2) return 2;
    else if(t1==2 && t2==1) return 2;
    else if(t1==2 && t2==3) return 3;
    else if(t1==3 && t2==2) return 3;
    else if(t1==3 && t2==4) return 4;
    else if(t1==4 && t2==3) return 4;
    else return -1;
}

int Driver::minimo(int t1, int t2)
{
    if(t1==t2) return t1;
    else if(t1==1 && t2==2) return 1;
    else if(t1==2 && t2==1) return 1;
    else if(t1==2 && t2==3) return 2;
    else if(t1==3 && t2==2) return 2;
    else if(t1==3 && t2==4) return 3;
    else if(t1==4 && t2==3) return 3;
    else return -1;
}

Expresion Driver::identificador(std::string id){
    Expresion e;
    if(tablaSimbolos.is_in(id)){ //Se válida que exista el id
        e.dir = id;
        e.tipo = tablaSimbolos.getType(id); // Se obtiene el tipo del id
    }else{
        error_semantico("El identificador "+ id + " no fue declarado");
    }
    return e;  
}


Expresion Expresion::numero(std::string val, int tipo){
    if( tipo == 2){
        stringstream cte;
        cte<<"cteFloat"<<cteFloat++;
        Numero num;
        num.val = val;
        num.tipo = tipo;
        contantes[cte.str()] = num;
    }
}

void error_semantico(std::string mensaje){
    cout<<"Error semántico "<<mensaje<<endl;
    exit(EXIT_FAILURE);
}

void Driver::asignacion(std::string id, Expresion e)
{
    Expresion e1;
    string alfa;
    //Validar que el id fue declarado
    if(!tablaSimbolos.is_in(id)) error_semantico("La variable "+id+" no fue declarada");
    int typeId = tablaSimbolos.getType(id);
    e1.tipo = typeId; //La expresión de salida siempre tendrá el tipo del id
    if(typeId == e.tipo){
        alfa = e.dir;
    }
    else if(typeId>e.tipo)
    {
        alfa = ampliar(e.dir, e.tipo, e1.tipo);
    }
    else if(minimo(typeId, e.tipo)!=1)
    {    
        alfa = reducir(e.dir, e.tipo, e1.tipo);        
    }
    else
    {
        error_semantico("Los tipos son incompatibles");
    }
    genCode(id, alfa, "=", "");
    e.dir = id;        
}

void Driver::gen_if(std::string var, string label)
{
    codigo_intermedio.push_back(Cuadrupla( var,"goto","if",label));    
}

void Driver::genCode(std::string arg1,std::string arg2,std::string op,std::string res)
{
    codigo_intermedio.push_back(Cuadrupla(arg1, arg2, op, res));
}

void Driver::gen_goto(std::string label)
{
    codigo_intermedio.push_back(Cuadrupla("","","goto",label ));
}

void Driver::gen_label(std::string label)
{
    codigo_intermedio.push_back(Cuadrupla("","","label",label ));
}

string Driver::nuevaTemporal()
{
    std::stringstream temp;
    temp<<"t"<<numTemporales++;
    return temp.str();
}

string Driver::nuevaEtiqueta(int lab)
{
    std::stringstream label;
    label<< "L"<<lab;
    return label.str();
}

string Driver::nuevaEtiqueta()
{
    std::stringstream label;
    label<< "L"<<numEtiquetas++;
    return label.str();
}