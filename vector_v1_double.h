#include <stddef.h>

#ifndef __VECTOR_V1_DOUBLE_H__
#define __VECTOR_V1_DOUBLE_H__

struct struct_vector_v1_double
{
	size_t size;
	double* elements;
};

typedef struct struct_vector_v1_double s_vector_v1_double;
typedef s_vector_v1_double * p_s_vector_v1_double;

/**
 * Creer un vecteur de double initialisee a 0.0 avec
 * pour longueur l entier donnee en argument.
 * @param  n Le nombre d elements dans le vecteur.
 * @return   Un vecteur initialise.
 */
p_s_vector_v1_double vector_v1_double_alloc(size_t n);

/**
 * Libere la memoire utilise par le vecteur donnee en parametre.
 * @param p_vector Le vecteur a liberer.
 */
void vector_v1_double_free(p_s_vector_v1_double p_vector);

/**
 * Assigne la valeur donnée a l index selectionne dans la structure.
 * @param p_vector La structure ou assigner la valeur.
 * @param i        L index ou inserer la valeur.
 * @param v        La valeur a inserer.
 */
void vector_v1_double_set(p_s_vector_v1_double p_vector, size_t i, double v);

/**
 * Renvoie la valeur donnée a l index passe en parametre.
 * @param  p_vector La structure ou recuperer la valeur.
 * @param  i        L index de la valeur a obtenir.
 * @return          Le double se trouvant dans le vecteur.
 */
double get(p_s_vector_v1_double p_vector, size_t i);

void vector_v1_double_insert(p_s_vector_v1_double p_vector, size_t i, double v);

void vector_v1_double_erase(p_s_vector_v1_double p_vector, size_t i);

void vector_v1_double_push_back(p_s_vector_v1_double p_vector, double v);

void vector_v1_double_pop_back(p_s_vector_v1_double p_vector);

void vector_v1_double_clear(p_s_vector_v1_double p_vector);

int vector_v1_double_empty(p_s_vector_v1_double p_vector);

size_t vector_v1_double_size(p_s_vector_v1_double p_vector);

#endif