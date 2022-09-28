#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

typedef struct {
    char nombre[30];
    int edad;
}stPersona;

typedef struct{
    stPersona dato;
    struct stNodoDoble *anterior;
    struct stNodoDoble *siguiente;
}stNodoDoble;

stNodoDoble *inicListaDoble();
stNodoDoble *crearNodoDoble(stPersona nodoNuevo);
stNodoDoble *agregarPpioDoble(stNodoDoble *lista, stNodoDoble *nuevoNodo);
stNodoDoble *agregarFinalDoble(stNodoDoble *lista, stNodoDoble *nuevoNodo);
stNodoDoble *buscarUltimoDoble(stNodoDoble *lista);
stNodoDoble *buscarUltimoDobleRecursivo(stNodoDoble *lista);
stNodoDoble *agregarEnOrdenDoble(stNodoDoble *lista, stNodoDoble *nuevoNodo);
void mostrarListaDoble(stNodoDoble *lista);
void mostrarNodoDoble(stPersona dato);
stNodoDoble *borrarPrimerNodoDoble(stNodoDoble *lista);


#endif // LISTADOBLE_H_INCLUDED
