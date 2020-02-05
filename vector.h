#include <stddef.h>

#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef void *(*t_data_alloc)(size_t size);
typedef void  (*t_data_free)(void* p_data);
typedef void  (*t_data_cpy)(void *p_data_dst, void *p_data_src);

struct struct_vector
{
	size_t size;
	size_t capacity;
	void** elements;
	t_data_alloc function_malloc;
	t_data_free function_free;
	t_data_cpy function_copy;
};

typedef struct struct_vector s_vector;
typedef s_vector * p_s_vector;

/**
 * Creer un vecteur de double initialisee a 0.0 avec
 * pour longueur l entier donnee en argument.
 * @param  n Le nombre d elements dans le vecteur.
 * @return   Un vecteur initialise.
 */
p_s_vector vector_alloc(size_t n, t_data_alloc f_alloc, t_data_free f_free, t_data_cpy f_cpy);

/**
 * Libere la memoire utilise par le vecteur donnee en parametre.
 * @param p_vector Le vecteur a liberer.
 */
void vector_free(p_s_vector p_vector);

/**
 * Assigne la valeur donnee a l index selectionne dans la structure.
 * @param p_vector La structure ou assigner la valeur.
 * @param i        L index ou inserer la valeur.
 * @param v        La valeur a inserer.
 */
void vector_set(p_s_vector p_vector, size_t i, void* v);

/**
 * Renvoie la valeur donnée a l index passe en parametre.
 * @param  p_vector La structure ou recuperer la valeur.
 * @param  i        L index de la valeur a obtenir.
 * @return          Le double se trouvant dans le vecteur.
 */
void* get(p_s_vector p_vector, size_t i);

/**
 * [vector_get description]
 * @param p_vector [description]
 * @param i        [description]
 * @param p_data   [description]
 */
void vector_get(p_s_vector p_vector, size_t i, void * p_data);

/**
 * Insert une valeur a l index indique dans le vecteur.
 * @param p_vector La structure ou inserer la valeur.
 * @param i        L index ou inserer la valeur.
 * @param v        La valeur a inserer.
 */
void vector_insert(p_s_vector p_vector, size_t i, void* v);

/**
 * Supprime la valeur a l index indique dans le vecteur.
 * @param p_vector La structure ou supprimer la valeur.
 * @param i        L index a supprimer.
 */
void vector_erase(p_s_vector p_vector, size_t i);

/**
 * Fonction auxiliaire pour realloue la taille du vecteur au besoin.
 * @param p_vector     Le vecteur sur lequel travailler.
 * @param new_capacity La nouvelle capacite du vecteur.
 */
void _realloc_according_capacity(p_s_vector p_vector, size_t new_capacity);

/**
 * Ajoute une valeur a la fin du vecteur.
 * @param p_vector La structure ou inserer la valeur.
 * @param v        La valeur a inserer.
 */
void vector_push_back(p_s_vector p_vector, void* v);

/**
 * Supprime la derniere valeur du vecteur.
 * @param p_vector La structure ou supprimer la derniere valeur.
 */
void vector_pop_back(p_s_vector p_vector);

/**
 * Libere la memoire du tableau de valeur et remet ca taille a zero.
 * @param p_vector La structure ou supprimer le tableau.
 */
void vector_clear(p_s_vector p_vector);

/**
 * Verifie si le vecteur est vide.
 * @param  p_vector Le vecteur ou effectuer la verification.
 * @return          Zero si le vecteur est vide sinon 1.
 */
int vector_empty(p_s_vector p_vector);

/**
 * Renvoie la taille du vecteur.
 * @param  p_vector La structure dont on souhaite la taille
 * @return          Un entier qui est la taille du vecteur.
 */
size_t vector_size(p_s_vector p_vector);

#endif
