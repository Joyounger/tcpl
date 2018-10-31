
#define HASHSIZE 101
static struct nlist *hashtable[HASHSIZE]; /* pointer table */

struct nlist {			/* table entry */
	struct nlist *next;	/* next entry in chain */
	char *name;			/* defined name */
	char *defn;			/* replacement text */
}

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
	{
		hashval = *s + 31 * hashval;
	}

	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtable[hash(s)]; np != NULL; np = np->next)
	{
		if (strcmp(np->name, s) == 0)
		{
			return np;	/* found */
		}
	}

	return NULL;		/* not found */
}

char *strdup(char *);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL)	/* not found */
	{
		np = (struct nlist *)malloc(sizeof(struct nlist));
		if (np == NULL || (np->name = strdup(name)) == NULL)
		{
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else {	/* already there */
		free((void *)np->defn);		/* free previous defn */
	}

	if ((np->defn = strdup(defn)) == NULL) {
		return NULL;
	}

	return np;
}

int main(int argc, char const *argv[])
{

}


