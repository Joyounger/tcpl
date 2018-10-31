#define HASHSIZE 101
static struct nlist *hashtable[HASHSIZE]; /* pointer table */

struct nlist {          /* table entry */
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
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
            return np;  /* found */
        }
    }

    return NULL;        /* not found */
}

int undef(char *name, char *defn)
{
    unsigned hashval;
    struct nlist *prev, *np;

    prev = NULL;
    hashval = hash(name);

    for (np = hashtable[hashval]; np != NULL; np = np->next)
    {
        if (strcmp(name, np->name) == 0) {
            break;
        }
        prev = np;
    }

    if (np != NULL)
    {
        if (prev == NULL)
        {
            hashtable[hashval] = np->next;
        } else {
            prev->next = np->next;
        }

        free((void *)np->name);
        free((void *)np->defn);
        free((void *)np);
    }

}

