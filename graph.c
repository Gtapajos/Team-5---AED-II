#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define UNDEFINED -1

struct _graph {
    int vertexNumber, 
        edgeNumber, 
        vertexCounter, 
        initial, 
        *terminal, 
        *target, 
        *suffixLink,
        *length, 
        *position, 
        *shift; 
  };

typedef struct _graph *Graph; 
typedef int boolean;

Graph newGraph(int v, int e) {
   Graph g;

   g = (Graph)calloc(1, sizeof(struct _graph));
   if (g == NULL)
      return g;
   g->vertexNumber  = v;
   g->edgeNumber    = e;
   g->initial       = 0;
   g->vertexCounter = 1;
   return(g);
}


Graph newAutomaton(int v, int e) {
   Graph aut;

   aut = newGraph(v, e);
   aut->target = (int *)calloc(e, sizeof(int));
   if (aut->target == NULL)
      printf("\nerro newAutomaton\n");
      return aut;
   aut->terminal = (int *)calloc(v, sizeof(int));
   if (aut->terminal == NULL)
      printf("\nerro newAutomaton\n");
      return aut;
   return(aut);
}


Graph newSuffixAutomaton(int v, int e) {
   Graph aut;

   aut = newAutomaton(v, e);
   memset(aut->target, UNDEFINED, e*sizeof(int));
   aut->suffixLink = (int *)calloc(v, sizeof(int));
   if (aut->suffixLink == NULL)
      printf("\n newSuffixAutomaton");
   aut->length = (int *)calloc(v, sizeof(int));
   if (aut->length == NULL)
      printf("\n newSuffixAutomaton");
   aut->position = (int *)calloc(v, sizeof(int));
   if (aut->position == NULL)
      printf("\n erro newSuffixAutomaton");
   aut->shift = (int *)calloc(e, sizeof(int));
   if (aut->shift == NULL)
      printf("\n erro newSuffixAutomaton");
   return(aut);
}

Graph newTrie(int v, int e) {
   Graph aut;
 
   aut = newAutomaton(v, e);
   memset(aut->target, UNDEFINED, e*sizeof(int));
   aut->suffixLink = (int *)calloc(v, sizeof(int));
   if (aut->suffixLink == NULL)
      printf("\n erro newTrie");
   aut->length = (int *)calloc(v, sizeof(int));
   if (aut->length == NULL)
      printf("\n erro newTrie");
   aut->position = (int *)calloc(v, sizeof(int));
   if (aut->position == NULL)
      printf("\n erro newTrie");
   aut->shift = (int *)calloc(e, sizeof(int));
   if (aut->shift == NULL)
      printf("\n erro newTrie");
   return(aut);
}


int newVertex(Graph g) {
   if (g != NULL && g->vertexCounter <= g->vertexNumber)
      return(g->vertexCounter++);
   printf("\n erro newVertex");
}


int getInitial(Graph g) {
   if (g != NULL)
      return(g->initial);
   printf("\n erro getInitial");
}


boolean isTerminal(Graph g, int v) {
   if (g != NULL && g->terminal != NULL &&
       v < g->vertexNumber)
      return(g->terminal[v]);
   printf("\n erro isTerminal");
}


void setTerminal(Graph g, int v) {
   if (g != NULL && g->terminal != NULL &&
       v < g->vertexNumber)
      g->terminal[v] = 1;
   else
      printf("\n erro isTerminal");
}


int getTarget(Graph g, int v, unsigned char c) {
   if (g != NULL && g->target != NULL &&
       v < g->vertexNumber && v*c < g->edgeNumber)
      return(g->target[v*(g->edgeNumber/g->vertexNumber) +
                       c]);
   printf("\n erro getTarget");
}


void setTarget(Graph g, int v, unsigned char c, int t) {
   if (g != NULL && g->target != NULL &&
       v < g->vertexNumber &&
       v*c <= g->edgeNumber && t < g->vertexNumber)
      g->target[v*(g->edgeNumber/g->vertexNumber) + c] = t;
   else
      printf("\n erro setTarget");
}


int getSuffixLink(Graph g, int v) {
   if (g != NULL && g->suffixLink != NULL &&
       v < g->vertexNumber)
      return(g->suffixLink[v]);
   printf("\n erro getSuffixLink");
}


void setSuffixLink(Graph g, int v, int s) {
   if (g != NULL && g->suffixLink != NULL &&
       v < g->vertexNumber && s < g->vertexNumber)
      g->suffixLink[v] = s;
   else
      printf("\n erro setSuffixLink");
}


int getLength(Graph g, int v) {
   if (g != NULL && g->length != NULL &&
       v < g->vertexNumber)
      return(g->length[v]);
   printf("\n erro getLength");
}


void setLength(Graph g, int v, int ell) {
   if (g != NULL && g->length != NULL &&
       v < g->vertexNumber)
      g->length[v] = ell;
   else
      printf("\n erro setLength");
}


int getPosition(Graph g, int v) {
   if (g != NULL && g->position != NULL &&
       v < g->vertexNumber)
      return(g->position[v]);
   printf("\n erro getPosition");
}


void setPosition(Graph g, int v, int p) {
   if (g != NULL && g->position != NULL &&
       v < g->vertexNumber)
      g->position[v] = p;
   else
      printf("\n erro setPosition");
}

int getShift(Graph g, int v, unsigned char c) {
   if (g != NULL && g->shift != NULL &&
       v < g->vertexNumber && v*c < g->edgeNumber)
      return(g->shift[v*(g->edgeNumber/g->vertexNumber) +
             c]);
   printf("\n erro getShift");
}

void setShift(Graph g, int v, unsigned char c, int s) {
   if (g != NULL && g->shift != NULL &&
       v < g->vertexNumber && v*c <= g->edgeNumber)
      g->shift[v*(g->edgeNumber/g->vertexNumber) + c] = s;
   else
      printf("\n erro setShift");
}

void copyVertex(Graph g, int target, int source) {
   if (g != NULL && target < g->vertexNumber &&
       source < g->vertexNumber) {
      if (g->target != NULL)
         memcpy(g->target +
                target*(g->edgeNumber/g->vertexNumber),
                g->target +
                source*(g->edgeNumber/g->vertexNumber),
                (g->edgeNumber/g->vertexNumber)*
                sizeof(int));
      if (g->shift != NULL)
         memcpy(g->shift + target*(g->edgeNumber/g->vertexNumber), g->shift + source*(g->edgeNumber/g->vertexNumber),(g->edgeNumber/g->vertexNumber)*sizeof(int));
      if (g->terminal != NULL)
         g->terminal[target] = g->terminal[source];
      if (g->suffixLink != NULL)
         g->suffixLink[target] = g->suffixLink[source];
      if (g->length != NULL)
         g->length[target] = g->length[source];
      if (g->position != NULL)
         g->position[target] = g->position[source];
   }
   else
      printf("\n erro copyVertex");
}