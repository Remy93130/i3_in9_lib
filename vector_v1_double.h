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
 * Assigne la valeur donnee a l index selectionne dans la structure.
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

/**
 * Insert une valeur a l index indique dans le vecteur.
 * @param p_vector La structure ou inserer la valeur.
 * @param i        L index ou inserer la valeur.
 * @param v        La valeur a inserer.
 */
void vector_v1_double_insert(p_s_vector_v1_double p_vector, size_t i, double v);

/**
 * Supprime la valeur a l index indique dans le vecteur.
 * @param p_vector La structure ou supprimer la valeur.
 * @param i        L index a supprimer.
 */
void vector_v1_double_erase(p_s_vector_v1_double p_vector, size_t i);

/**
 * Ajoute une valeur a la fin du vecteur.
 * @param p_vector La structure ou inserer la valeur.
 * @param v        La valeur a inserer.
 */
void vector_v1_double_push_back(p_s_vector_v1_double p_vector, double v);

/**
 * Supprime la derniere valeur du vecteur.
 * @param p_vector La structure ou supprimer la derniere valeur.
 */
void vector_v1_double_pop_back(p_s_vector_v1_double p_vector);

/**
 * Libere la memoire du tableau de valeur et remet ca taille a zero.
 * @param p_vector La structure ou supprimer le tableau.
 */
void vector_v1_double_clear(p_s_vector_v1_double p_vector);

/**
 * Verifie si le vecteur est vide.
 * @param  p_vector Le vecteur ou effectuer la verification.
 * @return          Zero si le vecteur est vide sinon 1.
 */
int vector_v1_double_empty(p_s_vector_v1_double p_vector);

/**
 * Renvoie la taille du vecteur.
 * @param  p_vector La structure dont on souhaite la taille
 * @return          Un entier qui est la taille du vecteur.
 */
size_t vector_v1_double_size(p_s_vector_v1_double p_vector);

#endif
