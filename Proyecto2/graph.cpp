#include "graph.h"
#include "stdlib.h"

int tanque = 50;

/**
 * @brief Este metodo se encarga de inicializar el graph
 */
void Graph::Start()
{
    a = NULL;
}

/**
 * @brief Revisa si el grafo esta vacio
 * @return Un booleano
 */
bool Graph::Empty()
{
    if(a == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Devuelve la cantidad de vertices del grafo
 * @return Int con numeros de vertices
 */
int Graph::Size()
{
    int cont = 0;
    Vertice *aux;
    aux = a;
    while(aux != NULL)
    {
        cont++;
        aux = aux->vertV;
    }
    return cont;
}
/**
 * @brief Devuelve el nombre del vertice
 * @param nombre devuelve el nombre del vertice
 * @return Null
 */
Vertice *Graph::GetVertice(string nombre)
{
    Vertice *aux;
    aux = a;
    while(aux  != NULL)
    {
        if(aux->nom == nombre)
        {
            return aux;
        }
        aux = aux->vertV;
    }
    return NULL;
}

/**
 * @brief Inserta los vertices en el grafo
 * @param nombre devuelve el nombre del vertice
 */
void Graph::InsVertice(string nombre)
{
    Vertice *nuevo = new Vertice;
    nuevo->nom = nombre;
    nuevo->vertV = NULL;
    nuevo->arisV = NULL;

    if(Empty())
    {
        a = nuevo;
    }
    else
    {
        Vertice *aux;
        aux = a;
        while(aux->vertV != NULL)
        {
            aux = aux->vertV;
        }
        aux->vertV = nuevo;
    }
}

/**
 * @brief Inserta las aristas en los vertices
 * @param comienzo una referencia al vertice del comienzo
 * @param final una referencia al vertice del final
 * @param num que corresponde al valor de la arista
 */
void Graph::InsArista(Vertice *comienzo, Vertice *final, int num)
{
    Arista *nuevo2 = new Arista;
    nuevo2->num = num;
    nuevo2->arisA = NULL;
    nuevo2->vertA = NULL;

    Arista *aux;

    aux = comienzo->arisV;

    if(aux == NULL)
    {
        comienzo->arisV = nuevo2;
        nuevo2->vertA = final;
    }
    else
    {
        while(aux->arisA != NULL)
        {
            aux = aux->arisA;
        }
        aux->arisA = nuevo2;
        nuevo2->vertA = final;
    }
}

/**
 * @brief Imprime la lista de adyacencia
 */
string Graph::listAdyacente()
{
    Vertice *VertAux;
    Arista *ArisAux;

    VertAux = a;
    while(VertAux != NULL)
    {
        lavel+=VertAux->nom+"->";
        //cout<<VertAux->nombre<<"->";
        ArisAux = VertAux->arisV;
        while(ArisAux != NULL)
        {
            lavel+= ArisAux->vertA->nom+":";
            string STR_Peso(std::to_string(ArisAux->num));
            lavel+=STR_Peso+"->";
            ArisAux = ArisAux->arisA;
        }
        VertAux = VertAux->vertV;
        lavel+="\n";

    }
    return lavel;
}

/**
 * @brief Destruye el grafo
 */
void Graph::Deny()
{
    Vertice *aux;

    while(a != NULL)
    {
        aux = a;
        a = a->vertV;
        delete(aux);
    }
}

/**
 * @brief Elimina las aritstas
 * @param comienzo una referencia al vertice del comienzo
 * @param final una referencia al vertice del final
 */
void Graph::EliminarArista(Vertice *comienzo, Vertice *final)
{
    int conteo = 0;
    Arista *actual, *anterior;
    actual = comienzo->arisV;

    if(actual == NULL)
    {
        cout<<"El vertice del comienzo no tiene ninguna aristas"<<endl;
    }
    else if(actual->vertA == final)
    {
        comienzo->arisV = actual->arisA;
        delete(actual);
    }
    else
    {
        while(actual != NULL)
        {
            if(actual->vertA == final)
            {
                conteo = 1;
                anterior->arisA = actual->arisA;
                delete(actual);
                break;
            }
            anterior = actual;
            actual = actual->arisA;
        }
        if(conteo == 0)
        {
            cout<<"Estos dos vertices no se encuentran conectados"<<endl;
        }
    }
}

/**
 * @brief Elimina un vertice
 * @param vert2 Vertice que se elimina
 */
void Graph::EliminarVertice(Vertice *vert2)
{
    Vertice *actual, *anterior;
    Arista *aux;

    actual = a;
    while(actual != NULL)
    {
        aux = actual->arisV;
        while(aux != NULL)
        {
            if(aux->vertA == vert2)
            {
                EliminarArista(actual, aux->vertA);
                break;
            }
            aux = aux->arisA;
        }
        actual = actual->vertV;
    }
    actual = a;
    if(a == vert2)
    {
        a = a->vertV;
        delete(actual);
    }
    else
    {
        while(actual != vert2)
        {
            anterior = actual;
            actual = actual->vertV;
        }
        anterior->vertV = actual->vertV;
        delete(actual);
    }
}

/**
 * @brief Encuentra las conexiones de los vertices
 * @param comienzo desde donde comienza a recorrer los vertices
 */
void Graph::ProfRecorrido(Vertice *comienzo)
{
    int conteo, conteo2;
    Vertice *actual;
    stack<Vertice*> pila;
    list<Vertice*> lista;
    list<Vertice*>::iterator i;

    pila.push(comienzo);

    while(!pila.empty())
    {
        conteo = 0;
        actual = pila.top();
        pila.pop();

        for(i=lista.begin(); i!=lista.end(); i++)
        {
            if(*i == actual)
            {
                conteo = 1;
            }
        }
        if(conteo == 0)
        {
            cout<<actual->nom<<", ";
            lista.push_back(actual);

            Arista *aux;
            aux = actual->arisV;

            while(aux != NULL)
            {
                conteo2 = 0;
                for(i=lista.begin(); i!=lista.end(); i++)
                {
                    if(*i == aux->vertA)
                    {
                        conteo2 = 1;
                    }
                }
                if(conteo2 == 0)
                {
                    pila.push(aux->vertA);
                }
                aux = aux->arisA;
            }
        }
    }
}

/**
 * @brief Recorre el grafo y calcula la ruta más corta
 * @param comienzo una referencia al vertice del comienzo
 * @param final una referencia al vertice del final
 */
void Graph::ProfPrimero(Vertice *comienzo, Vertice *final){
    Vertice *VerticeActual, *FinalActual;
    typedef pair<Vertice*, Vertice*> ParVertices;
    int conteo,conteo2,conteo3=0;
    int numerador = comienzo->arisV->num;
    Arista *aux;
    stack<Vertice*> pila;
    list<Vertice*> lista;
    stack <ParVertices> PilaPar;
    list<Vertice*>::iterator i;

    pila.push(comienzo);

    while (!pila.empty()){
        conteo=0;
        VerticeActual=pila.top();
        pila.pop();

        for(i=lista.begin();i!=lista.end();i++){
            if(VerticeActual==*i){
                conteo=1;
            }
        }
        if (conteo==0){
            if (VerticeActual==final){
                conteo3=1;
                FinalActual=final;
                while(!PilaPar.empty()){
                    cout<<FinalActual->nom<<"<-";
                    while (!PilaPar.empty()&& PilaPar.top().second != FinalActual){
                        PilaPar.pop();

                    }
                    if(!PilaPar.empty()){
                        FinalActual=PilaPar.top().first;
                    }
                }
                cout<<"   El tamano de tu tanque debe ser: "<<numerador<<endl;
                if (numerador <= tanque){
                    tanque = numerador;
                }
                break;
            }
            lista.push_back(VerticeActual);
            aux=VerticeActual->arisV;
            if(aux!=NULL){
                if (aux->num!=NULL){
                    if (numerador <= aux->num){
                        numerador = aux->num;
                    }
                }
            }
            while(aux!=NULL){
                conteo2=0;
                for(i=lista.begin(); i!=lista.end(); i++){
                    if(aux->vertA==*i){
                        conteo2=1;
                    }
                }
                if(conteo2==0){
                    pila.push(aux->vertA);
                    PilaPar.push(ParVertices(VerticeActual,aux->vertA));
                }
                aux=aux->arisA;
            }
        }
    }
    if(conteo3==0){
        cout <<"No hay ruta entre los vertices seleccionados!"<< endl;
    }
}

bool Comparar(pair <Vertice*, int> x, pair<Vertice*, int> y)
{
    return x.second < y.second;
}

/**
 * @brief Recorre el grafo y calcula la ruta de menor costo
 * @param comienzo una referencia al vertice del comienzo
 * @param final una referencia al vertice del final
 */
string Graph::PrimMejor(Vertice *comienzo, Vertice *final){

    int CostoActual, conteo, conteo2, CostoAnterior;
    string resultado_costo, resultado_trayecto,resultado_ordenado,pasos_algoritmo;
    Vertice *VerticeActual, *DestinoActual;
    Arista *aux;
    typedef pair<Vertice*, int> VerticeCosto;
    typedef pair<Vertice*, Vertice*> VerticeVertice;
    list<VerticeCosto> ListaCostos;
    list<VerticeCosto> ListaOrdenada;
    stack<VerticeVertice> pila;
    list<VerticeCosto>::iterator i, j;

    ListaCostos.push_back(VerticeCosto(comienzo, 0));
    ListaOrdenada.push_back(VerticeCosto(comienzo,0));

    while(!ListaOrdenada.empty())
    {
        VerticeActual = ListaOrdenada.front().first;
        CostoActual = ListaOrdenada.front().second;
        ListaOrdenada.pop_front();

        if(VerticeActual == final)
        {
            //cout<<"Costo: "<<CostoActual<<endl;
            string converter(std::to_string(CostoActual));
            resultado_costo+=converter+"\n";
            conteo2 = 1;
            DestinoActual = final;

            while(!pila.empty())
            {
                //cout<<DestinoActual->nombre<<"<-";
                resultado_trayecto+=DestinoActual->nom+"<-";

                while(!pila.empty() && pila.top().second != DestinoActual)
                {
                    pila.pop();
                }

                if(!pila.empty())
                {
                    DestinoActual = pila.top().first;
                }
            }
            break;
        }

        aux = VerticeActual->arisV;
        while(aux != NULL)
        {
            conteo = 0;
            CostoAnterior = CostoActual;
            if (CostoActual < aux->num)
            {
                CostoActual = aux->num;
            }
            //CostoActual = CostoActual + aux->peso;
            for(i=ListaCostos.begin(); i!=ListaCostos.end(); i++)
            {
                if(aux->vertA == i->first)
                {
                    conteo = 1;
                    if(CostoActual < i->second)
                    {
                        (*i).second = CostoActual;

                        for(j=ListaOrdenada.begin(); j!=ListaOrdenada.end(); j++)
                        {
                            if(j->first == aux->vertA)
                            {
                                (*j).second = CostoActual;
                            }
                        }
                        ListaOrdenada.sort(Comparar);
                        pila.push(VerticeVertice(VerticeActual, aux->vertA));
                        CostoActual = CostoAnterior;
                        pasos_algoritmo+=VerticeActual->nom+"->";
                        pasos_algoritmo+=aux->vertA->nom+"\n";
                    }
                }
            }
            if(conteo == 0)
            {
                ListaCostos.push_back(VerticeCosto(aux->vertA, CostoActual));
                ListaOrdenada.push_back(VerticeCosto(aux->vertA, CostoActual));
                ListaOrdenada.sort(Comparar);
                pila.push(VerticeVertice(VerticeActual, aux->vertA));
                pasos_algoritmo+=VerticeActual->nom+"->";
                pasos_algoritmo+=aux->vertA->nom+"\n";
                CostoActual = CostoAnterior;

            }

            aux = aux->arisA;
        }
    }
    if(conteo2 == 0)
    {
        cout<<"No hay una ruta entre estos vertices"<<endl;
    }
    resultado_ordenado="El camino a seguir es: "+resultado_trayecto+"\n"+
            "El tanque neceasrio para el recorrido es: "+resultado_costo+"\n"+"\n"
            +"Los pasos que realizo el algoritmo son: \n"+pasos_algoritmo;
    return resultado_ordenado;
}
