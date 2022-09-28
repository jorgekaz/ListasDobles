#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDoble.h"

stNodoDoble *inicListaDoble(){
    return NULL;
}

stNodoDoble *crearNodoDoble(stPersona nodoNuevo){
    stNodoDoble *aux=(stNodoDoble*)malloc(sizeof(stNodoDoble));
    aux->dato=nodoNuevo;
    aux->anterior=NULL;
    aux->siguiente=NULL;
    return aux;
}

stNodoDoble *agregarPpioDoble(stNodoDoble *lista, stNodoDoble *nuevoNodo){
    nuevoNodo->siguiente=lista;
    if(lista!=NULL){
    lista->anterior=nuevoNodo;
    }
    return nuevoNodo;
}



stNodoDoble *agregarFinalDoble(stNodoDoble *lista, stNodoDoble *nuevoNodo){
    if(lista==NULL){
        lista=nuevoNodo;
    }else{
        stNodoDoble *aux=(stNodoDoble*)malloc(sizeof(stNodoDoble));
        aux=buscarUltimoDobleRecursivo(lista);
        aux->siguiente=nuevoNodo;
        nuevoNodo->anterior=aux;
    }
    return lista;
}

stNodoDoble *buscarUltimoDoble(stNodoDoble *lista){
    stNodoDoble *aux=(stNodoDoble*)malloc(sizeof(stNodoDoble));
    aux=lista;
    while(aux->siguiente!=NULL){
        aux=aux->siguiente;
    }
    return aux;
}

stNodoDoble *buscarUltimoDobleRecursivo(stNodoDoble *lista){
    stNodoDoble *aux=(stNodoDoble*)malloc(sizeof(stNodoDoble));
    if(lista==NULL){
        aux=NULL;
    }else{
    if(lista->siguiente==NULL){
        aux=lista;
    }else{
        aux=buscarUltimoDobleRecursivo(lista->siguiente);
    }
    }
    return aux;
}

stNodoDoble *agregarEnOrdenDoble(stNodoDoble *lista, stNodoDoble *nuevoNodo){
    if(lista==NULL){
        lista=nuevoNodo;
    }else{
        if(lista->dato.edad>nuevoNodo->dato.edad){
            agregarPpioDoble(lista,nuevoNodo);
        }else{
        stNodoDoble *seg=(stNodoDoble*)malloc(sizeof(stNodoDoble));
        stNodoDoble *ante=(stNodoDoble*)malloc(sizeof(stNodoDoble));
        while(seg->siguiente!=NULL&&nuevoNodo->dato.edad>seg->dato.edad){
            ante=seg;
            seg=seg->siguiente;
        }
        if(seg->siguiente==NULL){
            agregarFinalDoble(seg,nuevoNodo);
        }else{
            ante->siguiente=nuevoNodo;
            nuevoNodo->anterior=ante;
            nuevoNodo->siguiente=seg;
            seg->anterior=nuevoNodo;
        }
    }
    }
    return lista;
}

void mostrarListaDoble(stNodoDoble *lista){
    stNodoDoble *seg=lista;
    printf("4");
    while(seg!=NULL){
        printf("5");
        mostrarNodoDoble(seg->dato);
        seg=seg->siguiente;
    }
}

void mostrarNodoDoble(stPersona dato){
    printf("5");
    printf("Nombre: %s\n",dato.nombre);
    printf("Edad: %d\n",dato.edad);
    puts("*------------------------------------------------*");
}

stNodoDoble *borrarPrimerNodoDoble(stNodoDoble *lista){
    stNodoDoble *aux;
    aux=lista;
    lista=lista->siguiente;
    free(aux);
    return lista;
}

